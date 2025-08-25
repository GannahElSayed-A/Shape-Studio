#pragma once

#include "../operations/operation.h"
class opDelete : public operation
{
public:
	opDelete(controller* pCont);
	virtual void Execute();
};