#define WinGlfw_Class_CPP
#define GLFW_EXPOSE_NATIVE_WIN32

#include "WinGlfw.h"
#include "GlfwWinData.h"
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <Debug/Debugger.h>
#include <Render/Glad/GladRender.h>
#include<Window/Win32 addition/Win32.h>


void ErrorCallback(int error_code, const char* description)
{
	ErrorLog(description);
	glfwTerminate();
}

void ResizeCallback(GLFWwindow* window, int x, int y)
{
	GlfwWindowData* data = (GlfwWindowData*)glfwGetWindowUserPointer(window);

	data->render->ResizeViewport(x, y);
}
WinGlfw::WinGlfw(int x, int y, const char* text, RenderAPI API)
{
	Log("Create a Window");

	glfwSetErrorCallback(ErrorCallback);

	glfwInit();

#pragma region Set API
	switch (API)
	{
	case RenderAPI::None:
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		break;
	case RenderAPI::Gl220:
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
		break;
	case RenderAPI::Gl330:
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		break;
	case RenderAPI::Gl440:
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		break;
	case RenderAPI::Gl460:
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		break;
	default:
		ErrorLog("Strange API");
		break;
	}
#pragma endregion

	Window = glfwCreateWindow(x, y, text, NULL, NULL);

	if (Window == nullptr)
	{
		ErrorLog("Failed to create a window");
		glfwTerminate();
	}

	glfwMakeContextCurrent((GLFWwindow*)Window);

	render = RenderBase::GetRenderBasedOnApi(API);

	render->ResizeViewport(800, 600);

	WinGlfwData = new GlfwWindowData{0};
	((GlfwWindowData*)WinGlfwData)->render = render;
	((GlfwWindowData*)WinGlfwData)->Window = this;

	glfwSetWindowUserPointer((GLFWwindow*)Window, WinGlfwData);

	glfwSetFramebufferSizeCallback((GLFWwindow*)Window, ResizeCallback);
}

bool WinGlfw::ShouldClose()
{
	if (glfwWindowShouldClose((GLFWwindow*)Window))
	{
		auto x = Win32::MsgBox(GetWindowPtrWin32(), L"Atrip", L"Are you sure you want to close?", MsgBoxTypes::YesNo, MsgBoxIcon::Exclamation, 0);

		if (x == MsgBoxReturnButton::Yes)
		{
			return true;
		}
		else
		{
			glfwSetWindowShouldClose((GLFWwindow*)Window, false);
		}
	}
	return false;
}

void WinGlfw::Response()
{
	glfwPollEvents();
}

void WinGlfw::Refresh()
{
	glClearColor(ColorR, ColorG, ColorB, ColorA);
	glClear(GL_COLOR_BUFFER_BIT);
	render->Draw();
	glfwSwapBuffers((GLFWwindow*)Window);
}

void WinGlfw::SetBgColor(float Red, float Green, float Blue, float Alpha)
{
	ColorR = Red;
	ColorG = Green;
	ColorB = Blue;
	ColorA = Alpha;
}

void* WinGlfw::GetWindowPtrWin32()
{
	return glfwGetWin32Window((GLFWwindow*)Window);
}

WinGlfw::~WinGlfw()
{
	glfwDestroyWindow((GLFWwindow*)Window);
	glfwTerminate();
	Log("window deleted");
}
