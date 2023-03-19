#include "DlgStart.h"

DlgStart::DlgStart() {}

void DlgStart::Draw()
{
	const int hardcodenode = 1;
	ImNodes::BeginNode(hardcodenode);
	ImNodes::BeginNodeTitleBar();
	ImGui::Text("Start");
	ImNodes::EndNodeTitleBar();
	ImNodes::BeginOutputAttribute(2);
	ImGui::Text("Output");
	ImNodes::EndOutputAttribute();
	ImNodes::EndNode();
}

DlgStart::~DlgStart() {}
