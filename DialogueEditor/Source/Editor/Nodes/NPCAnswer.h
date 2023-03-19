#pragma once
#include "Editor/Node.h"

class NPCAnswer : public Node
{
public:
	NPCAnswer();
	~NPCAnswer();

	void Draw() override;

private:
	char buffer[255];
};

