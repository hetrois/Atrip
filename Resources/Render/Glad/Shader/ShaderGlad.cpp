#define ShaderGlad_Class_H

#include "ShaderGlad.h"
#include <Opengl/glad/glad.h>
#include <GLFW/glfw3.h>

ShaderGlad::ShaderGlad(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	Program = glCreateProgram();

	glAttachShader(Program, vertexShader);
	glAttachShader(Program, fragmentShader);

	glLinkProgram(Program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

void ShaderGlad::Active()
{
	glUseProgram(Program);
}

ShaderGlad::~ShaderGlad()
{
	glDeleteProgram(Program);
}
