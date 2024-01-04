#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <mesh.h>
#include <shader.h>
#include <camera.h>
#include <texture.h>

class Application {
public:
	Application(std::string WindowTitle, int width, int height);
	void Run();

private:
	bool openWindow();
	void setupInputs();

	void setupScene();
	bool update(float deltaTime);
	bool draw();

	void handleInput(float deltaTime);
	void mousePositionCallback(double xpos, double ypos);

private:
	std::string _applicationName {};
	int _width {};
	int _height {};
	GLFWwindow* _window { nullptr };

	float _moveSpeed{ 5.f };
	Camera _camera;
	std::vector<Mesh> _meshes;
	std::vector<Texture> _textures;
	Shader _shader;
	Shader _shaderLight;
	bool _running{ false };
	std::vector<Mesh> _marvel;
	std::vector<Mesh> _plane;
	std::vector<Mesh> _sugar;
	std::vector<Mesh> _papertowel;
	std::vector<Mesh> _baseball;
	std::vector<Mesh> _light;

	bool _firstMouse{ false };
	glm::vec2 _lastMousePosition {};
	glm::vec2 _cameraLookSpeed {};

	float _lastFrameTime{ -1.f };

	// lighting
	float _ambientStrength { 0.1f };
	glm::vec3 _ambientLightColor{ 1.f, 1.f, 1.f };
};