#define GladRender_Class_CPP

#include "GladRender.h"
#include <Debug/Debugger.h>
#include <Opengl/glad/glad.h>
#include <Render/Shader/Glad/GladShader.h>
#include <Render/Mesh/Glad/GladMesh.h>


GladRender::GladRender()
{
	if (!gladLoadGL())
	{
		ErrorLog("Failed to init glad");
	}

	Log("Init successfully Glad Render");
}

void GladRender::AddMesh(MeshData& mesh)
{
	Meshs = new GladMesh(mesh);
	Log("Add Mesh to Renderer");
}

void GladRender::AddShader(const char* VertexShaderCode, const char* FragmentShaderCode)
{
	shader = new GladShader(VertexShaderCode, FragmentShaderCode);
	Log("Add Shader");
}

void GladRender::Draw()
{
	shader->Use();
	Meshs->bind();

	//Log("Draw");
}

GladRender::~GladRender()
{
	delete Meshs;
	delete shader;
	Log("clear render data");
}
