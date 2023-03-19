#include "DlgEnd.h"

DlgEnd::DlgEnd() {}

void DlgEnd::Draw()
{
	const int hardcode2 = 3;
	ImNodes::BeginNode(hardcode2);
	ImNodes::BeginNodeTitleBar();
	ImGui::Text("End");
	ImNodes::EndNodeTitleBar();
	ImNodes::BeginInputAttribute(4);
	ImGui::Text("Input");
	ImNodes::EndInputAttribute();
	ImNodes::EndNode();
}

DlgEnd::~DlgEnd() {}