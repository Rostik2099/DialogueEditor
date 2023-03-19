#include "DlgEnd.h"
DlgEnd::DlgEnd() {}

void DlgEnd::Draw(int& nodeID)
{
	ImNodes::BeginNode(nodeID);
	ImNodes::BeginNodeTitleBar();
	ImGui::Text("End");
	ImNodes::EndNodeTitleBar();
	nodeID++;
	ImNodes::BeginInputAttribute(nodeID);
	ImGui::Text("Input");
	ImNodes::EndInputAttribute();
	ImNodes::EndNode();
}

DlgEnd::~DlgEnd() {}