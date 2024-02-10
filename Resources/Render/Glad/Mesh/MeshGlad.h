#pragma once
#define MeshGlad_Class_H

#include<Render/Mesh/MeshBase.h>
#include<Debug/Debugger.h>

class MeshGlad : public MeshBase
{
private:
	uint VBO, VAO, IBO;
public:
	MeshGlad(float vertices[], uint indices[], uint stride);
	virtual void Render() override;
	~MeshGlad();
};

