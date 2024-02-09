#pragma once
#include "../ShaderBase.h"
class GladShader :
    public ShaderBase
{
public:
    GladShader(const char* VertexCode, const char* FragmentCode);
    virtual void Use() override;
    ~GladShader();
private:
};

