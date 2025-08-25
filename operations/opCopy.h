#pragma once

#include "../operations/operation.h"
class opCopy : public operation
{
public:
	opCopy(controller* pCont);

	virtual void Execute();
};





