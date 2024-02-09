#define Win32_Class_CPP

#include "Win32.h"
#include <Windows.h>
#include <Debug/Debugger.h>

MsgBoxReturnButton Win32::MsgBox(void* WinOwner, const wchar_t* Title, const wchar_t* Text, MsgBoxTypes type, MsgBoxIcon icon, unsigned short DefaultButton)
{
	UINT uType;

	switch (type)
	{
	case MsgBoxTypes::Failed:
		uType = MB_RETRYCANCEL;
		break;
	case MsgBoxTypes::FailedContinue:
		uType = MB_CANCELTRYCONTINUE;
		break;
	case MsgBoxTypes::Help:
		uType = MB_HELP;
		break;
	case MsgBoxTypes::Ok:
		uType = MB_OK;
		break;
	case MsgBoxTypes::OkCancel:
		uType = MB_OKCANCEL;
		break;
	case MsgBoxTypes::YesNo:
		uType = MB_YESNO;
		break;
	case MsgBoxTypes::YesNoCancel:
		uType = MB_YESNOCANCEL;
		break;
	default:
		ErrorLog("Unkown MsgBox Type");
		break;
	}

	switch (icon)
	{
	case MsgBoxIcon::Exclamation:
		uType = uType | MB_ICONEXCLAMATION;
		break;
	case MsgBoxIcon::Warning:
		uType = uType | MB_ICONWARNING;
		break;
	case MsgBoxIcon::Information:
		uType = uType | MB_ICONINFORMATION;
		break;
	case MsgBoxIcon::Question:
		uType = uType | MB_ICONQUESTION;
		break;
	case MsgBoxIcon::Stop:
		uType = uType | MB_ICONSTOP;
		break;
	case MsgBoxIcon::Error:
		uType = uType | MB_ICONERROR;
		break;
	case MsgBoxIcon::Hand:
		uType = uType | MB_ICONHAND;
		break;
	default:
		break;
	}

	switch (DefaultButton)
	{
	case(0):
		uType = uType | MB_DEFBUTTON1;
		break;
	case(1):
		uType = uType | MB_DEFBUTTON2;
		break;
	case(2):
		uType = uType | MB_DEFBUTTON3;
		break;
	case(3):
		uType = uType | MB_DEFBUTTON4;
		break;
	default:
		ErrorLog("Unkown Default MsgBox Button");
		break;
	}

	int ret = MessageBoxEx((HWND)WinOwner, Text, Title, uType, 0);

	switch (ret)
	{
	case IDCANCEL:
		return MsgBoxReturnButton::Ok;
		break;
	case IDCONTINUE:
		return MsgBoxReturnButton::Continue;
		break;
	case IDIGNORE:
		return MsgBoxReturnButton::Ignore;
		break;
	case IDNO:
		return MsgBoxReturnButton::No;
		break;
	case IDOK:
		return MsgBoxReturnButton::Ok;
		break;
	case IDRETRY:
		return MsgBoxReturnButton::Retry;
		break;
	case IDTRYAGAIN:
		return MsgBoxReturnButton::Retry;
		break;
	case IDYES:
		return MsgBoxReturnButton::Yes;
		break;
	default:
		ErrorLog("Unkown MsgBox Button pressed");
		return MsgBoxReturnButton::Retry;
		break;
	}
}
