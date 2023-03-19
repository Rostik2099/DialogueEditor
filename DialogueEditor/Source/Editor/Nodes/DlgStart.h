#pragma once
#include "Editor/Node.h"

class DlgStart : public Node
{
public:
	DlgStart();
	~DlgStart();

	void Draw() override;
	void SetParams(ImVec2 pos, int& ID) override;
};

