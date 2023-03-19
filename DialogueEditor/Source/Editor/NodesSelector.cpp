#include "NodesSelector.h"
#include "DialogueEditor.h"

NodesSelector::NodesSelector(DialogueEditor* editor, ImVec2 dropPos)
{
	this->editor = editor;
	this->dropPos = dropPos;
}

void NodesSelector::Draw()
{
	if (justCreated)
	{
		ImGui::SetNextWindowPos(ImGui::GetMousePos());
		justCreated = false;
	}
	ImGui::SetNextWindowSize(ImVec2(200.f, 100.f));
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
			editor->SpawnNode(node.second);
			editor->DestroyNodeSelector();
			return;
		}
	}
}

NodesSelector::~NodesSelector() {}
