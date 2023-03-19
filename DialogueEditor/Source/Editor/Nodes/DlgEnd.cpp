#include "DlgEnd.h"
DlgEnd::DlgEnd() {}

void DlgEnd::Draw()
{
	Node::Draw();
	ImNodes::BeginNode(ID);

	ImNodes::BeginNodeTitleBar();
	ImGui::Text("End");
	ImNodes::EndNodeTitleBar();

	ImNodes::BeginInputAttribute(inputID);
	ImGui::Text("Input");
	ImNodes::EndInputAttribute();

	ImNodes::EndNode();
}

void DlgEnd::SetParams(ImVec2 pos, int& ID)
{
	pins = 1;
	Node::SetParams(pos, ID);
	inputID = ID + 1;
	outputID = ID + 2;
}

DlgEnd::~DlgEnd() {}