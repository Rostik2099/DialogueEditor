#pragma once

#include "imnodes.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class Node
{
public:
	Node() {};
	~Node() {};

	void SetStartPos(ImVec2 startPos) { this->startPos = startPos; };

	virtual	void Draw(int& nodeID) 
	{
		if (justCreated)
		{
			ImNodes::SetNodeScreenSpacePos(nodeID, startPos);
			justCreated = false;
		}
	};

private:
	bool justCreated = true;
	ImVec2 startPos;
};

