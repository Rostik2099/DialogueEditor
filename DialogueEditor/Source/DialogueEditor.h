#pragma once
#include "imnodes.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Nodes/DlgStart.h"
#include "Nodes/DlgEnd.h"

class DialogueEditor
{
public:

	DialogueEditor();
	~DialogueEditor();

	void Draw();

//Temp
private:
	DlgStart* dlgStart;
	DlgEnd* dlgEnd;
};

