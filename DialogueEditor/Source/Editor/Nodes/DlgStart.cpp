#include "DlgStart.h"

DlgStart::DlgStart() 
{
	pins = 1;
}

void DlgStart::Draw()
{
	Node::Draw();
	ImNodes::BeginNode(ID);

	ImNodes::BeginNodeTitleBar();
	ImGui::Text("Start");
	ImNodes::EndNodeTitleBar();

	outputID = ID + 1;
	ImNodes::BeginOutputAttribute(outputID);
	ImGui::Text("Output");
	ImNodes::EndOutputAttribute();

	ImNodes::EndNode();
}

DlgStart::~DlgStart() {}
