#include "MeshGlad.h"
#include <Opengl/glad/glad.h>
#include <GLFW/glfw3.h>

MeshGlad::MeshGlad(std::vector<float>& vertices, std::vector<uint>& indices, uint stride) :
	VBO(0), VAO(0), IBO(0)
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)0);

	glEnableVertexAttribArray(0);
}

void MeshGlad::Render()
{
	glEnableVertexAttribArray(0);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
}

MeshGlad::~MeshGlad()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &IBO);
}
