#pragma once
#define RenderBase_Class_H

#include "Mesh/MeshBase.h"
#include "Shader/ShaderBase.h"
#include<vector>


enum class RenderAPI
{
	None,
	GL220,
	GL330,
	GL440,
	GL460,
	Auto
};

class RenderBase abstract
{
protected:
	ShaderBase* Shader;
	MeshBase* Meshs;
public:
	static RenderBase* GetRenderBasedOnApi(RenderAPI api);
	virtual void ResizeViewport(int x, int y) abstract;
	virtual void AddMesh(float vertices[], uint indices[], uint stride) abstract;
	virtual void Draw() abstract;
};

