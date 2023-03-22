#include "NodesSelector.h"
#include "DialogueEditor.h"

NodesSelector::NodesSelector(DialogueEditor* editor, ImVec2 dropPos, int dropID)
{
	this->editor = editor;
	this->dropPos = dropPos;
	this->dropID = dropID;
}

void NodesSelector::Draw()
{
	if (justCreated)
	{
		ImGui::SetNextWindowPos(ImGui::GetMousePos());
		justCreated = false;
	}
	ImGui::SetNextWindowSize(ImVec2(300.f, 200.f));
	ImGui::Begin("Create Node", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings);
	ShowNodes();
	if (!ImGui::IsWindowFocused())
	{
		editor->DestroyNodeSelector();
	}
	ImGui::End();
}

void NodesSelector::ShowNodes()
{
	for (auto node : this->nodesList)
	{
		if (ImGui::Button(node.first.c_str()))
		{
			editor->DeleteLink(dropID);
			editor->SpawnNode(node.second, GetDropPos() , dropID);
			editor->DestroyNodeSelector();
			return;
		}
	}
}

NodesSelector::~NodesSelector() {}
