#pragma once
#include <vector>
#include <iostream>

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
	void SpawnNode(NodeType nodeType, int dropID);
	void DeleteNodes();
	void DeleteLink(int linkID);
	void OpenNodeSelector();
	void OpenNodeSelector(int dropID);
	bool HasMouseHover() { return this->isHovered; };
	Node* GetNodeByPin(int pinID);

private:
	template<typename Class>
	void CreateNewNode(int dropID)
	{
		Node* newNode = new Class;
		newNode->SetParams(selector->GetDropPos(), nextID);
		int in, out;
		newNode->GetIOid(in, out);
		if (dropID != -1)
		{
			Node* dropNode = GetNodeByPin(dropID);
			int din, dout;
			dropNode->GetIOid(din, dout);
			if (din == dropID && out != -1)
			{
				this->links.push_back(std::make_pair(dropID, out));
			}
			else if (dout == dropID && in != -1)
			{
				this->links.push_back(std::make_pair(dropID, in));
			}
		}
		nodes.push_back(newNode);
	};

private:
	std::vector<Node*> nodes;
	std::vector<std::pair<int, int>> links;
	int nextID = 0;
	NodesSelector* selector = nullptr;
	bool isHovered;
};

