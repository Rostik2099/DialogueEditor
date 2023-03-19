#pragma once
#include "Editor/Node.h"

class DlgEnd : public Node
{
public:
	DlgEnd();
	~DlgEnd();

	void Draw() override;
	void SetParams(ImVec2 pos, int& ID) override;
};

