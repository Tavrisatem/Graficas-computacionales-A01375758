/*********************************************************

Materia: Gr�ficas Computacionales

Fecha: 2 de octubre de 2017

Autor: A01375758 Luis Fernando Espinosa Elizalde

*********************************************************/

#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include "Shader.h"

class ShaderProgram {
	public:
		ShaderProgram();
		~ShaderProgram();
		void CreateProgram();
		void AttachShader(std::string path, GLenum type);
		void LinkProgram();
		void Activate();
		void Deactivate();
		void SetAttribute(GLuint locationIndex, std::string name);
		void SetUniformf(std::string name, float value);
		void SetUniformf(std::string name, float x, float y);
		void SetUniformf(std::string name, float x, float y, float z);
		void SetUniformf(std::string name, float x, float y, float z, float w);
		void SetUniformMatrix(std::string name, glm::mat4 matrix);
	private:
		GLuint _programHandle;
		std::vector<std::unique_ptr<Shader>> _attachedShaders;
		void DeleteAndDetachShaders();
		void DeleteProgram();
};