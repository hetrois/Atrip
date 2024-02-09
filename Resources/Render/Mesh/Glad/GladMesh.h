#pragma once
#include "../MeshBase.h"
class GladMesh :
    public MeshBase
{
private:
    virtual void Generate() override;
    virtual void Bind() override;
    virtual void Fill(MeshData& data) override;
    virtual void UnBind() override;
public:
    GladMesh(MeshData& data);
    virtual void bind() override;
    virtual ~GladMesh() override;
};

