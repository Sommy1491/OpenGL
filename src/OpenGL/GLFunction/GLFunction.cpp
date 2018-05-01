#include "OpenGL\GLFunction\GLFunction.h"


#pragma region BufferObject Class
BufferObject::BufferObject(BUFFER::TYPE type)
{
	this->type = type;
    glGenBuffers(1, &bufferObject);
}

BufferObject::~BufferObject()
{
	DeleteBuffer();
}

void BufferObject::BindBuffer()
{
	if (this->type == BUFFER::TYPE::VERTEX)
		glBindBuffer(GL_ARRAY_BUFFER, bufferObject);

	else if (this->type == BUFFER::TYPE::ELEMENT)
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferObject);
}

void BufferObject::BufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage)
{
	glBufferData(target, size, data, usage);
}

void BufferObject::DeleteBuffer()
{
	glDeleteBuffers(1, &bufferObject);
}
#pragma endregion


#pragma region VertexArrayObject Class
VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &vertexArrayObject);
}

VertexArrayObject::~VertexArrayObject()
{
	DeleteVertexArrayObject();
}

void VertexArrayObject::BindVertexArrayObject()
{
	glBindVertexArray(vertexArrayObject);
}

void VertexArrayObject::UnbindVertexArrayObject()
{
	glBindVertexArray(0);
}

void VertexArrayObject::DeleteVertexArrayObject()
{
	glDeleteVertexArrays(1, &vertexArrayObject);
}
#pragma endregion


#pragma region VertexAttribute Class
GLint VertexAttribute::GetAttributeLocation(GLuint shaderProgram, const GLchar* name)
{
	return glGetAttribLocation(shaderProgram, name);
}

void VertexAttribute::VertexAttributePointer(GLint attribLocation)
{
	glVertexAttribPointer(attribLocation, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

void VertexAttribute::enableVertexAttribArray(GLint attribLocation)
{
	glEnableVertexAttribArray(attribLocation);
}
#pragma endregion


#pragma region Shader
Shader::Shader(SHADER::TYPE type, const char* program)
{
	this->type = type;

	if (type == SHADER::TYPE::VERTEX)
	{
		std::cout << "VertexShader Constructor" << std::endl;
		shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(shader, 1, &program, NULL);
		CompileShader();
	}

	else if (type == SHADER::TYPE::FRAGMENT)
	{
		std::cout << "FragmentShader Constructor" << std::endl;
		shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(shader, 1, &program, NULL);
		CompileShader();
	}
}

Shader::~Shader()
{
	if (type == SHADER::TYPE::VERTEX)
		std::cout << "VertexShader Destructor" << std::endl;

	else if (type == SHADER::TYPE::FRAGMENT)
		std::cout << "FragmentShader Destructor" << std::endl;
}

void Shader::CompileShader()
{
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &shaderStatus);

	if (type == SHADER::TYPE::VERTEX)
	{
		if (shaderStatus == GL_TRUE)
			std::cout << "Vertex Shader Compile Succesfully" << std::endl;

		else {
			glGetShaderInfoLog(shader, 512, NULL, shaderInfoLog);
			std::cout << shaderInfoLog << std::endl;
		}
	}

	if (type == SHADER::TYPE::FRAGMENT)
	{
		if (shaderStatus == GL_TRUE)
			std::cout << "Fragment Shader Compile Succesfully" << std::endl;

		else {
			glGetShaderInfoLog(shader, 512, NULL, shaderInfoLog);
			std::cout << shaderInfoLog << std::endl;
		}
	}
}

GLuint Shader::getShader()
{
	return this->shader;
}
#pragma endregion


#pragma region ShaderProgram
ShaderProgram::ShaderProgram(Shader * vertexShader, Shader * fragmentShader)
{
	std::cout << "ShaderProgram Constructor" << std::endl;
	program = glCreateProgram();
	glAttachShader(program, vertexShader->getShader());
	glAttachShader(program, fragmentShader->getShader());

	glLinkProgram(program);

	delete(vertexShader);
	delete(fragmentShader);
}

ShaderProgram::~ShaderProgram()
{
	std::cout << "ShaderProgram Destructor" << std::endl;
}
GLuint ShaderProgram::getProgram()
{
	return this->program;
}
#pragma endregion


