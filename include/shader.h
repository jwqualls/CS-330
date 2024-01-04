#pragma once
#include <filesystem>
#include <string>
#include <GLAD/glad.h>
#include <glm/glm.hpp>

using Path = std::filesystem::path;


class Shader {
public:
	Shader() = default;
	Shader(const std::string& vertexSource, const std::string& fragmentSource);
	Shader(const Path& vertexPath,const Path& fragmentPath);

	// Reference ID of the Shader Program
	GLuint ID;

	void Bind();

	// Activates the Shader Program
	void Activate();
	// Deletes the Shader Program
	void Delete();

	void SetMat4(const std::string& uniformName, const glm::mat4& mat4);
	void SetInt(const std::string& uniformName, int value);

private:
	void load(const std::string& vertexSource, const std::string& fragmentSource);
	GLint getUniformLocation(const std::string& uniformName);

private:
	GLuint _shaderProgram;
};