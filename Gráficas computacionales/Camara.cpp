#include "Camara.h"
#include <glm/gtc/matrix_transform.hpp>

Camara::Camara()
{
	SetPerspective(1.0f, 1000.0f, 60.0f, 1.0f);
	_viewMatrix = glm::inverse(_transform.GetModelMatrix());
}

glm::mat4 Camara::GetViewProjection()
{
	return _projectionMatrix * _viewMatrix;
}

glm::mat4 Camara::GetViewMatrix()
{
	return _viewMatrix;
}

glm::mat4 Camara::GetProjectionMatrix()
{
	return _projectionMatrix;
}

glm::vec3 Camara::GetPosition()
{
	return _transform.GetPosition();
}

void Camara::SetPosition(float x, float y, float z)
{
	_transform.SetPosition(x, y, z);
	_viewMatrix = glm::inverse(_transform.GetModelMatrix());
}

void Camara::SetRotation(float x, float y, float z)
{
	_transform.SetRotation(x, y, z);
	_viewMatrix = glm::inverse(_transform.GetModelMatrix());
}

void Camara::MoveForward(float delta, bool world)
{
	_transform.MoveForward(delta, world);
	_viewMatrix = glm::inverse(_transform.GetModelMatrix());
}

void Camara::MoveUp(float delta, bool world)
{
	_transform.MoveUp(delta, world);
	_viewMatrix = glm::inverse(_transform.GetModelMatrix());
}

void Camara::MoveRight(float delta, bool world)
{
	_transform.MoveRight(delta, world);
	_viewMatrix = glm::inverse(_transform.GetModelMatrix());
}

void Camara::Yaw(float degrees)
{
	_transform.Rotate(0.0f, degrees, 0.0f, false);
	_viewMatrix = glm::inverse(_transform.GetModelMatrix());
}

void Camara::Roll(float degrees)
{
	_transform.Rotate(0.0f, 0.0f, degrees, false);
	_viewMatrix = glm::inverse(_transform.GetModelMatrix());
}

void Camara::Pitch(float degrees)
{
	_transform.Rotate(degrees, 0.0f, 0.0f, false);
	_viewMatrix = glm::inverse(_transform.GetModelMatrix());
}

void Camara::Rotate(float x, float y, float z, bool world)
{
	_transform.Rotate(x, y, z, world);
	_viewMatrix = glm::inverse(_transform.GetModelMatrix());
}

void Camara::SetPerspective(float nearPlane, float farPlane, float fieldOfView, float aspectRatio)
{
	_projectionMatrix = glm::perspective(glm::radians(fieldOfView), aspectRatio, nearPlane, farPlane);
}

void Camara::SetOrthographic(float size, float aspectRatio)
{
	float xSize = aspectRatio * size;
	_projectionMatrix = glm::ortho(-xSize, xSize, -size, size, -size, size);
}