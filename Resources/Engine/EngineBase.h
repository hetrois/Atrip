#pragma once
#define EngineBase_Class_H

#define Close false
#define Restart true


class EngineBase abstract
{
public:
	virtual bool Run() abstract;
	virtual ~EngineBase();
};