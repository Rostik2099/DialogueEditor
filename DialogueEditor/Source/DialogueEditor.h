#pragma once
#include <vector>

#include "imnodes.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Node.h"

class DialogueEditor
{
public:

	DialogueEditor();
	~DialogueEditor();

	void Draw();

private:
	std::vector<Node*> nodes;
	std::vector<std::pair<int, int>> links;
};

