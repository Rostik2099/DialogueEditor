#pragma once
#include "Editor/Node.h"

class GiveMoney : public Node
{
public:
	GiveMoney();
	~GiveMoney();

	void Draw() override;

private:
	char buffer[255];
};

