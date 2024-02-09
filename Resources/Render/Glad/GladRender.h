#pragma once
#define GladRender_Class_H


#include "../RenderBase.h"
#include <Render/Mesh/Glad/GladMesh.h>
class GladRender :
    public RenderBase
{
private:
    GladMesh* Meshs;

public:
    GladRender();
    virtual void ResizeViewport(int x, int y) override;
    virtual void Draw() override;
    virtual void AddMesh(MeshData& mesh) override;
    virtual void AddShader(const char* VertexShaderCode, const char* FragmentShaderCode) override;
    ~GladRender();
};

