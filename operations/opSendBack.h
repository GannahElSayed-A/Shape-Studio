#pragma once

#include "../operations/operation.h"
class opSendBack : public operation
{
public:
	opSendBack(controller* pCont);
	virtual void Execute();
};

