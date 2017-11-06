#pragma once

#include <GL/freeglut.h>
#include <iostream>
#include <string>

class Texture2D {
public:
	Texture2D();
	~Texture2D();
	void LoadTexture(std::string path);
	void Bind();
	void Unbind();
private:
	GLuint _textureId;
};