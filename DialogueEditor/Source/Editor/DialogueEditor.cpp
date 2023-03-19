#include "DialogueEditor.h"
#include <iostream>
#include "Nodes/DlgStart.h"
#include "Nodes/DlgEnd.h"
#include "Nodes/ProgressQuest.h"
#include "Nodes/GiveQuest.h"
#include "Nodes/GiveItem.h"

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

	ImNodes::EndNodeEditor();

	int startID, endID;
	if (ImNodes::IsLinkCreated(&startID, &endID))
	{
		this->links.push_back(std::make_pair(startID, endID));
	}

	int dropID;
	if (ImNodes::IsLinkDropped(&dropID))
	{
		OpenNodeSelector();
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
	case GiveQst:
		CreateNewNode<GiveQuest>();
		break;
	case GiveItm:
		CreateNewNode<GiveItem>();
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
		for (int i = 0; i < nodes.size(); i++)
		{
			for (int n = 0; n < nodesToDelete.size(); n ++)
			{
				if (nodes[i]->GetID() == nodesToDelete[n])
				{
					int inID, outID;
					nodes[i]->GetIOid(inID, outID);
					for (int l = 0; l < links.size(); l++)
					{
						if (links[l].first == inID || links[l].first == outID || links[l].second == inID || links[l].second == outID)
						{
							links.erase(links.begin() + l, links.begin() + l + 1);
						}
					}
					nodesToDelete.erase(nodesToDelete.begin() + n, nodesToDelete.begin() + n + 1);
					delete nodes[i];
					nodes.erase(nodes.begin() + i, nodes.begin() + i + 1);
				}
			}
		}
	}
}

void DialogueEditor::OpenNodeSelector()
{
	selector = new NodesSelector(this, ImGui::GetMousePos());
}

DialogueEditor::~DialogueEditor() {}