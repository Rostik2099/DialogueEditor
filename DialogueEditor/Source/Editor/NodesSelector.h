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
	ProgrQst,
};

class DialogueEditor;
class NodesSelector
{
public:
	NodesSelector(DialogueEditor* editor, ImVec2 dropPos);
	~NodesSelector();

	void Draw();
	ImVec2 GetDropPos() { return this->dropPos; };

private:
	void ShowNodes();

private:
	DialogueEditor* editor;
	bool justCreated = true;
	ImVec2 dropPos;
	std::vector<int> bebra;
	std::vector<std::pair<std::string, NodeType>> nodesList =
	{
		std::make_pair("Dialogue Start", Start),
		std::make_pair("Dialogue End", End),
		std::make_pair("Progress Quest", ProgrQst),
	};
};

