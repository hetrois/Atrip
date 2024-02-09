#define Debugger_Class_CPP

#ifdef _DEBUG



#include "Debugger.h"
#include <iostream>
#include <Windows.h>

void Debugger::TestColor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (size_t i = 0; i < 16; i++)
	{
		SetConsoleTextAttribute(hConsole, i);

		std::cout << "test colors" << i << std::endl;
	}
}

void Debugger::ALog(const char* text)
{
	std::cout << "[message] " << text << std::endl;
}

void Debugger::AWarnLog(const char* text)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "[Warning] " << text << std::endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void Debugger::AFailLog(const char* text)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "[Fail] " << text << std::endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void Debugger::AErrorLog(const char* text)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "[Error] " << text << std::endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void Debugger::ALog(std::string& text)
{
	std::cout << "[message] " << text << std::endl;
}

void Debugger::AWarnLog(std::string& text)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "[Warning] " << text << std::endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void Debugger::AFailLog(std::string& text)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "[Fail] " << text << std::endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void Debugger::AErrorLog(std::string& text)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "[Error] " << text << std::endl;
	SetConsoleTextAttribute(hConsole, 7);
}
const std::string Debugger::AGetInput()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);

	std::cout << "[Input] ";

	SetConsoleTextAttribute(hConsole, 7);

	std::string input;
	std::cin >> input;
	return input;
}
const std::string Debugger::AGetInput(const char* text)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);

	std::cout << "[Input] " << text << ": ";

	SetConsoleTextAttribute(hConsole, 7);

	std::string input;
	std::cin >> input;
	return input;
}
const std::string Debugger::AGetInput(std::string& text)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);

	std::cout << "[Input] " << text << ": ";

	SetConsoleTextAttribute(hConsole, 7);

	std::string input;
	std::cin >> input;
	return input;
}
#endif // _DEBUG
