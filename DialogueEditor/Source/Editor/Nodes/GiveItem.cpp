#include "GiveItem.h"

GiveItem::GiveItem() 
{
	memset(idBuffer, 0, 255);
	memset(quantBuffer, 0, 255);
}

void GiveItem::Draw()
{
	Node::Draw();
	ImNodes::BeginNode(ID);

	ImNodes::BeginNodeTitleBar();
	ImGui::Text("Give Item");
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
	ImGui::InputText("Item ID", ("u8%s", idBuffer), sizeof(idBuffer));

	ImGui::SetNextItemWidth(100.f);
	ImGui::InputText("Quantity", quantBuffer, sizeof(quantBuffer));

	ImNodes::EndNode();
}

void GiveItem::SetParams(ImVec2 pos, int& newID)
{
	pins = 2;
	Node::SetParams(pos, newID);
	inputID = ID + 1;
	outputID = ID + 2;
}

GiveItem::~GiveItem() {}
