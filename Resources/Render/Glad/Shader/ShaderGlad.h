#pragma once
#define ShaderGlad_Class_H

#include<Debug/Debugger.h>
#include<Render/Shader/ShaderBase.h>

class ShaderGlad : public ShaderBase
{
private:
	uint Program;
public:
	ShaderGlad(const char* vertexShaderSource, const char* fragmentShaderSource);
	virtual void Active() override;
	~ShaderGlad();
};

