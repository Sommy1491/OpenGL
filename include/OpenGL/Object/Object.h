#pragma once

#include <iostream>
#include <map>
#include "OpenGL/Component/Component.h"

#pragma region GameObject
class Component;
class GameObject
{
public:
	GameObject();
	~GameObject();

	template <class T>
	void AddComponent();

	template <class T>	
	T* GetComponent();
	void Update();

private:
	std::map<ComponentType, Component*> componentList;
	
};
#pragma endregion