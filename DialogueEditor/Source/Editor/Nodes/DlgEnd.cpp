#include "DlgEnd.h"
DlgEnd::DlgEnd()
{
	pins = 1;
}

void DlgEnd::Draw()
{
	Node::Draw();
	ImNodes::BeginNode(ID);

	ImNodes::BeginNodeTitleBar();
	ImGui::Text("End");
	ImNodes::EndNodeTitleBar();

	inputID = ID + 1;
	ImNodes::BeginInputAttribute(inputID);
	ImGui::Text("Input");
	ImNodes::EndInputAttribute();

	ImNodes::EndNode();
}

DlgEnd::~DlgEnd() {}