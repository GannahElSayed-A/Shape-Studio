#pragma once

#include "../operations/operation.h"



class opPaste : public operation {
public:
	opPaste(controller* pCont);

	virtual void Execute();
};