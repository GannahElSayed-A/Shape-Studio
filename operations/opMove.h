#pragma once
#include <fstream>
#include<iostream>
#include"operation.h"
#include"../Shapes/Shape.h"
#include"../controller.h"
#include "../Shapes/Graph.h"
#include "../GUI/GUI.h"
class opMove : public operation {
private:
	double Dist = 0;

public:
	opMove(controller* pcont);
	virtual ~opMove();
	virtual void Execute();

};