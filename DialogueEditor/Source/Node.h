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

	virtual	void Draw(int& nodeID) {};
};

