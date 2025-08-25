#pragma once

#include "operation.h"



class opAddTri : public operation
{
public:
	opAddTri(controller* pCont);
	virtual ~opAddTri();

	//Add rectangle to the controller
	virtual void Execute();
	virtual void Undo()override;

	virtual void Redo()override;
};

