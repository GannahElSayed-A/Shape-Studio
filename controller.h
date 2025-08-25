#pragma once

#include "DEFS.h"
#include "Shapes\Graph.h"
#include "GUI\GUI.h"

class operation; //forward declaration

//Main class that manages everything in the application.
class controller
{

	Graph* pGraph;	//pointe to the grapg
	GUI* pGUI;		//Pointer to UI class
	vector<operation*>Present;
	vector<operation*>future;
	vector<shape*>OperatedOn;
	vector<shape*>FutureOperatedOn;

public:	
	controller(); 
	~controller();
	
	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	operationType GetUseroperation() const;
	operation* createOperation(operationType) ; //Creates an operation
	void Run();
	
	Graph* getGraph() const;
	
	// -- Interface Management Functions
	GUI *GetUI() const; //Return pointer to the UI
	void UpdateInterface() const;	//Redraws all the drawing window	
	bool checkFuture();
	operation* UpdateFuture();
	void popOperatedOnToPresent();
	void pushToOperatedOn(shape* shp);
	bool checkPresent();
	operation* UpdateTimeLine();
	void popOperatedOn();
	void pushToFutureOperatedOn(shape*);
	shape* getFutureOperatedOn();
	shape* getOperatedOn();	//gets recent shape
};

