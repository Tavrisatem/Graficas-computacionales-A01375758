/*********************************************************

Materia: Gráficas Computacionales

Fecha: 2 de octubre de 2017

Autor: A01375758 Luis Fernando Espinosa Elizalde

*********************************************************/

#include "Mesh.h"
#include <iostream>

Mesh::Mesh()
{
	_vertexArrayObject = 0;
	_positionsVertexBufferObject = 0;
	_colorsVertexBufferObject = 0;
	_normalsVertexBufferObject = 0;
	_texCoordsVertexBufferObject = 0;
	_vertexCount = 0;
	_indicesBufferObject = 0;
	_indicesCount = 0;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &_vertexArrayObject);
	glDeleteBuffers(1, &_positionsVertexBufferObject);
	glDeleteBuffers(1, &_colorsVertexBufferObject);
	glDeleteBuffers(1, &_normalsVertexBufferObject);
	glDeleteBuffers(1, &_texCoordsVertexBufferObject);
	_vertexCount = 0;
}

void Mesh::CreateMesh(GLint vertexCount)
{
	_vertexCount = vertexCount;
	//Queremos generar 1 manager
	glGenVertexArrays(1, &_vertexArrayObject);
}

void Mesh::Draw(GLenum primitive)
{
	glBindVertexArray(_vertexArrayObject);
	if (_indicesCount > 0) {
		//Función de dibujado con índices
		glDrawElements(primitive, _indicesCount, GL_UNSIGNED_INT, nullptr);
	}
	else {
		//Función de dibujado sin índices
		glDrawArrays(primitive, 0, _vertexCount);
	}
	glBindVertexArray(0);
}

void Mesh::SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex)
{
	if (positions.size() > 0 && positions.size() == _vertexCount)
		SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec2) * positions.size(), positions.data(), usage, locationIndex, 2);
}

void Mesh::SetPositionAttribute(std::vector<glm::vec3> positions, GLenum usage, GLuint locationIndex)
{
	if (positions.size() > 0 && positions.size() == _vertexCount)
		SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec3) * positions.size(), positions.data(), usage, locationIndex, 3);

}


void Mesh::SetColorAttribute(std::vector<glm::vec3> color, GLenum usage, GLuint locationIndex)
{
	if (color.size() > 0 && color.size() == _vertexCount)
		SetAttributeData(_colorsVertexBufferObject, sizeof(glm::vec3) * color.size(), color.data(), usage, locationIndex, 3);

}

void Mesh::SetColorAttribute(std::vector<glm::vec4> color, GLenum usage, GLuint locationIndex)
{
	if (color.size() > 0 && color.size() == _vertexCount)
		SetAttributeData(_colorsVertexBufferObject, sizeof(glm::vec4) * color.size(), color.data(), usage, locationIndex, 4);

}

void Mesh::SetNormalAttribute(std::vector<glm::vec3> normal, GLenum usage, GLuint locationIndex)
{
	if (normal.size() > 0 && normal.size() == _vertexCount)
		SetAttributeData(_normalsVertexBufferObject, sizeof(glm::vec3) * normal.size(), normal.data(), usage, locationIndex, 3);
}

void Mesh::SetIndices(std::vector<unsigned int> indices, GLenum usage)
{
	if (indices.size() == 0) {
		return;
	}
	_indicesCount = indices.size();
	if (_indicesBufferObject != 0) {
		_indicesBufferObject = 0;
	}
	//std::cout << _indicesCount<<"perro";
	glBindVertexArray(_vertexArrayObject);
	glGenBuffers(1, &_indicesBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indicesBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*_indicesCount, indices.data(), usage);
	glBindVertexArray(0);
}

void Mesh::SetTexCoordAttribute(std::vector<glm::vec2> texCoords, GLenum usage, GLuint locationIndex)
{
	if (texCoords.size() > 0 && texCoords.size() == _vertexCount)
		SetAttributeData(_normalsVertexBufferObject, sizeof(glm::vec3) * texCoords.size(), texCoords.data(), usage, locationIndex, 2);
}

void Mesh::SetAttributeData(GLuint & buffer, const GLsizeiptr size, const void* data, GLenum usage, GLuint locationIndex, const GLint components)
{
	if (buffer) {
		glDeleteBuffers(1, &buffer);
	}
	glBindVertexArray(_vertexArrayObject);
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	glEnableVertexAttribArray(locationIndex);
	glVertexAttribPointer(locationIndex, components, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
