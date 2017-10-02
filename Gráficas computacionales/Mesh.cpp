/*********************************************************

Materia: Gráficas Computacionales

Fecha: 2 de octubre de 2017

Autor: A01375758 Luis Fernando Espinosa Elizalde

*********************************************************/

#include "Mesh.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "InputFile.h"

Mesh::Mesh()
{
	_vertexArrayObject = 0;
	_positionsVertexBufferObject = 0;
	_colorsVertexBufferObject = 0;
	_vertexCount = 0;
}

Mesh::~Mesh()
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Mesh::CreateMesh(GLint vertexCount)
{
	_vertexCount = vertexCount;
	GLuint vao;
	//Queremos generar 1 manager
	glGenVertexArrays(1, &vao);
	_vertexArrayObject = vao;
}

void Mesh::Draw(GLenum primitive)
{
	glBindVertexArray(_vertexArrayObject);
	//Función de dibujado sin índices
	glDrawArrays(primitive, 0, _vertexCount);
	glUseProgram(0);
}

void Mesh::SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex)
{
	if (positions.empty()) {
		return;
	}
	else if (positions.size() != _vertexCount) {
		return;
	}
	else {
		Mesh::SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec2) * positions.size(), positions.data(), usage, locationIndex, 2);
	}
}

void Mesh::SetPositionAttribute(std::vector<glm::vec3> positions, GLenum usage, GLuint locationIndex)
{
	if (positions.empty()) {
		return;
	}
	else if (positions.size() != _vertexCount) {
		return;
	}
	else {
		Mesh::SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec3) * positions.size(), positions.data(), usage, locationIndex, 3);
	}
}


void Mesh::SetColorAttribute(std::vector<glm::vec3> color, GLenum usage, GLuint locationIndex)
{
	if (color.empty()) {
		return;
	}
	else if (color.size() != _vertexCount) {
		return;
	}
	else {
		Mesh::SetAttributeData(_colorsVertexBufferObject, sizeof(glm::vec3) * color.size(), color.data(), usage, locationIndex, 3);
	}
}

void Mesh::SetColorAttribute(std::vector<glm::vec4> color, GLenum usage, GLuint locationIndex)
{
	if (color.empty()) {
		return;
	}
	else if (color.size() != _vertexCount) {
		return;
	}
	else {
		Mesh::SetAttributeData(_colorsVertexBufferObject, sizeof(glm::vec4) * color.size, color.data(), usage, locationIndex, 4);
	}
}

void Mesh::SetAttributeData(GLuint & buffer, const GLsizeiptr size, const void* data, GLenum usage, GLuint locationIndex, const GLint components)
{
	if (buffer != 0) {
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	GLuint colorsVBO;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	glEnableVertexAttribArray(locationIndex);
	glVertexAttribPointer(locationIndex, components, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
