#include "Editor.h"

Editor::Editor()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Editor::CreateWindow(std::string title)
{
	this->appWindow = glfwCreateWindow(1600, 900, title.c_str(), NULL, NULL);
	if (!appWindow)
	{
		std::cout << "Failed to open Window" << std::endl;
	}
	glfwMakeContextCurrent(appWindow);


	glViewport(0, 0, 1600, 900);
	glClearColor(0.07f, 0.13f, 0.17f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(appWindow);
}

bool Editor::AppWindowShouldClose()
{
	if (appWindow)
	{
		return glfwWindowShouldClose(appWindow);
	}
	else return false;
}

Editor::~Editor()
{
	glfwDestroyWindow(appWindow);
	glfwTerminate();
}
