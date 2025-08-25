#pragma once

#include "../operations/operation.h"
class ZoomOut : public operation
{
public:
	ZoomOut(controller* pCont);
	virtual void Execute();
};

