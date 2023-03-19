#include "ProgressQuest.h"
#include <iostream>
ProgressQuest::ProgressQuest() 
{
	memset(buffer, 0 , 255);
}

void ProgressQuest::Draw(int& nodeID)
{
	Node::Draw(nodeID);
	ImNodes::BeginNode(nodeID);

	ImNodes::BeginNodeTitleBar();
	ImGui::Text("Progress Quest");
	ImNodes::EndNodeTitleBar();

	nodeID++;
	ImNodes::BeginInputAttribute(nodeID);
	ImGui::Text("Input");
	ImGui::SetCursorPos(ImVec2(100.f, 30.f));
	ImNodes::EndInputAttribute();
	ImGui::SameLine();

	nodeID++;
	ImNodes::BeginOutputAttribute(nodeID);
	ImGui::Text("Output");
	ImNodes::EndOutputAttribute();

	ImGui::SetNextItemWidth(100.f);
	ImGui::InputText("Quest ID", buffer, sizeof(buffer));

	ImNodes::EndNode();
}

ProgressQuest::~ProgressQuest() {}

