#pragma once
#define MeshGlad_Class_H

#include<vector>
#include<Debug/Debugger.h>
#include<Render/Mesh/MeshBase.h>

class MeshGlad : public MeshBase
{
private:
	uint VBO, VAO, IBO;
public:
	MeshGlad(std::vector<float>& vertices, std::vector<uint>& indices, uint stride);
	virtual void Render() override;
	~MeshGlad();
};

