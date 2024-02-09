#include"GladRender.h"
#include<Debug/Debugger.h>
#include<Opengl/glad/glad.h>
#include<GLFW/glfw3.h>


void GladRender::ResizeViewport(int x, int y)
{
	glViewport(0, 0, x, y);
	Log("Resize window");
}