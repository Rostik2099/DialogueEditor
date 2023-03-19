#include "GiveMoney.h"

GiveMoney::GiveMoney()
{
	memset(buffer, 0, 255);
}

void GiveMoney::Draw()
{
	Node::Draw();
	ImNodes::BeginNode(ID);

	ImNodes::BeginNodeTitleBar();
	ImGui::Text("Give Money");
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
	ImGui::InputText("Ammount", buffer, sizeof(buffer));

	ImNodes::EndNode();
}

void GiveMoney::SetParams(ImVec2 pos, int& ID)
{
	pins = 2;
	Node::SetParams(pos, ID);
	inputID = ID + 1;
	outputID = ID + 2;
}

GiveMoney::~GiveMoney() {}
