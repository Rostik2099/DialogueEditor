#pragma once
#include "Editor/Node.h"

class NPCAnswer : public Node
{
public:
	NPCAnswer();
	~NPCAnswer();

	void Draw() override;
	void SetParams(ImVec2 pos, int& ID) override;

private:
	char buffer[255];
};

