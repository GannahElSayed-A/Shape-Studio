#pragma once

#include "operation.h"



class opAddsquare : public operation
{
public:
	opAddsquare(controller* pCont);
	virtual ~opAddsquare();

	//Add rectangle to the controller
	virtual void Execute();
	virtual void Undo()override;

	virtual void Redo()override;
};



