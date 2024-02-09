#pragma once
#define MeshData_Struct_H

struct MeshData
{
	float* Vertex;
	unsigned int* Index;
	unsigned int stride;
};