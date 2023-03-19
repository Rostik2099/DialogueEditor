#pragma once
#include <vector>

#include "imnodes.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Node.h"
#include "NodesSelector.h"

class DialogueEditor
{
public:

	DialogueEditor();
	~DialogueEditor();

	void Draw();
	void DestroyNodeSelector();
	void SpawnNode(NodeType nodeType);

private:
	template<typename Class>
	void CreateNewNode()
	{
		Node* newNode = new Class;
		newNode->SetStartPos(selector->GetDropPos());
		nodes.push_back(newNode);
	};

private:
	std::vector<Node*> nodes;
	std::vector<std::pair<int, int>> links;

	NodesSelector* selector = nullptr;
};

