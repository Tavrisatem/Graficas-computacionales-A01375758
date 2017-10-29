/*********************************************************

Materia: Gr�ficas Computacionales

Fecha: 2 de octubre de 2017

Autor: A01375758 Luis Fernando Espinosa Elizalde

*********************************************************/

#include "ShaderProgram.h"

#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "Shader.h"

ShaderProgram::ShaderProgram()
{
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram()
{
	DeleteProgram();
}

void ShaderProgram::CreateProgram()
{
	//Creamos el identificador para el manager de los shader.
	_programHandle = glCreateProgram();
}

void ShaderProgram::AttachShader(std::string path, GLenum type)
{
	// Create and add the shaders to a list
	std::unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(path, type);
	_attachedShaders.push_back(std::move(shader));
}

void ShaderProgram::LinkProgram()
{
	for (int i=0; i < _attachedShaders.size(); i++) {
		glAttachShader(_programHandle, _attachedShaders[i]->GetHandle());
	}
	glLinkProgram(_programHandle);
	DeleteAndDetachShaders();
}

void ShaderProgram::Activate()
{
	glUseProgram(_programHandle);
}

void ShaderProgram::Deactivate()
{
	glUseProgram(0);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name)
{
	glBindAttribLocation(_programHandle, locationIndex, name.c_str());
}

void ShaderProgram::SetUniformf(std::string name, float value)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform1f(uniformLocation, value);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform2f(uniformLocation, x, y);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform3f(uniformLocation, x, y, z);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform4f(uniformLocation, x, y, z, w);
}

void ShaderProgram::SetUniformMatrix(std::string name, glm::mat4 matrix)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::SetUniformVector(std::string name, glm::vec3 vector)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform3fv(uniformLocation, 1, glm::value_ptr(vector));
}

void ShaderProgram::DeleteAndDetachShaders()
{
	for (int i=0; i < _attachedShaders.size(); i++) {
		glDetachShader(_programHandle, _attachedShaders[i].get()->GetHandle());
	}
	_attachedShaders.clear();
}

void ShaderProgram::DeleteProgram()
{
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);
}
