#pragma once

#include "operation.h"

//Add select operation class
class opMultiSelect : public operation
{
public:
	opMultiSelect(controller* pCont);
	virtual ~opMultiSelect();

	//Add select to the controller
	virtual void Execute();

};
class opChangeFillColor : public operation
{
public:
	opChangeFillColor(controller* pCont);
	virtual ~opChangeFillColor();

	// Execute the operation
	virtual void Execute();
};

class opChangeBorderColor : public operation
{
public:
	opChangeBorderColor(controller* pCont);
	virtual ~opChangeBorderColor();
	virtual void Execute();
};

class opChangePenColor : public operation
{
public:
	opChangePenColor(controller* pCont);
	virtual ~opChangePenColor();
	virtual void Execute();
};

class opRotate :
	public operation
{
public:
	opRotate(controller* pCont);
	virtual ~opRotate();
	virtual void Execute();
};