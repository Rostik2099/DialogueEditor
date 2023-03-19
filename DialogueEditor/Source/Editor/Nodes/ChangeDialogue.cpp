#include "ChangeDialogue.h"

ChangeDialogue::ChangeDialogue()
{
	memset(buffer, 0, 255);
}

void ChangeDialogue::Draw()
{
	Node::Draw();
	ImNodes::BeginNode(ID);

	ImNodes::BeginNodeTitleBar();
	ImGui::Text("Change Dialogue");
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
	ImGui::InputText("Dialogue Name", buffer, sizeof(buffer));

	ImNodes::EndNode();
}

void ChangeDialogue::SetParams(ImVec2 pos, int& ID)
{
	pins = 2;
	Node::SetParams(pos, ID);
	inputID = ID + 1;
	outputID = ID + 2;
}

ChangeDialogue::~ChangeDialogue() {}