#pragma once

#include "../operations/operation.h"
class ZoomIn : public operation
{
public:
	ZoomIn(controller* pCont);
	virtual void Execute();
};

