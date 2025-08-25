#include "GUI.h"
#include"../Shapes/Graph.h"



GUI::GUI()
{

	width = 1300;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 75;
	MenuIconWidth = 40;

	DrawColor = DARKGREEN;	//default Drawing color
	FillColor = YELLOW;	//default Filling color
	MsgColor = BLUE;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use it for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	//[1] If user clicks on the Toolbar
	if (y >= 0 && y < ToolBarHeight)
	{
		//Check whick Menu icon was clicked
		//==> This assumes that menu icons are lined up horizontally <==
		int ClickedIconOrder = (x / MenuIconWidth);
		//Divide x coord of the point clicked by the menu icon width (int division)
		//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

		switch (ClickedIconOrder)
		{

		case ICON_RECT: return DRAW_RECT;
		case ICON_TRI: return DRAW_TRI;
		/*case ICON_EXIT: return EXIT;*/
		case LINE_ICON: return DRAW_LINE;
		case ICON_CIRCLE: return DRAW_CIRC;
		case ICON_OVAL: return DRAW_OVAL;
		case ICON_REG:return DRAW_REGPOLY;
		case SQUARE_ICON: return DRAW_SQUARE;
		case ICON_IRREG: return DRAW_POLY;
		case ICON_MOVE: return MOVE;
		case ICON_ROTATE: return ROTATE;
	/*	case LOAD_ICON: return SAVE;*/
		/*case ICON_PLAY: return TO_PLAY;*/
		case ICON_SELECT: return SELECT;
		case SAVE_ICON: return MULTI_SELECT;
		case COPY_ICON: return COPY;
		case CUT_ICON: return CUT;
		case MULTI_SELECT_ICON: return MULTI_SELECT;
		case ICON_UNDO: return UNDO;
		case ICON_REDO: return REDO;
		case ICON_EMPTY: return MULTI_DELETE;
		case ZOOM_IN: return ZOOMIN;
		case ZOOM_OUT: return ZOOMOUT;
		case BACK_ICON: return SEND_BACK;
		case ICON_BORDER: return CHNG_BORDER_CLR;
		case ICON_FILLING: return CHNG_FILL_CLR;
		case ICON_PASTE: return PASTE;
		case ICON_EXIT: return EXIT;
			//case ICON_DELETE: return DEL;
		default: return EMPTY;	//A click on empty place in desgin toolbar
		}
	}

	//[2] User clicks on the drawing area
	if (y >= ToolBarHeight && y < height - StatusBarHeight)
	{
		return DRAWING_AREA;
	}

	//[3] User clicks on the status bar
	return STATUS;
	

}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar()
{

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];

	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\rect.jpg";
	MenuIconImages[ICON_TRI] = "images\\MenuIcons\\triangle.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";
	MenuIconImages[LINE_ICON] = "images\\MenuIcons\\line.p.jpg";
	MenuIconImages[ICON_IRREG] = "images\\MenuIcons\\irregular.jpg";
	MenuIconImages[SQUARE_ICON] = "images\\MenuIcons\\square.jpg";
	/*MenuIconImages[FRONT_ICON] = "images\\MenuIcons\\forwardicon.jpg";*/
	MenuIconImages[BACK_ICON] = "images\\MenuIcons\\backwardicon.jpg";
	MenuIconImages[ICON_DELETE] = "images\\MenuIcons\\del.jpg";
	MenuIconImages[ICON_CIRCLE] = "images\\MenuIcons\\cir.jpg";
	MenuIconImages[ICON_ROTATE] = "images\\MenuIcons\\rotate.m.jpg";
	MenuIconImages[ICON_FILLING] = "images\\MenuIcons\\fillcolor.jpg";
	MenuIconImages[ICON_MOVE] = "images\\MenuIcons\\move.jpg";
	MenuIconImages[ICON_DRAWING] = "images\\MenuIcons\\pen.jpg";
	/*MenuIconImages[ICON_PLAY] = "images\\MenuIcons\\playm.jpg";
	MenuIconImages[ICON_DRAW] = "images\\MenuIcons\\drawm.jpg";*/
	MenuIconImages[ICON_EMPTY] = "images\\MenuIcons\\emptym.jpg";
	MenuIconImages[LOAD_ICON] = "images\\MenuIcons\\sav.jpg";
	MenuIconImages[ICON_UNDO] = "images\\MenuIcons\\undoi.jpg";
	MenuIconImages[ICON_REDO] = "images\\MenuIcons\\redoi.jpg";
	/*MenuIconImages[ICON_BACKGROUND] = "images\\MenuIcons\\background.jpg";*/
	MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\oval.jpg";
	MenuIconImages[ICON_REG] = "images\\MenuIcons\\reg.jpg";
	MenuIconImages[ICON_SELECT] = "images\\MenuIcons\\select_icon.jpg";
	MenuIconImages[ZOOM_IN] = "images\\MenuIcons\\ZOOM_IN.jpg";
	MenuIconImages[ZOOM_OUT] = "images\\MenuIcons\\ZOOM_OUT.jpg";
	MenuIconImages[COPY_ICON] = "images\\MenuIcons\\COPY.jpg";
	MenuIconImages[CUT_ICON] = "images\\MenuIcons\\CUT.jpg";
	MenuIconImages[ICON_PASTE] = "images\\MenuIcons\\PASTE.jpg";
	MenuIconImages[SAVE_ICON] = "images\\MenuIcons\\SAVE_ICON.jpg";
	MenuIconImages[RESIZE] = "images\\MenuIcons\\RESIZE.jpg";
	MenuIconImages[MULTI_SELECT_ICON] = "images\\MenuIcons\\multiselect.jpg";
	MenuIconImages[ICON_BORDER] = "images\\MenuIcons\\pen2.jpg";
	/*MenuIconImages[ICON_GROUP] = "images\\MenuIcons\\colorf.jpg";*/
	//TODO: Prepare images for each menu icon and add it to the list


	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
}


//////////////////////////////////////////////////////////////////////////////////////////



void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}





//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

void GUI::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo) const
{
	color DrawingClr;
	if (TriGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

};

void GUI::DrawLine(Point P1, Point P2, GfxInfo lineGfxInfo) const
{
	color DrawingClr;
	if (lineGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = lineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, lineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (lineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(lineGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}


void GUI::DrawEllipse(Point P1, Point P2, GfxInfo ovalGfxInfo) const
{
	color DrawingClr;
	if (ovalGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = ovalGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, ovalGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (ovalGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(ovalGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);

}



void GUI::Drawcircle(Point P1,Point P2,double radius, GfxInfo circleGfxInfo) const
{
	Point MA = P1;
	double x = pow((P2.x - P1.x), 2);
	double y = pow((P2.y - P1.y), 2);
	radius = sqrt(x + y);
	color DrawingClr;
	if (circleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = circleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, circleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (circleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(circleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y,radius, style);

}


void GUI::Drawsquare(Point P1,int sideLength, GfxInfo squareGfxInfo) const
{
	Point P2;
	P2.x = P1.x + sideLength;
	P2.y = P1.y + sideLength;

	color DrawingClr;
	if (squareGfxInfo.isSelected)
		DrawingClr = HighlightColor;
	else
		DrawingClr = squareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, squareGfxInfo.BorderWdth);

	drawstyle style;
	if (squareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(squareGfxInfo.FillClr);
	}
	else
	{
		style = FRAME;
	}

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style, 0, 0);
}



void GUI::DrawPolygon(Point* P1, int ivertices, GfxInfo regpolyGfxInfo) const
{
	color DrawingClr;
	if (regpolyGfxInfo.isSelected) 
		DrawingClr = HighlightColor; 
	else
		DrawingClr = regpolyGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, regpolyGfxInfo.BorderWdth); 

	drawstyle style;
	if (regpolyGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(regpolyGfxInfo.FillClr);
	}
	else
		style = FRAME;

	// Convert Point array to arrays of x and y coordinates
	int* xCoords = new int[ivertices];
	int* yCoords = new int[ivertices];

	for (int i = 0; i < ivertices; i++)
	{
		xCoords[i] = P1[i].x;
		yCoords[i] = P1[i].y;
	}

	pWind->DrawPolygon(xCoords, yCoords, ivertices, style);

	delete[] xCoords;
	delete[] yCoords;
}

void GUI::DrawregPolygon(Point* P1, int ivertices, const GfxInfo regpolyGfxInfo) const
{
	color DrawingClr;
	if (regpolyGfxInfo.isSelected) // Shape is selected
		DrawingClr = HighlightColor; // Shape should be drawn highlighted
	else
		DrawingClr = regpolyGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, regpolyGfxInfo.BorderWdth); // Set Drawing color & width

	drawstyle style;
	if (regpolyGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(regpolyGfxInfo.FillClr);
	}
	else
		style = FRAME;

	// Convert Point array to arrays of x and y coordinates
	int* xCoords = new int[ivertices];
	int* yCoords = new int[ivertices];

	for (int i = 0; i < ivertices; i++)
	{
		xCoords[i] = P1[i].x;
		yCoords[i] = P1[i].y;
	}

	pWind->DrawPolygon(xCoords, yCoords, ivertices, style);

	delete[] xCoords;
	delete[] yCoords;
}
window* GUI::getwind()
{
	return pWind;
}

void GUI::setcrntdrawcolor(color newcolor)
{
	DrawColor = newcolor;
}
void GUI::setcrntfillcolor(color newcolor)
{
	FillColor = newcolor;
}
color GUI::getColorPallete()
{
	window* colorWindow = CreateWind(500, 500, 100, 100);
	colorWindow->DrawImage("images\\MenuIcons\\p.jpg", 0, 0, 500, 500);
	Point pcolor;
	colorWindow->WaitMouseClick(pcolor.x, pcolor.y);
	color clr = colorWindow->GetColor(pcolor.x, pcolor.y);
	delete colorWindow;
	return clr;

}

buttonstate GUI::Drag(Point& P2)
{
	return pWind->GetButtonState(LEFT_BUTTON, P2.x, P2.y);
}