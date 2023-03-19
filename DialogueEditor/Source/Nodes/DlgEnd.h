#pragma once
#include "Node.h"
class DlgEnd : public Node
{
public:
	DlgEnd();
	~DlgEnd();

	void Draw(int& nodeID) override;
};

