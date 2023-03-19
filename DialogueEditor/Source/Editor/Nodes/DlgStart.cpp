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

void DlgStart::SetParams(ImVec2 pos, int& ID)
{
	pins = 1;
	Node::SetParams(pos, ID);
	inputID = ID + 1;
	outputID = ID + 2;
}

DlgStart::~DlgStart() {}
