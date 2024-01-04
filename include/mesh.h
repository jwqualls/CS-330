#pragma once
#include <vector>
#include <types.h>
#include <glad/glad.h>

class Mesh {
public:
	Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
	Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices, const glm::vec3& color);

	void Draw();
	void DrawPolygon();
	void DrawPlane();

	glm::mat4 Transform{ 1.f };

private:


	uint32_t _elementCount{ 0 };
	GLuint VBO{};
	GLuint VBO2{};
	GLuint VBO3{};
	GLuint VBO4{};
	GLuint VAO{};
	GLuint VAO2{};
	GLuint VAO3{};
	GLuint VAO4{};
	GLuint _shaderProgram{};
	GLuint EBO{};
};