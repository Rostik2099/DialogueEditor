#pragma once
#include "Editor/Node.h"

class ChangeDialogue : public Node
{
public:
	ChangeDialogue();
	~ChangeDialogue();

	void Draw() override;

private:
	char buffer[255];
};

