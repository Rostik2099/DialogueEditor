#pragma once
#include "Editor/Node.h"

class DlgStart : public Node
{
public:
	DlgStart();
	~DlgStart();

	void Draw(int& nodeID) override;
};

