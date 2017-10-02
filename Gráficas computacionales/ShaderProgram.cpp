/*********************************************************

Materia: Gráficas Computacionales

Fecha: 2 de octubre de 2017

Autor: A01375758 Luis Fernando Espinosa Elizalde

*********************************************************/

#include "ShaderProgram.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include "Shader.h"

ShaderProgram::ShaderProgram()
{
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram()
{
	ShaderProgram::DeleteProgram();
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
	for (int i; i < _attachedShaders.size(); i++) {
		glAttachShader(_programHandle, _attachedShaders[i]->GetHandle);
	}
	ShaderProgram::DeleteAndDetachShaders();
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
	glUseProgram(_programHandle);
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform1f(uniformLocation, value);
	glUseProgram(0);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y)
{
	glUseProgram(_programHandle);
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform2f(uniformLocation, x, y);
	glUseProgram(0);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z)
{
	glUseProgram(_programHandle);
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform3f(uniformLocation, x, y, z);
	glUseProgram(0);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w)
{
	glUseProgram(_programHandle);
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform4f(uniformLocation, x, y, z, w);
	glUseProgram(0);
}

void ShaderProgram::DeleteAndDetachShaders()
{
	for (int i; i < _attachedShaders.size(); i++) {
		glDetachShader(_programHandle, _attachedShaders[i].get()->GetHandle());
	}
}

void ShaderProgram::DeleteProgram()
{
	ShaderProgram::DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);
}
