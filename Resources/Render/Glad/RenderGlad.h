#pragma once
#define RenderGlad_Class_H

#include"../RenderBase.h"
#include <Debug/Debugger.h>

class RenderGlad : public RenderBase
{
private:

public:
	RenderGlad();
	virtual void ResizeViewport(int x, int y) override;
	virtual void AddMesh(std::vector<float>& vertices, std::vector<uint>& indices, uint stride) override;
	virtual void Draw() override;
	~RenderGlad();
};

