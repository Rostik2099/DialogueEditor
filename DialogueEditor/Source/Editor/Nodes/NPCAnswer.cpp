#include "NPCAnswer.h"

NPCAnswer::NPCAnswer() 
{
	memset(buffer, 0, 255);
}

void NPCAnswer::Draw()
{
	Node::Draw();
	ImNodes::BeginNode(ID);

	ImNodes::BeginNodeTitleBar();
	ImGui::Text("NPC Answer");
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
	ImGui::InputText("Text", buffer, sizeof(buffer));

	ImNodes::EndNode();
}

void NPCAnswer::SetParams(ImVec2 pos, int& ID)
{
	pins = 2;
	Node::SetParams(pos, ID);
	inputID = ID + 1;
	outputID = ID + 2;
}

NPCAnswer::~NPCAnswer() {}
