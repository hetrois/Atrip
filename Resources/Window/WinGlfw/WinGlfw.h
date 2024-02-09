#pragma once
#define WinGlfw_Class_H
#include "../WinBase.h"
#include<Render/RenderAPI.h>
class WinGlfw :
    public WinBase
{
private:
    void* WinGlfwData;
public:
    WinGlfw(int x, int y, const char* text, RenderAPI API);
    virtual bool ShouldClose() override;
    virtual void Response() override;
    virtual void Refresh() override;
    virtual void SetBgColor(float Red, float Green, float Blue, float Alpha) override;
    virtual void* GetWindowPtrWin32() override;
    ~WinGlfw();
};