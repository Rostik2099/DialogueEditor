#pragma once
#include "glfw3.h"

class Editor;
class InputManager
{
public:
	InputManager(GLFWwindow* window, Editor* editor);
	~InputManager() {};
};

