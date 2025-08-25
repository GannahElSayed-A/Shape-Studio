#pragma once
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"


#include <string>
class shape;

using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};
struct POL
{
	const int* x;
	const int* y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
	
};




class GUI
{
 	HDC hDC;
	HPEN hPen = nullptr; 
	enum MenuIcon //The icons of the menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		LINE_ICON,
		ICON_RECT,
		SQUARE_ICON,
		ICON_CIRCLE,		//Recangle icon in menu
		ICON_TRI,
		ICON_OVAL,
		ICON_REG,
		ICON_IRREG,
		ICON_SELECT,
		MULTI_SELECT_ICON,
		ICON_MOVE,		//Triangle icon in menu
		ICON_ROTATE,
		/*FRONT_ICON,*/
		BACK_ICON,
		RESIZE,
		ZOOM_IN,
		ZOOM_OUT,
		COPY_ICON,
		CUT_ICON,
		ICON_PASTE,
		SAVE_ICON,
		LOAD_ICON,
		ICON_DRAWING,
		ICON_FILLING, ICON_BORDER,
//TODO: Add more icons names here
		/*ICON_BACKGROUND,*/
		ICON_DELETE,
		ICON_EMPTY,
		/*ICON_GROUP,*/
		/*ICON_PLAY,*/		
		ICON_REDO,
		ICON_UNDO,
		ICON_EXIT,
		DRAW_ICON_COUNT	
		//no. of menu icons ==> This should be the last line in this enum
	//no. of menu icons ==> This should be the last line in this enum

	};




	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu
	shape* selectedShape;



	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed



	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;
	//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void ChangePenColor(COLORREF color) {

		if (hPen) {
			DeleteObject(hPen);
		}

		hPen = CreatePen(PS_INSIDEFRAME, 1, color);

		SelectObject(hDC, hPen);
	}
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void DrawLine(Point P1, Point P2, GfxInfo lineGfxInfo) const;

	void DrawEllipse(Point P1, Point P2, GfxInfo ovalGfxInfo) const;
	
	
	void DrawTri(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo) const;
	//void DrawEllipse(Point P1, Point P2, GfxInfo ovalGfxInfo) const;
	void Drawcircle(Point P1, Point P2,double radius, GfxInfo circleGfxInfo) const;


	void Drawsquare(Point P1, int sideLength, GfxInfo squareGfxInfo) const;

	void DrawPolygon(Point* P1, int ivertices, GfxInfo regpolyGfxInfo) const;
	void DrawregPolygon(Point* P1, int ivertices, const GfxInfo regpolyGfxInfo) const;
	///Make similar functions for drawing all other shapes.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	void setcrntfillcolor(color newcolor);
	void setcrntdrawcolor(color newcolor);
	color getColorPallete();

	~GUI();

	window* getwind();
	buttonstate Drag(Point& P2);
	
};

