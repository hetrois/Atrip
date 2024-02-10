#pragma once
#define Debugger_Class_H

typedef unsigned int uint;

#ifdef _DEBUG

#include <string>

#define Log(x) Debugger::ALog(x)
#define WarnLog(x) Debugger::AWarnLog(x)
#define FailLog(x) Debugger::AFailLog(x)
#define ErrorLog(x) Debugger::AErrorLog(x); throw(x)
#define GetInput() Debugger::AGetInput()
#define GetInput(x) Debugger::AGetInput(x)

class Debugger abstract
{
public:
	static void TestColor();
	static void ALog(const char* text);
	static void AWarnLog(const char* text);
	static void AFailLog(const char* text);
	static void AErrorLog(const char* text);
	static void ALog(std::string& text);
	static void AWarnLog(std::string& text);
	static void AFailLog(std::string& text);
	static void AErrorLog(std::string& text);
	static const std::string AGetInput();
	static const std::string AGetInput(const char* text);
	static const std::string AGetInput(std::string& text);
};

#else

#define Log(x)
#define WarnLog(x)
#define FailLog(x)
#define ErrorLog(x) throw(x)

#endif // _DEBUG


