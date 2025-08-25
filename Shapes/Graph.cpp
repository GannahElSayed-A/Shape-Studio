#include "Graph.h"
#include "../GUI/GUI.h"

Graph::Graph()
{
	shapeCount = 0;
	selectedShape = nullptr;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes list
	if(shapeCount<maxShapeCount)
		shapesList[shapeCount++] = pShp;
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (int i=0;i<shapeCount; i++)
		shapesList[i]->Draw(pUI);
}


shape* Graph::Getshape(int x, int y) const
{

	for (int i = shapeCount-1; i >=0; i--)
		if (shapesList[i]->is_in_fig(x, y)) {
			return shapesList[i];
		}


	return nullptr;
}
shape* Graph::resetselect(int x, int y) const
{
	for (int i = 0; i < shapeCount; i++)
	{
		shapesList[i]->SetSelected(false);

	}
	return nullptr;
}
shape* Graph::resetmultiselect(int x, int y) const
{
	bool s = false;
	for (int i = 0; i < shapeCount; i++)
	{
		if (shapesList[i]->is_in_fig(x, y))
		{
			s = true;
			break;
		}

	}
	if(s == false)
	{
		resetselect(x,y);
	}
	return nullptr;
}
void Graph::SetSelected(shape* s) {
	selectedShape = s;
}

shape* Graph::GetSelected()
{
	return selectedShape;
}

void Graph::copy() {
	shapecopied.clear();
	for (int i = 0; i < shapeCount; i++)
	{
		if (shapesList[i]->IsSelected() == true) 
		{
			shapecopied.push_back(shapesList[i]->copy());
			shapesList[i]->SetSelected(false);

		}
	}
}

vector <shape*> Graph::getcopy()
{
	return shapecopied;
}

void Graph::Delete() {
	if (selectedShape == nullptr) {
		return; // No shape is selected
	}

	for (int i = 0; i < shapeCount; ++i) {
		if (shapesList[i] == selectedShape) {
			// Delete the shape
			delete shapesList[i];

			// Shift remaining shapes to fill the gap
			for (int j = i; j < shapeCount - 1; ++j) {
				shapesList[j] = shapesList[j + 1];
			}

			shapesList[shapeCount - 1] = nullptr; // Clear the last element
			--shapeCount; // Decrease the shape count
			selectedShape = nullptr; // Clear the selection
			return;
		}
	}
}

void Graph::PopFromShapeList(shape* PopMe) 
{
	
	undonshapes[undoneshapescount] = shapesList[shapeCount - 1];
	Delete();
}


buttonstate Graph::Drag(Point& P2)
{
	return pWind->GetButtonState(LEFT_BUTTON, P2.x, P2.y);
}


void Graph::back() {
	if (selectedShape == nullptr) {
		return; 
	}

	for (int i = 0; i < shapeCount; ++i) {
		if (shapesList[i]->IsSelected()) {
			shape* temp;
			temp = shapesList[0];
			shapesList[0] = shapesList[i];
			shapesList[i] = temp;
		}
	}
}

void Graph::multiDelete() {
	if (selectedShape == nullptr) {
		return; 
	}
	for (int i = 0; i < shapeCount; ++i) {
		if (shapesList[i]->IsSelected()) { 
			delete shapesList[i];

			
			for (int j = i; j < shapeCount - 1; ++j) {
				shapesList[j] = shapesList[j + 1];
			}

			shapesList[shapeCount - 1] = nullptr; 
			--shapeCount;
			--i; 

		}
	}
}


void Graph::zoom_in() {
	for (int i = 0; i < shapeCount; i++) {
		shapesList[i]->Zoom(2);
	}

}

void Graph::zoom_out() {
	for (int i = 0; i < shapeCount; i++) {
		shapesList[i]->Zoom(0.5);
	}

}

void Graph::grouped() {
	if (selectedShape == nullptr) {
		return; 
	}
	for (int i = 0; i < shapeCount; ++i) {
		if (shapesList[i]->IsSelected()) { 
			group[j] = shapesList[i];
			j++;

		}
	}
}
void Graph::ResizeSelectedShapes(double factor) {
	if (factor <= 0) {
		return;
	}

	for (int i = 0; i < shapeCount; ++i) {
		if (shapesList[i] == selectedShape) {

			shapesList[i]->Resize(factor);
			return;
		}
	}


}

void Graph::paste() {

	if (shapecopied.empty()) {
		return;
	}


	for (shape* pShape : shapecopied) {
		if (pShape) {
			if (shapeCount < maxShapeCount) {

				shapesList[shapeCount++] = pShape->copy();
			}
		}
	}

}
