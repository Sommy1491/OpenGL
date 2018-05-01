#include "OpenGL/Component/Component.h"

#pragma region Component
Component::Component(GameObject *gameObject)
{	
	this->gameObject = gameObject;
}

Component::~Component()
{
	
}
#pragma endregion


#pragma region MeshFilter
#pragma region Mesh
Mesh::Mesh()
{

}
Mesh::~Mesh()
{
	
}
#pragma endregion
#pragma region MeshFilter
MeshFilter::MeshFilter(GameObject *gameObject) : Component(gameObject)
{
	vbo = new BufferObject(BUFFER::TYPE::VERTEX);
	vbo->BindBuffer();

	vao = new VertexArrayObject();
	vao->BindVertexArrayObject();

	ebo = new BufferObject(BUFFER::TYPE::ELEMENT);
	ebo->BindBuffer();
}

MeshFilter::~MeshFilter()
{
	delete(mesh);
	delete(vbo);
	delete(vao);
	delete(ebo);
}

void MeshFilter::UpdateMesh()
{
	vbo->BufferData(GL_ARRAY_BUFFER, sizeof(Vector3) * mesh->vertices.size(), &mesh->vertices[0], GL_STATIC_DRAW);
	ebo->BufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * mesh->triangles.size(), &mesh->triangles[0], GL_STATIC_DRAW);
}

VertexArrayObject* MeshFilter::getVAO()
{
	return this->vao;
}

void MeshFilter::Update()
{
	
}
#pragma endregion
#pragma endregion 


#pragma region MeshRenderer
#pragma region MaterialClass
Material::Material()
{
	
}

Material::~Material()
{
	delete(shaderProgram);
}
#pragma endregion
#pragma region MeshRenderer
MeshRenderer::MeshRenderer(GameObject *gameObject) : Component(gameObject)
{
	meshFilter = this->gameObject->GetComponent<MeshFilter>();
}

MeshRenderer::~MeshRenderer()
{
	delete(vertexAttrib);
	delete(material);
}

void MeshRenderer::UpdateShader()
{
	vertexAttrib = new VertexAttribute();

	GLint attribPointer = vertexAttrib->GetAttributeLocation(material->shaderProgram->getProgram(), "position");
	vertexAttrib->VertexAttributePointer(attribPointer);
	vertexAttrib->enableVertexAttribArray(attribPointer);
}

void MeshRenderer::Update()
{
	meshFilter->getVAO()->BindVertexArrayObject();
	glUseProgram(material->shaderProgram->getProgram());
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	meshFilter->getVAO()->UnbindVertexArrayObject();
}
#pragma endregion 
#pragma endregion

