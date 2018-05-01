#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#pragma region GLWindow
class GLWindow
{
public:
	GLWindow();
	~GLWindow();
	GLFWwindow * window;

	bool createWindow(const int width, const int height, const char* title);
	void PollEvent();
	void SwapBuffer(GLFWwindow* window);
	bool windowShouldClose(GLFWwindow *window);

private:

	int initWindow();
	void configureWindow();
};
#pragma endregion

#pragma region GLContext
class GLContext
{
public:
	GLContext();
	~GLContext();

	void createContext(GLFWwindow *window);
	void deleteContext();
};
#pragma endregion

#pragma region GLExtensionWrangler
class GLEW {

public:
	GLEW();
	~GLEW();

	bool initGLEW();
};
#pragma endregion