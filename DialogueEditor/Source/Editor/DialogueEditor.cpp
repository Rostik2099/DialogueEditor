#include "DialogueEditor.h"
#include <iostream>
#include "Nodes/DlgStart.h"
#include "Nodes/DlgEnd.h"
#include "Nodes/ProgressQuest.h"

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

	ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_BottomRight);

	ImNodes::EndNodeEditor();

	int startID, endID;
	if (ImNodes::IsLinkCreated(&startID, &endID))
	{
		this->links.push_back(std::make_pair(startID, endID));
	}

	int dropID;
	if (ImNodes::IsLinkDropped(&dropID))
	{
		selector = new NodesSelector(this, ImGui::GetMousePos());
	}

	if (selector)
	{
		selector->Draw();
	}
}

void DialogueEditor::DestroyNodeSelector()
{
	delete selector;
	selector = nullptr;
}

void DialogueEditor::SpawnNode(NodeType nodeType)
{
	switch (nodeType)
	{
	case Start:
		CreateNewNode<DlgStart>();
		break;
	case End:
		CreateNewNode<DlgEnd>();
		break;
	case ProgrQst:
		CreateNewNode<ProgressQuest>();
		break;
	}
}

DialogueEditor::~DialogueEditor() {}