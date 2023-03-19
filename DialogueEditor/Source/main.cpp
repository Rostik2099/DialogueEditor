#include <iostream>
#include "Editor.h"

int main()
{
	Editor Editor;
	Editor.CreateWindow("Cotico Dialogue");

	while (!Editor.AppWindowShouldClose())
	{
		Editor.Draw();
		glfwPollEvents();
	}
	
	return 0;
}