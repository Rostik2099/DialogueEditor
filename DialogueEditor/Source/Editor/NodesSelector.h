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
	GiveQst,
	GiveItm,
	NPCAnsw,
	DlgChange,
	GiveMny,
};

class DialogueEditor;
class NodesSelector
{
public:
	NodesSelector(DialogueEditor* editor, ImVec2 dropPos, int dropID);
	~NodesSelector();

	void Draw();
	ImVec2 GetDropPos() { return this->dropPos; };

private:
	void ShowNodes();

private:
	DialogueEditor* editor;
	bool justCreated = true;
	ImVec2 dropPos;
	int dropID = -1;
	std::vector<int> bebra;
	std::vector<std::pair<std::string, NodeType>> nodesList =
	{
		std::make_pair("Dialogue Start", Start),
		std::make_pair("Dialogue End", End),
		std::make_pair("Progress Quest", ProgrQst),
		std::make_pair("Give New Quest", GiveQst),
		std::make_pair("Give Item", GiveItm),
		std::make_pair("NPC Answer", NPCAnsw),
		std::make_pair("Change Dialogue", DlgChange),
		std::make_pair("Give Money", GiveMny),
	};
};
