#pragma once
#include "Editor/Node.h"

class ProgressQuest : public Node
{
public:
	ProgressQuest();
	~ProgressQuest();

	void Draw(int& nodeID) override;

private:
	char buffer[255];
};

