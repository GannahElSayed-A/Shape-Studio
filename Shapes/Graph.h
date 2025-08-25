#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>

using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
	enum { maxShapeCount = 1000 };
	enum { members = 100 };
protected:
	shape* group[members];
	shape* shapesList[maxShapeCount];//a container to hold all shapes							   
	int shapeCount;			// Actual number of shapes stored in the list
	shape* selectedShape;	//pointer to the currently selected shape
	vector <shape*> shapecopied;
	window* pWind;
	shape* undonshapes[maxShapeCount];
	int undoneshapescount=0;

public:	
	int j = 0;
	vector <shape*> getcopy();
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	shape* resetselect(int x, int y) const;
	shape*  resetmultiselect (int x, int y) const;
	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file

	shape* GetSelected();
	void SetSelected(shape* s);
	void copy();
	void Delete();
	void back();
	void multiDelete();
	void zoom_in();
	void zoom_out();
	void grouped();
	void PopFromShapeList(shape*);
	buttonstate Drag(Point& P2);
	void paste();
	void ResizeSelectedShapes(double factor);
	void setselectedshapenull() {
		selectedShape = nullptr;
	}
};
