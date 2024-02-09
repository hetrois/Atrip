#define WinBase_Class_CPP

#include "WinBase.h"

std::vector<WinBase*> WinBase::Wins;

WinBase::WinBase()
{
	Wins.push_back(this);
	WinNumList = Wins.size();
}

void* WinBase::GetWindowPtr()
{
	return Window;
}

RenderBase* WinBase::GetRenderer()
{
	return render;
}

WinBase::~WinBase()
{
	Wins.erase(Wins.begin() + WinNumList, Wins.begin() + WinNumList);
}

WinBase* WinBase::GetWindow(void* WindowPtr)
{
	for(int i = 0; i < Wins.size(); i++)
	{
		if (Wins.at(i)->GetWindowPtr() == WindowPtr)
		{
			return Wins.at(i);
		}
	}
}
