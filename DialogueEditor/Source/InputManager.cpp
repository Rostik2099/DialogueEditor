#include "InputManager.h"
#include "Editor.h"

InputManager* self;
Editor* editor;
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

InputManager::InputManager(GLFWwindow* window, Editor* editr)
{
	editor = editr;
	self = this;
	glfwSetKeyCallback(window, keyCallBack);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
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

	if (key == GLFW_KEY_LEFT_CONTROL && action == GLFW_PRESS) self->controlPressed = true;
	if (key == GLFW_KEY_LEFT_CONTROL && action == GLFW_RELEASE) self->controlPressed = false;

	if (key == GLFW_KEY_O && action == GLFW_RELEASE && self->controlPressed)
	{
		std::string name;
		std::getline(std::cin, name);
		editor->GetSaveMngr()->OpenFile(name);
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