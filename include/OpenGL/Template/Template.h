#pragma once

#include "OpenGL/Object/Object.h"

#pragma region GameObject
template void GameObject::AddComponent<MeshFilter>();
template void GameObject::AddComponent<MeshRenderer>();

template MeshFilter* GameObject::GetComponent<MeshFilter>();
template MeshRenderer* GameObject::GetComponent<MeshRenderer>();
#pragma endregion