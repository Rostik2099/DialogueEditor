#include "DialogueEditor.h"
#include <iostream>
#include "Nodes/DlgStart.h"
#include "Nodes/DlgEnd.h"

DialogueEditor::DialogueEditor()
{ 
	DlgStart* dlgStart = new DlgStart;
	DlgEnd* dlgEnd = new DlgEnd;
	DlgStart* dlgStart2 = new DlgStart;

	this->nodes.push_back(dlgStart);
	this->nodes.push_back(dlgEnd);
	this->nodes.push_back(dlgStart2);
}

void DialogueEditor::Draw()
{
	int nodeID = 1;
	ImGui::Begin("Dialogue Editor");
	ImNodes::BeginNodeEditor();

	for (auto node : nodes)
	{
		node->Draw(nodeID);
		nodeID++;
	}

	for (int i = 0; i < links.size(); i++)
	{
		ImNodes::Link(i, links[i].first, links[i].second);
	}

	ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_BottomLeft);

	ImNodes::EndNodeEditor();

	int startID, endID;
	if (ImNodes::IsLinkCreated(&startID, &endID))
	{
		this->links.push_back(std::make_pair(startID, endID));
	}
}

DialogueEditor::~DialogueEditor() {}