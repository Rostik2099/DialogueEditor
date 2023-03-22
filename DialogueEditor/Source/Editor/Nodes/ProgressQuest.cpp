#include "ProgressQuest.h"

ProgressQuest::ProgressQuest() 
{
	memset(buffer, 0 , 255);
}

void ProgressQuest::Draw()
{
	Node::Draw();
	ImNodes::BeginNode(ID);

	ImNodes::BeginNodeTitleBar();
	ImGui::Text("Progress Quest");
	ImNodes::EndNodeTitleBar();

	ImNodes::BeginInputAttribute(inputID);
	ImGui::Text("Input");
	ImGui::SetCursorPos(ImVec2(100.f, 30.f));
	ImNodes::EndInputAttribute();
	ImGui::SameLine();

	ImNodes::BeginOutputAttribute(outputID);
	ImGui::Text("Output");
	ImNodes::EndOutputAttribute();

	ImGui::SetNextItemWidth(100.f);
	ImGui::InputText("Task ID", buffer, sizeof(buffer));

	ImNodes::EndNode();
}

void ProgressQuest::SetParams(ImVec2 pos, int& newID)
{
	pins = 2;
	Node::SetParams(pos, newID);
	inputID = ID + 1;
	outputID = ID + 2;
}

ProgressQuest::~ProgressQuest() {}

