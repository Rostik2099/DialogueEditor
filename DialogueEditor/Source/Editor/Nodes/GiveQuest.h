#pragma once
#include "Editor/Node.h"

class GiveQuest : public Node
{
public:
	GiveQuest();
	~GiveQuest();

	void Draw() override;
	void SetParams(ImVec2 pos, int& ID) override;

private:
	char buffer[255];
};

