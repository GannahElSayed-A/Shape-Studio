#pragma once

#include "operation.h"

//Add Rectangle operation class



class opaddoval : public operation
{
public:
	opaddoval(controller* pcont);
	virtual ~opaddoval();
	virtual void Execute();
	virtual void Undo()override;

	virtual void Redo()override;

};




