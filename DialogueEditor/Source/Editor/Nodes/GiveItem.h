#pragma once
#include "Editor/Node.h"

class GiveItem : public Node
{
public:
	GiveItem();
	~GiveItem();

	void Draw() override;
	void SetParams(ImVec2 pos, int& ID) override;

private:
	char idBuffer[255];
	char quantBuffer[255];
};

