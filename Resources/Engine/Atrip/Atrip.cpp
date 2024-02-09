#define Atrip_Class_CPP

#include "Atrip.h"
#include <Debug/Debugger.h>
#include <Window/WinGlfw/WinGlfw.h>
#include <Render/Mesh/Glad/GladMesh.h>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
"}\n\0";



float vertices[] =
{
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
};

unsigned int indices[] =
{
	0, 3, 5, // Lower left triangle
	3, 2, 4, // Lower right triangle
	5, 4, 1 // Upper triangle
};


Atrip::Atrip()
{
    Log("Engine start");
	Win = new WinGlfw(800, 600, "hello", RenderAPI::Gl330);
	Win->SetBgColor(0, 0, 1, 1);
}

bool Atrip::Run()
{
	MeshData data = { vertices, indices, 3 };
	Win->GetRenderer()->AddShader(vertexShaderSource, fragmentShaderSource);
	Win->GetRenderer()->AddMesh(data);

	while (!Win->ShouldClose())
	{
		Win->Refresh();
		Win->Response();
	}

	return Close;
}

Atrip::~Atrip()
{
	delete Win;
	Log("Engine Close");
}
