#pragma once

#include "operation.h"






class opAddcircle : public operation
{
public:
	opAddcircle(controller* pCont);
	virtual ~opAddcircle();

	//Add rectangle to the controller
	virtual void Execute();
	virtual void Undo()override;

	virtual void Redo()override;

};







