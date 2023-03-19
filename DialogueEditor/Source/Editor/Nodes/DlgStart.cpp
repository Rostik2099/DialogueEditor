#include "DlgStart.h"
DlgStart::DlgStart() {}

void DlgStart::Draw(int& nodeID)
{
	Node::Draw(nodeID);
	ImNodes::BeginNode(nodeID);

	ImNodes::BeginNodeTitleBar();
	ImGui::Text("Start");
	ImNodes::EndNodeTitleBar();

	nodeID++;
	ImNodes::BeginOutputAttribute(nodeID);
	ImGui::Text("Output");
	ImNodes::EndOutputAttribute();

	ImNodes::EndNode();
}

DlgStart::~DlgStart() {}
