#pragma once
#define ShaderBase_Class_H

class ShaderBase
{
protected:
	unsigned int Program;
	unsigned int Vertex;
	unsigned int Fragment;
public:
	virtual void Use() abstract;
};

