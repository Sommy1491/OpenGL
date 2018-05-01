#pragma once

#pragma region Vector2
class Vector2
{
public:
	Vector2(float x, float y);
	float getX();
	float getY();
private:
	float x, y;
};
#pragma endregion


#pragma region Vector3
class Vector3
{
public:
	Vector3(float x, float y, float z);
	float getX();
	float getY();
	float getZ();

private:
	float x, y, z;
};
#pragma endregion