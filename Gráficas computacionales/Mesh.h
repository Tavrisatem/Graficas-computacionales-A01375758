#pragma once

#include <GL/glew.h>
/*********************************************************

Materia: Gráficas Computacionales

Fecha: 16 de octubre de 2017

Autor: A01375758 Luis Fernando Espinosa Elizalde

*********************************************************/

#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>

class Mesh {
	public:
		Mesh();
		~Mesh();
		void CreateMesh(GLint vertexCount);
		void Draw(GLenum primitive);
		void SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex);
		void SetPositionAttribute(std::vector<glm::vec3> positions, GLenum usage, GLuint locationIndex);
		void SetColorAttribute(std::vector<glm::vec3> color, GLenum usage, GLuint locationIndex);
		void SetColorAttribute(std::vector<glm::vec4> color, GLenum usage, GLuint locationIndex);
		void SetIndices(std::vector<unsigned int> indices, GLenum usage);
	private:
		GLuint _vertexArrayObject;
		GLuint _positionsVertexBufferObject;
		GLuint _colorsVertexBufferObject;
		GLint _vertexCount;
		GLuint _indicesBufferObject;
		GLint _indicesCount;

		void SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void* data, GLenum usage, GLuint locationIndex, const GLint components);
};