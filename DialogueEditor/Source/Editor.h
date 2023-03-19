#pragma once
#include <string>
#include <iostream>

#include "imnodes.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "glfw3.h"

#include "Editor/DialogueEditor.h"
#include "InputManager.h"

class Editor
{
public:
	Editor();
	~Editor();

	void CreateWindow(std::string title);
	bool AppWindowShouldClose();
	void Draw();
	DialogueEditor* GetDlgEditor() { return this->editor; };

private:
	GLFWwindow* appWindow;
	DialogueEditor* editor;
	InputManager* inpMng;
};

