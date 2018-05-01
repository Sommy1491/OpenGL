#include "OpenGL\Math\Math.h"

#pragma region Vector2 Class
Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vector2::getX()
{
	return this->x;
}

float Vector2::getY()
{
	return this->y;
}
#pragma endregion


#pragma region Vector3 Class
Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector3::getX()
{
	return this->x;
}

float Vector3::getY()
{
	return this->y;
}

float Vector3::getZ()
{
	return this->z;
}
#pragma endregion


