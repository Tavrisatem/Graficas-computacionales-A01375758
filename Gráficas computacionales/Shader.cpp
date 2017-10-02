/*********************************************************

Materia: Gráficas Computacionales

Fecha: 2 de octubre de 2017

Autor: A01375758 Luis Fernando Espinosa Elizalde

*********************************************************/

#include "Shader.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "InputFile.h"

Shader::Shader()
{
	_shaderHandle = 0;
}

Shader::~Shader()
{
	glDeleteShader(_shaderHandle);
}

void Shader::CreateShader(std::string path, GLenum type)
{
	if (_shaderHandle != 0) {
		glDeleteShader(_shaderHandle);
	}
	InputFile ifile;
	//VERTEX SHADER
	//Leemos el archivo Default.vert donde está el código del vertex shader.
	ifile.Read(path);
	//Obtenemos el código fuente y lo guardamos en un string.
	std::string vertexSource = ifile.GetContents();
	//Creamos un shader de tipo vertex guardamos su identificador en una variable.
	GLuint _shaderHandle = glCreateShader(type);
	//Obtener los datos en el formato correcto
	const GLchar *vertexSource_c = (const GLchar*)vertexSource.c_str();
	//Le estamos dando el código fuente a OpenGl para que se lo asigne al shader
	glShaderSource(_shaderHandle, 1, &vertexSource_c, nullptr);
	//Compilams el shader en busca de errores.
	//Vamos a asumir que no hay ningún error.
	glCompileShader(_shaderHandle);
}

GLuint Shader::GetHandle()
{
	return _shaderHandle;
}
