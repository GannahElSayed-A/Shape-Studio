#ifndef DEFS_H
#define DEFS_H


//This file contais some global constants and definitions to be used in the project.
enum operationType //The operations supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	DRAW_OVAL,
	DRAW_SQUARE,
	DRAW_POLY,
	DRAW_REGPOLY,
	CHNG_BORDER_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_PN_CLR,	//Change background color
	DEL,			//Delete a shape(s)
	MOVE,			//Move a shape(s)
	REsize,			//Resize a shape(s)
	ROTATE,			//Rotate a shape(s)
	SEND_BACK,		//Send a shape to the back of all shapes
	BRNG_FRNT,		//Bring a shape to the front of all shapes
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application
	SELECT,
	ZOOMIN,
	ZOOMOUT,
	COPY,
	CUT,
	PASTE,
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	MULTI_SELECT,MULTI_DELETE,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY			//Switch interface to Play mode
	,UNDO,REDO,GROUP,
	TO_DELETE,
	
	///TODO: Add more operation types (if needed)
};

#endif