#pragma once
#include<iostream>
#include<vector>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

enum NodeType
{
	Start,
	End,
};

class DialogueEditor;
class NodesSelector
{
public:
	NodesSelector(DialogueEditor* editor);
	~NodesSelector();

	void Draw();

private:
	void ShowNodes();

private:
	DialogueEditor* editor;
	bool justCreated = true;
	std::vector<int> bebra;
	std::vector<std::pair<std::string, NodeType>> nodesList =
	{
		std::make_pair("Dialogue Start", Start),
		std::make_pair("Dialogue End", End),
	};
};

