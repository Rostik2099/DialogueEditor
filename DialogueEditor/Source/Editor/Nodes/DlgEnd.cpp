#include "DlgEnd.h"
#include <iostream>
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

void DlgEnd::SetParams(ImVec2 pos, int& newID)
{
	pins = 1;
	Node::SetParams(pos, newID);
	inputID = ID + 1;
}

DlgEnd::~DlgEnd() {}