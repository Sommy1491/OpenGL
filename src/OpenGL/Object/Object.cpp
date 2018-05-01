#include "OpenGL\Object\Object.h"

#pragma region GameObject
GameObject::GameObject()
{
	
}

GameObject::~GameObject()
{
	
}

template <class T>
void GameObject::AddComponent()
{
	if (typeid(T) == typeid(MeshFilter))
	{
		Component* component = new T(this);
		componentList.insert(std::make_pair(ComponentType::MESH_FILTER, component));
	}

	else if (typeid(T) == typeid(MeshRenderer))
	{
		Component* component = new T(this);
		componentList.insert(std::make_pair(ComponentType::MESH_RENDERER, component));
	}
}

template<class T>
T* GameObject::GetComponent()
{
	if (typeid(T) == typeid(MeshFilter))
	{
		T* meshFilter = dynamic_cast<T*>(componentList.find(ComponentType::MESH_FILTER)->second);
		return meshFilter;
	}

	else if (typeid(T) == typeid(MeshRenderer))
	{
		T* meshRenderer = dynamic_cast<T*>(componentList.find(ComponentType::MESH_RENDERER)->second);
		return meshRenderer;
	}

	return nullptr;
}

#include "OpenGL/Template/Template.h"

void GameObject::Update()
{
	for (std::map<ComponentType, Component*>::iterator it = componentList.begin(); it != componentList.end(); it++)
	{
		it->second->Update();	
	}
}
#pragma endregion
