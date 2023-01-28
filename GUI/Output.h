#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void ClearToolBar() const;//clear toolbar
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawSquare(Point P1, GfxInfo SquareGfxInfo, bool selected = false) const; // Draw a Square
	void DrawHexagon(Point P1, GfxInfo HexInfo, bool selected = false) const;//Draw a Hexagon
	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected = false) const;  //Draw a triangle
	void DrawCir(Point P1, Point P2, GfxInfo CirGfxInfo, bool selected = false) const;  //Draw a circle

	///Make similar functions for drawing all other figure types.

	void PrintMessage(string msg) const;	//Print a message on Status bar
	void setCrntDrawColor(color);
	void setCrntFillColor(color);
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~Output();
};

#endif
