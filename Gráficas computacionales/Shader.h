/********************************************************* 

Materia: Gráficas Computacionales

Fecha: 2 de octubre de 2017

Autor: A01375758 Luis Fernando Espinosa Elizalde

*********************************************************/

#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>

class Shader {
	public:
		Shader();
		~Shader();
		void CreateShader(std::string path, GLenum type);
		GLuint GetHandle();
	private:
		GLuint _shaderHandle;
};