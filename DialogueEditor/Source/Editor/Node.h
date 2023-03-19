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

	void SetParams(ImVec2 startPos, int& newID) 
	{
		this->startPos = startPos;
		this->ID = newID;
		newID += 1 + pins;
	};
	int GetID() { return this->ID; };
	void GetIOid(int& inputID, int& outputID) 
	{
		inputID = this->inputID;
		outputID = this->outputID;
	};

	virtual	void Draw() 
	{
		if (justCreated)
		{
			ImNodes::SetNodeScreenSpacePos(ID, startPos);
			justCreated = false;
		}
	};

protected:
	bool justCreated = true;
	ImVec2 startPos;
	int inputID = -1, outputID = -1;
	int ID;
	int pins = 0;
};

