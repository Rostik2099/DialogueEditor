#pragma once
#include <string>
#include <iostream>

#include "glfw3.h"

class Editor
{
public:
	Editor();
	~Editor();

	void CreateWindow(std::string title);
	bool AppWindowShouldClose();

private:
	GLFWwindow* appWindow;
};

