#define RenderGlad_Class_CPP


#include "RenderGlad.h"
#include "Mesh/MeshGlad.h"
#include "Shader/ShaderGlad.h"
#include <Opengl/glad/glad.h>
#include <GLFW/glfw3.h>
#include <Debug/Debugger.h>

const char* vertexShaderCode = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderCode = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";



RenderGlad::RenderGlad()
{
	gladLoadGL();

	Shader = new ShaderGlad(vertexShaderCode, fragmentShaderCode);
}

void RenderGlad::ResizeViewport(int x, int y)
{
	glViewport(0, 0, x, y);
	Log("Resize window");
}

void RenderGlad::AddMesh(float vertices[], uint indices[], uint stride)
{
	Meshs = new MeshGlad(vertices, indices, stride);
}

void RenderGlad::Draw()
{
	Shader->Active();
	Meshs->Render();
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        // There is an OpenGL error
        switch (error) {
        case GL_INVALID_ENUM:
            ErrorLog("OpenGL Error: GL_INVALID_ENUM");
            break;
        case GL_INVALID_VALUE:
            ErrorLog("OpenGL Error: GL_INVALID_VALUE");
            break;
        case GL_INVALID_OPERATION:
            ErrorLog("OpenGL Error: GL_INVALID_OPERATION");
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            ErrorLog("OpenGL Error: GL_INVALID_FRAMEBUFFER_OPERATION");
            break;
        case GL_OUT_OF_MEMORY:
            ErrorLog("OpenGL Error: GL_OUT_OF_MEMORY");
            break;
        default:
            ErrorLog("OpenGL Error: Unknown error");
            break;
        }
    }

}

RenderGlad::~RenderGlad()
{
	delete Meshs;
	delete Shader;
}
