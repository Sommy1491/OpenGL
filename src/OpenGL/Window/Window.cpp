#include "OpenGL/Window/Window.h"

#pragma region GLWindow
GLWindow::GLWindow()
{
	if (initWindow() == GL_FALSE) {
		std::cout << "Failed to Initialize Window" << std::endl;
		return;
	}

	configureWindow();
}

GLWindow::~GLWindow()
{

}

int GLWindow::initWindow()
{
	return glfwInit();
}

void GLWindow::configureWindow()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

bool GLWindow::createWindow(const int width, const int height, const char* title)
{
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	if (window == NULL)
		return false;
	else
		return true;
}

void GLWindow::PollEvent()
{
	glfwPollEvents();
}

void GLWindow::SwapBuffer(GLFWwindow *window)
{
	glfwSwapBuffers(window);
}

bool GLWindow::windowShouldClose(GLFWwindow *window)
{
	return glfwWindowShouldClose(window);
}

#pragma endregion


#pragma region GLContext
GLContext::GLContext()
{

}

GLContext::~GLContext()
{

}

void GLContext::createContext(GLFWwindow *window)
{
	glfwMakeContextCurrent(window);
}

void GLContext::deleteContext()
{
	glfwMakeContextCurrent(NULL);
}
#pragma endregion


#pragma region GLExtensionWrangler
GLEW::GLEW()
{
}

GLEW::~GLEW()
{
}

bool GLEW::initGLEW()
{
	glewExperimental = GL_TRUE;
	
	if (glewInit() != GLEW_OK)
		return false;

	else
		return true;

}
#pragma endregion