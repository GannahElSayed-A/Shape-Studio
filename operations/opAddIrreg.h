#pragma once

#include "operation.h"



class opAddREGPOLY : public operation
{
public:
	opAddREGPOLY(controller* pCont);
		virtual ~opAddREGPOLY();
		virtual void Execute();

};



