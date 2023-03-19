#pragma once
#include "Editor/Node.h"

class GiveQuest : public Node
{
public:
	GiveQuest();
	~GiveQuest();

	void Draw() override;

private:
	char buffer[255];
};

