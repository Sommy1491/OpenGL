#pragma once

#pragma region BufferSpecification
namespace BUFFER
{
	enum TYPE
	{
		VERTEX,
		ELEMENT
	};
}
#pragma endregion

#pragma region ShaderSpecification
namespace SHADER
{
	enum TYPE
	{
		VERTEX,
		FRAGMENT
	};
}
#pragma endregion

#include <GL/glew.h>
#include <iostream>

#pragma region BufferObject
class BufferObject
{
public:
	BufferObject(BUFFER::TYPE type);
	~BufferObject();
	void BindBuffer();
	void BufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
	void DeleteBuffer();

private:
	BUFFER::TYPE type;
	GLuint bufferObject;
};
#pragma endregion


#pragma region VertexArrayObject
class VertexArrayObject
{
public:
	VertexArrayObject();
	~VertexArrayObject();
	void BindVertexArrayObject();
	void UnbindVertexArrayObject();
	void DeleteVertexArrayObject();

private:
	GLuint vertexArrayObject;
};
#pragma endregion


#pragma region VertexAttribute
class VertexAttribute
{
public:
	GLint GetAttributeLocation(GLuint shaderProgram, const GLchar* name);
	void VertexAttributePointer(GLint attribLocation);
	void enableVertexAttribArray(GLint attribLocation);
};
#pragma endregion


#pragma region Shader
class Shader
{
public:
	Shader(SHADER::TYPE type, const char* program);
	~Shader();

	GLuint getShader();

private:
	SHADER::TYPE type;
	GLuint shader;
	GLint shaderStatus;
	char shaderInfoLog[512];

	void CompileShader();
};
#pragma endregion


#pragma region ShaderProgram
class ShaderProgram
{
public:
	ShaderProgram(Shader* vertexShader, Shader* fragmentShader);
	~ShaderProgram();

	GLuint getProgram();

private:
	GLuint program;
};
#pragma endregion