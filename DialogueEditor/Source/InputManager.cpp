#include "InputManager.h"
#include "Editor.h"

Editor* editor;
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);

InputManager::InputManager(GLFWwindow* window, Editor* edit)
{
	glfwSetKeyCallback(window, keyCallBack);
	editor = edit;
}

void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_DELETE && action == GLFW_PRESS)
	{
		editor->GetDlgEditor()->DeleteNodes();
	}
	if (key == GLFW_KEY_C && action == GLFW_PRESS)
	{
		editor->GetDlgEditor()->OpenNodeSelector();
	}
}
