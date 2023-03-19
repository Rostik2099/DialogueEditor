#pragma once
#include "Editor/Node.h"

class ChangeDialogue : public Node
{
public:
	ChangeDialogue();
	~ChangeDialogue();

	void Draw() override;
	void SetParams(ImVec2 pos, int& ID) override;

private:
	char buffer[255];
};

