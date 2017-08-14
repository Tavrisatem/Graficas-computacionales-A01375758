#include "Rectangle.h"

Rectangle::Rectangle() {
	float _width = 1.0;
	float _height = 1.0;
}

Rectangle::Rectangle(float w, float h) {
	float _width = w;
	float _height = h;
}

float Rectangle::GetWidth()
{
	return _width;
}

float Rectangle::GetHeight()
{
	return _height;
}

float Rectangle::GetArea()
{
	return _width * _height;
}

float Rectangle::GetPerimeter()
{
	return 2 * _width + 2 * _height;
}

void Rectangle::SetWidth(float w)
{
	_width = w;
}

void Rectangle::SetHeight(float h)
{
	_height = h;
}
