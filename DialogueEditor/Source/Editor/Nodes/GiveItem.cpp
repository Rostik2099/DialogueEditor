#include "GiveItem.h"

GiveItem::GiveItem() 
{
	memset(idBuffer, 0, 255);
	memset(quantBuffer, 0, 255);
	pins = 2;
}

void GiveItem::Draw()
{
	Node::Draw();
	ImNodes::BeginNode(ID);

	ImNodes::BeginNodeTitleBar();
	ImGui::Text("Give Item");
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
	ImGui::InputText("Item ID", idBuffer, sizeof(idBuffer));

	ImGui::SetNextItemWidth(100.f);
	ImGui::InputText("Quantity", quantBuffer, sizeof(quantBuffer));

	ImNodes::EndNode();
}

GiveItem::~GiveItem() {}
