#include "DialogueEditor.h"
#include <iostream>
#include "Nodes/DlgStart.h"
#include "Nodes/DlgEnd.h"
#include "Nodes/ProgressQuest.h"
#include "Nodes/GiveQuest.h"
#include "Nodes/GiveItem.h"
#include "Nodes/NPCAnswer.h"
#include "Nodes/ChangeDialogue.h"
#include "Nodes/GiveMoney.h"

DialogueEditor::DialogueEditor() {}

void DialogueEditor::Draw()
{
	ImGui::Begin("Dialogue Editor");
	ImNodes::BeginNodeEditor();

	for (auto node : nodes)
	{
		node->Draw();
	}

	for (int i = 0; i < links.size(); i++)
	{
		ImNodes::Link(i, links[i].first, links[i].second);
	}

	ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_BottomRight);
	this->isHovered = ImNodes::IsEditorHovered();
	ImNodes::EndNodeEditor();

	int startID, endID;
	if (ImNodes::IsLinkCreated(&startID, &endID))
	{
		DeleteLink(startID);
		DeleteLink(endID);
		this->links.push_back(std::make_pair(startID, endID));
	}

	int dropID;
	if (ImNodes::IsLinkDropped(&dropID))
	{
		OpenNodeSelector(dropID);
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

void DialogueEditor::SpawnNode(NodeType nodeType, int dropID)
{
	switch (nodeType)
	{
	case Start:
		CreateNewNode<DlgStart>(dropID);
		break;
	case End:
		CreateNewNode<DlgEnd>(dropID);
		break;
	case ProgrQst:
		CreateNewNode<ProgressQuest>(dropID);
		break;
	case GiveQst:
		CreateNewNode<GiveQuest>(dropID);
		break;
	case GiveItm:
		CreateNewNode<GiveItem>(dropID);
		break;
	case NPCAnsw:
		CreateNewNode<NPCAnswer>(dropID);
		break;
	case DlgChange:
		CreateNewNode<ChangeDialogue>(dropID);
		break;
	case GiveMny:
		CreateNewNode<GiveMoney>(dropID);
		break;
	}
}

void DialogueEditor::DeleteNodes()
{
	const int nodesNum = ImNodes::NumSelectedNodes();
	if (nodesNum != 0)
	{
		std::vector<int> nodesToDelete;
		nodesToDelete.resize(nodesNum);
		ImNodes::GetSelectedNodes(nodesToDelete.data());
		for (int i = 0; i < nodesToDelete.size(); i++)
		{
			for (int n = 0; n < nodes.size(); n++)
			{
				if (nodes[n]->GetID() == nodesToDelete[i])
				{
					int in, out;
					nodes[n]->GetIOid(in, out);
					DeleteLink(in);
					DeleteLink(out);
					delete nodes[n];
					nodes.erase(nodes.begin() + n, nodes.begin() + n + 1);
					break;
				}
			}
		}
	}
}

void DialogueEditor::DeleteLink(int linkID)
{
	if (linkID != -1)
	{
		for (int i = 0; i < links.size(); i++)
		{
			if (links[i].first == linkID || links[i].second == linkID)
			{
				links.erase(links.begin() + i, links.begin() + i + 1);
				return;
			}
		}
	}
}

void DialogueEditor::OpenNodeSelector()
{
	if (HasMouseHover())
		selector = new NodesSelector(this, ImGui::GetMousePos());
}

void DialogueEditor::OpenNodeSelector(int dropID)
{
	if (HasMouseHover())
		selector = new NodesSelector(this, ImGui::GetMousePos(), dropID);
}

Node* DialogueEditor::GetNodeByPin(int pinID)
{
	for (auto node : nodes)
	{
		int in, out;
		node->GetIOid(in, out);
		if (pinID == in || pinID == out)
		{
			return node;
		}
	}
	return nullptr;
}

DialogueEditor::~DialogueEditor() {}