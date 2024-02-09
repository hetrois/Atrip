#include "GladMesh.h"
#include <Opengl/glad/glad.h>
#include <Debug/Debugger.h>

void GladMesh::Generate()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);

	Log("Allocate mesh data");
}

void GladMesh::Bind()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	Log("bind Mesh data allocated");
}

void GladMesh::Fill(MeshData& data)
{
	Vertices = data.Vertex;
	Indices = data.Index;

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, data.stride, GL_FLOAT, GL_FALSE, data.stride * sizeof(float), (void*)0);

	Log("Mesh data Filled");
}

void GladMesh::UnBind()
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	Log("unbind Mesh data allocated");

}

GladMesh::GladMesh(MeshData& data)
{
	Generate();
	Bind();
	Fill(data);
	UnBind();
}

void GladMesh::bind()
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, IBO, GL_UNSIGNED_INT, 0);

	//Log("render mesh");
}

GladMesh::~GladMesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &IBO);

	Log("delete Mesh");
}
