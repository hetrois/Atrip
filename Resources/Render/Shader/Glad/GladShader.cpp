#include "GladShader.h"
#include<Opengl/glad/glad.h>
#include<Debug/Debugger.h>

GladShader::GladShader(const char* VertexCode, const char* FragmentCode)
{
	Vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(Vertex, 1, &VertexCode, 0);
	glCompileShader(Vertex);

	Log("create vertex shader");

	Fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(Fragment, 1, &FragmentCode, 0);
	glCompileShader(Fragment);

	Log("create fragment shader");

	Program = glCreateProgram();
	glAttachShader(Program, Vertex);
	glAttachShader(Program, Fragment);

	glLinkProgram(Program);

	Log("create shader program");

	glDeleteShader(Vertex);
	glDeleteShader(Fragment);

}

void GladShader::Use()
{
	glUseProgram(Program);

	//Log("Use shader");
}

GladShader::~GladShader()
{
	glDeleteProgram(Program);
	Log("delete program");
}
