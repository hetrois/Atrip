#pragma once
#define Atrip_Class_H
#include "../EngineBase.h"
#include <Window/WinBase.h>


class Atrip :
    public EngineBase
{
private:
    WinBase* Win;
public:
    Atrip();
    virtual bool Run() override;
    ~Atrip();
};

