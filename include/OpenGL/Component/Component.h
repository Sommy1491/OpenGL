#pragma once

#pragma region ComponentType
enum ComponentType
{
	MESH_FILTER,
	MESH_RENDERER
};
#pragma endregion

#pragma region Component

class GameObject;
class Component
{
public:
	Component(GameObject *gameObject);
	~Component();

	GameObject *gameObject;
	
	virtual void Update() = 0;
};
#pragma endregion

#include <iostream>
#include <vector>
#include "OpenGL/Math/Math.h"
#include "OpenGL/GLFunction/GLFunction.h"
#include "OpenGL/Helper/Helper.h"

#pragma region MeshFilter
#pragma region Mesh
class Mesh
{
public:
	Mesh();
	~Mesh();

	std::vector<Vector3> vertices;
	std::vector<int> triangles;
};
#pragma endregion
#pragma region MeshFilter
class MeshFilter : public Component
{
public:
	MeshFilter(GameObject *gameObject);
	~MeshFilter();
	void UpdateMesh();
	Mesh *mesh;

	VertexArrayObject* getVAO();

private:
	BufferObject *vbo;
	VertexArrayObject *vao;
	BufferObject *ebo;

	void Update();
};
#pragma endregion
#pragma endregion


#pragma region MeshRenderer
#pragma region Material
class Material
{
public:
	Material();
	~Material();

	ShaderProgram * shaderProgram;
};
#pragma endregion
#pragma region MeshRenderer
#include "OpenGL/Object/Object.h"
class MeshRenderer : public Component
{
public:
	MeshRenderer(GameObject *gameObject);
	~MeshRenderer();

	Material *material;
	void UpdateShader();

private:
	VertexAttribute *vertexAttrib;
	MeshFilter *meshFilter;
	void Update();
};
#pragma endregion
#pragma endregion
