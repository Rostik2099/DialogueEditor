#include "GiveMoney.h"

GiveMoney::GiveMoney()
{
	memset(buffer, 0, 255);
	pins = 2;
}

void GiveMoney::Draw()
{
	Node::Draw();
	ImNodes::BeginNode(ID);

	ImNodes::BeginNodeTitleBar();
	ImGui::Text("Give Money");
	ImNodes::EndNodeTitleBar();

	inputID = ID + 1;
	ImNodes::BeginInputAttribute(inputID);
	ImGui::Text("Input");
	ImGui::SetCursorPos(ImVec2(100.f, 30.f));
	ImNodes::EndInputAttribute();
	ImGui::SameLine();

	outputID = ID + 2;
	ImNodes::BeginOutputAttribute(outputID);
	ImGui::Text("Output");
	ImNodes::EndOutputAttribute();

	ImGui::SetNextItemWidth(100.f);
	ImGui::InputText("Ammount", buffer, sizeof(buffer));

	ImNodes::EndNode();
}

GiveMoney::~GiveMoney() {}
