#pragma once

#include "operation.h"

class opAddLine : public operation
{
public:
	opAddLine(controller* pCont);
	virtual ~opAddLine();

	//Add rectangle to the controller
	virtual void Execute();
	virtual void Undo()override;

	virtual void Redo()override;

};