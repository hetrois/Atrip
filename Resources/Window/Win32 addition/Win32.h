#pragma once
#define Win32_Class_H

#include "MsgBoxTypes.h"
#include "MsgBoxIcon.h"
#include "MsgBoxReturnButton.h"

class Win32
{
public:
	static MsgBoxReturnButton MsgBox(void* WinOwner, const wchar_t* Title, const wchar_t* Text, MsgBoxTypes type, MsgBoxIcon icon, unsigned short DefaultButton);
};

