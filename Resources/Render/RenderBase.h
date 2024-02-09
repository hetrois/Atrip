#pragma once
#include"RenderAPI.h"
#include<vector>
#include<Render/Shader/ShaderBase.h>
class RenderBase abstract
{
protected:

	ShaderBase* shader;
public:
	virtual void ResizeViewport(int x, int y) abstract;
	virtual void Draw() abstract;
	virtual void AddMesh(MeshData& mesh) abstract;
	virtual void AddShader(const char* VertexShaderCode, const char* FragmentShaderCode) abstract;
	static RenderBase* GetRenderBasedOnApi(RenderAPI api);
};

