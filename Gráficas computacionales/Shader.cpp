/*********************************************************

Materia: Gr�ficas Computacionales

Fecha: 2 de octubre de 2017

Autor: A01375758 Luis Fernando Espinosa Elizalde

*********************************************************/

#include "Shader.h"

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
	InputFile ifile;
	//VERTEX SHADER
	//Leemos el archivo Default.vert donde est� el c�digo del vertex shader.
	if (ifile.Read(path)) std::cout << "File " << path << " opened successfully" << std::endl;
	//Obtenemos el c�digo fuente y lo guardamos en un string.
	std::string vertexSource = ifile.GetContents();
	if (_shaderHandle) {
		glDeleteShader(_shaderHandle);
	}
	//Creamos un shader de tipo vertex guardamos su identificador en una variable.
	_shaderHandle = glCreateShader(type);
	//Obtener los datos en el formato correcto
	const GLchar *vertexSource_c = (const GLchar*)vertexSource.c_str();
	//Le estamos dando el c�digo fuente a OpenGl para que se lo asigne al shader
	glShaderSource(_shaderHandle, 1, &vertexSource_c, nullptr);
	//Compilams el shader en busca de errores.
	//Vamos a asumir que no hay ning�n error.
	glCompileShader(_shaderHandle);
}

GLuint Shader::GetHandle()
{
	return _shaderHandle;
}
