#pragma once
#define MeshBase_Class_H

#include "../RenderAPI.h"
#include "MeshData.h"

class MeshBase abstract
{
protected:
	unsigned int VBO, VAO, IBO;

	float* Vertices;
	unsigned int* Indices;

	virtual void Generate() abstract;
	virtual void Bind() abstract;
	virtual void Fill(MeshData& data) abstract;
	virtual void UnBind() abstract;

public:
	static MeshBase* GetMeshBasedOnAPI(RenderAPI api, MeshData& data);
	virtual void bind() abstract;
	virtual ~MeshBase();
};