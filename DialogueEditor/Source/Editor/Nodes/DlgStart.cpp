#include "DlgStart.h"

DlgStart::DlgStart() {}

void DlgStart::Draw()
{
	Node::Draw();
	ImNodes::BeginNode(ID);

	ImNodes::BeginNodeTitleBar();
	ImGui::Text("Start");
	ImNodes::EndNodeTitleBar();

	ImNodes::BeginOutputAttribute(outputID);
	ImGui::Text("Output");
	ImNodes::EndOutputAttribute();

	ImNodes::EndNode();
}

void DlgStart::SetParams(ImVec2 pos, int& newID)
{
	pins = 1;
	Node::SetParams(pos, newID);
	outputID = ID + 1;
}

DlgStart::~DlgStart() {}
