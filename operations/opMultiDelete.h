#pragma once

#include "operation.h"
class opMultDelete : public operation
{
public:
	opMultDelete(controller* pCont);
	virtual void Execute();
};




