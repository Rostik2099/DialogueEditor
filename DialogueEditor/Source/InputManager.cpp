#include "InputManager.h"
#include "Editor.h"

Editor* editor;
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

InputManager::InputManager(GLFWwindow* window, Editor* editr)
{
	glfwSetKeyCallback(window, keyCallBack);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	editor = editr;
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

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		editor->GetDlgEditor()->OpenNodeSelector();
	}
	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS)
	{
		if (editor->GetDlgEditor()->HasMouseHover())
		{
			editor->GetDlgEditor()->DestroyNodeSelector();
		}
	}
}	