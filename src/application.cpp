#include <application.h>
#include <types.h>
#include <iostream>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stb_image.h>
#include <Cylinder.h>
#include <VAO.h>
#include <VBO.h>
#include <EBO.h>
#include <shaderClass.h>
 
Application::Application(std::string WindowTitle, int width, int height)
	: _applicationName{WindowTitle}, _width{ width }, _height{ height },
	_camera{ width, height, {0.f, 6.f, 10.f}, true}, // final scene location
	//_camera{ width, height, {0.f, 0.f, 2.f}, true }, // pyramid location camera
	_cameraLookSpeed {0.15f, 0.15f}
	{}

void Application::Run() {
	//Open window
	if (!openWindow()) {
		return;
	}

	setupInputs();

	_running = true;

	//setup scene
	setupScene();

	//Run application
	while (_running) {
		float currentTime = glfwGetTime();

		if (_lastFrameTime == -1.f) {
			_lastFrameTime = currentTime;
		}

		auto deltaTime = currentTime - _lastFrameTime;
		_lastFrameTime = currentTime;

		if (glfwWindowShouldClose(_window)) {
			_running = false;
			continue;
		}
		

		//Update
		update(deltaTime);

		//Draw
		draw();

	}

	glfwTerminate();
}

bool Application::openWindow() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//create window
	_window = glfwCreateWindow(800, 600, "Jaylen Qualls CS330", nullptr, nullptr);

	//check if window worked
	if (!_window) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(_window); 

	glfwSetWindowUserPointer(_window, (void*)this);

	glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height) {
		//Called when the window is resized
		glViewport(0, 0, width, height);

		auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
		app->_width = width;
		app->_height = height;

		app->_camera.SetSize(width, height);
	});

	//check for glad being initialized
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return false;
	}

	glEnable(GL_DEPTH_TEST);

	return true;
}

void Application::setupInputs() {
	glfwSetKeyCallback(_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
	    
		switch (key) {
			case GLFW_KEY_ESCAPE: {
				if (action == GLFW_PRESS) {
					app->_running = false;
				}
				break;
			}
			// press P to swap between perspective and orthographic perspective
			case GLFW_KEY_P: {
				if (action == GLFW_PRESS) {
					app->_camera.SetIsPerspective(!app->_camera.IsPerspective());
				}
			}
			default: {}
		}
	});

	//give mouse position when mouse moves on screen
	glfwSetCursorPosCallback(_window, [](GLFWwindow* window, double xpos, double ypos) {
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));

//		app->mousePositionCallback(xpos, ypos);
	});

	glfwSetScrollCallback(_window, [](GLFWwindow* window, double xOffset, double yOffset) {
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
		app->_camera.IncrementZoom(yOffset * 2);
	});

	glfwSetMouseButtonCallback(_window, [](GLFWwindow* window, int button, int action, int mods) {
		switch (button) {
			case GLFW_MOUSE_BUTTON_LEFT: {
				if (action == GLFW_PRESS) {
					std::cout << "Left mouse button pressed" << std::endl;
				}
				else {
					std::cout << "Left mouse button released" << std::endl;
				}
				break;
			}
			case GLFW_MOUSE_BUTTON_MIDDLE: {
				if (action == GLFW_PRESS) {
					std::cout << "Middle mouse button pressed" << std::endl;
				}
				else {
					std::cout << "Middle mouse button released" << std::endl;
				}
				break;
			}
			case GLFW_MOUSE_BUTTON_RIGHT: {
				if (action == GLFW_PRESS) {
					std::cout << "Right mouse button pressed" << std::endl;
				}
				else {
					std::cout << "Right mouse button released" << std::endl;
				}
				break;
			}
			default:
				std::cout << "Unhandled mouse button" << std::endl;
		}
	});
}

GLfloat lightVertices[] =
{ //     COORDINATES     //
	-0.1f, -0.1f,  0.1f,
	-0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f,  0.1f,
	-0.1f,  0.1f,  0.1f,
	-0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f,  0.1f
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

void Application::setupScene() {
	auto texturePath = std::filesystem::current_path() / "assets" / "textures";
	//_textures.emplace_back(texturePath / "marvel.jpg");
	//_textures.emplace_back(texturePath / "table.jpg");
	//_textures.emplace_back(texturePath / "CS330-2.png");
	_textures.emplace_back(texturePath / "Collage.png");
	_textures.emplace_back(texturePath / "wall.jpg");

	Path shaderPath = std::filesystem::current_path() / "assets" / "shaders";
	_shader = Shader(shaderPath / "basic_shader.vert", shaderPath / "basic_shader.frag");
	_shaderLight = Shader(shaderPath / "light.vert", shaderPath / "light.frag");

	VAO lightVAO;
	lightVAO.Bind();

	VBO lightVBO(lightVertices, sizeof(lightVertices));
	EBO lightEBO(lightIndices, sizeof(lightIndices));
	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	lightVAO.Unbind();
	lightVBO.Unbind();
	lightEBO.Unbind();

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(5.0f, 0.f, 0.f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 pyramidModel = glm::mat4(1.0f);
	pyramidModel = glm::translate(pyramidModel, pyramidPos);

	_shaderLight.Activate();
	glUniformMatrix4fv(glGetUniformLocation(_shaderLight.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(_shaderLight.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	_shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(_shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniform4f(glGetUniformLocation(_shader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(_shader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	auto& marvelBox = _meshes.emplace_back(Shapes::marvelVertices, Shapes::marvelElements);
	marvelBox.Transform = glm::translate(marvelBox.Transform, glm::vec3(0.f, 1.f, 0.0f));
	marvelBox.Transform = glm::rotate(marvelBox.Transform, glm::radians(90.f), glm::vec3(0.0f, 0.f, -1.f));	

	auto [cylinderVertices, cylinderElements] = Shapes::BuildCylinderSmooth(32, 1.f, 5.f);
	auto& sugarContainer = _meshes.emplace_back(cylinderVertices, cylinderElements);
	sugarContainer.Transform = glm::translate(sugarContainer.Transform, glm::vec3(-5.5f, 2.5f, -2.0f));
	sugarContainer.Transform = glm::rotate(sugarContainer.Transform, glm::radians(90.f), glm::vec3(1.0f, 0.f, 0.f));

	auto& plane = _meshes.emplace_back(Plane::planeVertices, Plane::planeElements);

	auto [sphereVertices, sphereElements] = Sphere::GenerateSphere(1.f, 50, 50);
	auto& baseball = _meshes.emplace_back(sphereVertices, sphereElements);
	baseball.Transform = glm::translate(baseball.Transform, glm::vec3(-5.5f, 1.f, 4.5f));

	auto [cylinderVerts, cylinderElems] = Shapes::BuildCylinderSmooth(32, 1.f, 5.f);
	auto& paperTowel = _meshes.emplace_back(cylinderVerts, cylinderElems);
	paperTowel.Transform = glm::translate(paperTowel.Transform, glm::vec3(2.5f, 2.5f, -7.f));
	paperTowel.Transform = glm::rotate(paperTowel.Transform, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f));

	//for pyramid assignment
	//auto& pyramid = _meshes.emplace_back(Pyramid::pyramidVertices, Pyramid::pyramidElements);

	auto& lightBox = _meshes.emplace_back(Light::lightVertices, Light::lightElements);
	lightBox.Transform = glm::translate(lightBox.Transform, glm::vec3(0.f, 10.f, 0.f));

}

bool Application::update(float deltaTime) {
	glfwPollEvents();

	handleInput(deltaTime);

	return false;
}

bool Application::draw()
{
	//set background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//camera
	glm::mat4 view = _camera.GetViewMatrix();

	//field of view
	//perspective is vanishing point theory where further away looks smaller
	//orthographic does not distort size from closer or farther away
	glm::mat4 projection = _camera.GetProjectionMatrix();
	glm::mat4 model = glm::mat4{ 1.f };

	//bind shader
	_shader.Bind();
	_shader.SetMat4("projection", projection);
	_shader.SetMat4("view", view);

	_shader.SetInt("tex0", 0);
	_shader.SetInt("tex1", 1);

	for (auto i = 0; i < _textures.size(); i++) {
		glActiveTexture(GL_TEXTURE0 + i);
		_textures[i].Bind();
	}

	//draw each triangle
	for (auto& mesh : _meshes) {
		_shader.SetMat4("model", mesh.Transform);
		//mesh.Transform = glm::rotate(mesh.Transform, glm::radians(0.01f), glm::vec3(0, 1, 0));
		mesh.Draw();
	}

	// Swap the back buffer with the front buffer
	glfwSwapBuffers(_window);
	// Take care of all GLFW events
	glfwPollEvents();

	return false;
}

void Application::handleInput(float deltaTime) {

	auto moveAmount = _moveSpeed * deltaTime;

	if (glfwGetKey(_window, GLFW_KEY_W)) {
		_camera.MoveCamera(Camera::MoveDirection::Forward, moveAmount);
	}
	if (glfwGetKey(_window, GLFW_KEY_A)) {
		_camera.MoveCamera(Camera::MoveDirection::Left, moveAmount);
	}
	if (glfwGetKey(_window, GLFW_KEY_S)) {
		_camera.MoveCamera(Camera::MoveDirection::Backward, moveAmount);
	}
	if (glfwGetKey(_window, GLFW_KEY_D)) {
		_camera.MoveCamera(Camera::MoveDirection::Right, moveAmount);
	}
	if (glfwGetKey(_window, GLFW_KEY_Q)) {
		_camera.MoveCamera(Camera::MoveDirection::Up, moveAmount);
	}
	if (glfwGetKey(_window, GLFW_KEY_E)) {
		_camera.MoveCamera(Camera::MoveDirection::Down, moveAmount);
	}
	
	double xpos, ypos;
	glfwGetCursorPos(_window, &xpos, &ypos);

	mousePositionCallback(xpos, ypos);
}

void Application::mousePositionCallback(double xpos, double ypos) {
	if (!_firstMouse) {
		_lastMousePosition.x = static_cast<float>(xpos);
		_lastMousePosition.y = static_cast<float>(ypos);
		_firstMouse = true;
	}

	glm::vec2 moveAmount{
		xpos - _lastMousePosition.x,
		_lastMousePosition.y - ypos,
	};

	_lastMousePosition.x = xpos;
	_lastMousePosition.y = ypos;

	_camera.RotateBy(moveAmount.x * _cameraLookSpeed.x, moveAmount.y * _cameraLookSpeed.y);
}