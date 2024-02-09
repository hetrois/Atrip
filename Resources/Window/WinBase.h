#pragma once
#define WinBase_Class_H
#include<vector>
#include<Render/RenderBase.h>

class WinBase abstract
{
protected:
	void* Window;
	RenderBase* render;
	int WinNumList;
	static std::vector<WinBase*> Wins;

	float ColorR, ColorG, ColorB, ColorA;
public:
	WinBase();

	virtual bool ShouldClose() abstract;
	virtual void Response() abstract;
	virtual void Refresh() abstract;
	virtual void SetBgColor(float Red, float Green, float Blue, float Alpha) abstract;
	virtual void* GetWindowPtrWin32() abstract;
	void* GetWindowPtr();
	RenderBase* GetRenderer();

	virtual ~WinBase();

	static WinBase* GetWindow(void* WindowPtr);

	void(*ResizeWindowCallback)(int X, int Y);
};