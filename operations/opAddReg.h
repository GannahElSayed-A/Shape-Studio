#pragma once

#include "operation.h"


class opAddpoly : public operation
{
public:
	opAddpoly(controller* pCont);
	virtual ~opAddpoly();

	//Add rectangle to the controller
	virtual void Execute();
	virtual void Undo()override;

	virtual void Redo()override;
};




