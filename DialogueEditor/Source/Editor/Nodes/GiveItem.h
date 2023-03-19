#pragma once
#include "Editor/Node.h"

class GiveItem : public Node
{
public:
	GiveItem();
	~GiveItem();

	void Draw() override;

private:
	char idBuffer[255];
	char quantBuffer[255];
};

