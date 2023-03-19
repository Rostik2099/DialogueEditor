#pragma once
#include "Editor/Node.h"

class GiveMoney : public Node
{
public:
	GiveMoney();
	~GiveMoney();

	void Draw() override;
	void SetParams(ImVec2 pos, int& ID) override;

private:
	char buffer[255];
};

