
#include <iostream>
#include "OpenGL/Window/Window.h"
#include "OpenGL/Object/Object.h"

int main()
{
	GLWindow glWindow;
	glWindow.createWindow(800, 600, "OpenGL");

	GLContext glContext;
	glContext.createContext(glWindow.window);

	GLEW glew;
	if (!glew.initGLEW()) {

		std::cout << "Failed to Initialize GLEW" << std::endl;
		return -1;
	}

	//............Object 1............//
	GameObject *gameObject = new GameObject();
	gameObject->AddComponent<MeshFilter>();
	gameObject->AddComponent<MeshRenderer>();

	std::vector<Vector3> vertices = {

		Vector3(0.5f, 0.5f, 0.0f),
		Vector3(-0.5f, 0.5f, 0.0f),
		Vector3(-0.5f, -0.5f, 0.0f),
		Vector3(0.5f, -0.5f, 0.0f)
	};

	std::vector<int> triangles = {

		0, 1, 2,
		0, 2, 3
	};

	Mesh *mesh = new Mesh();
	mesh->vertices = vertices;
	mesh->triangles = triangles;

	gameObject->GetComponent<MeshFilter>()->mesh = mesh;
	gameObject->GetComponent<MeshFilter>()->UpdateMesh();

	std::string vertexProgram = FileHandler::ReadFile("..//src//Resources//Shader//Vertex.vert");
	std::string fragmentProgram = FileHandler::ReadFile("..//src//Resources//Shader//Fragment.frag");

	Shader *vertexShader = new Shader(SHADER::TYPE::VERTEX, vertexProgram.c_str());
	Shader *fragmentShader = new Shader(SHADER::TYPE::FRAGMENT, fragmentProgram.c_str());

	ShaderProgram *shaderProgram = new ShaderProgram(vertexShader, fragmentShader);

	Material *material = new Material();
	material->shaderProgram = shaderProgram;
	
	gameObject->GetComponent<MeshRenderer>()->material = material;
	gameObject->GetComponent<MeshRenderer>()->UpdateShader();

	//...........Object 2....................//
	GameObject *gameObject1 = new GameObject();
	gameObject1->AddComponent<MeshFilter>();
	gameObject1->AddComponent<MeshRenderer>();

	std::vector<Vector3> vertices1 = {

		Vector3(1.0f, 1.0f, 0.0f),
		Vector3(-0.5f, 0.5f, 0.0f),
		Vector3(-0.5f, -0.5f, 0.0f),
	};

	std::vector<int> triangles1 = {

		0, 1, 2
	};

	Mesh *mesh1 = new Mesh();
	mesh1->vertices = vertices1;
	mesh1->triangles = triangles1;

	gameObject1->GetComponent<MeshFilter>()->mesh = mesh1;
	gameObject1->GetComponent<MeshFilter>()->UpdateMesh();

	gameObject1->GetComponent<MeshRenderer>()->material = material;
	gameObject1->GetComponent<MeshRenderer>()->UpdateShader();

	while (!glWindow.windowShouldClose(glWindow.window))
	{
		glClearColor(1.0, 1.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		gameObject->Update();
		gameObject1->Update();

		glWindow.SwapBuffer(glWindow.window);
		glWindow.PollEvent();
	}
}