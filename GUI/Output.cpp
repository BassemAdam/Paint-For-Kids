#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 40; //80;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];

	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQR] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_HEXA] = "images\\MenuItems\\Menu_Hexagon.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";

	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Menu_orange.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_blue.jpg";

	MenuItemImages[ITM_SelectOne] = "images\\MenuItems\\Menu_SelectOne.jpg";
	MenuItemImages[ITM_ChangeDraw] = "images\\MenuItems\\Menu_Unhighlight.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\Menu_fill.jpg";
	MenuItemImages[ITM_MOVE_SHAPE] = "images\\MenuItems\\Menu_MoveShape.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_CLEAN_ALL] = "images\\MenuItems\\Menu_ClearAll.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";

	MenuItemImages[ITM_START_RECORDING] = "images\\MenuItems\\Menu_START_RECORDING.jpg";
	MenuItemImages[ITM_STOP_RECORDING] = "images\\MenuItems\\Menu_STOP_RECORDING.jpg";
	MenuItemImages[ITM_PLAY_RECORDING] = "images\\MenuItems\\Menu_PLAY_RECORDING.jpg";
	MenuItemImages[ITM_SAVE_GRAPH] = "images\\MenuItems\\Menu_SAVE.jpg";
	MenuItemImages[ITM_LOAD_GRAPH] = "images\\MenuItems\\Menu_LOAD_GRAPH.jpg";
	MenuItemImages[ITM_Mute] = "images\\PlayItems\\Playitems_Mute.jpg";
	MenuItemImages[ITM_TO_PLAY] = "images\\MenuItems\\Menu_PLAY.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list
	
	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const {
	for (int i = PLAY_ITM_COUNT - 1; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage("images\\PlayItems\\square-512.jpg", i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
}
void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	string PlayItemImages[PLAY_ITM_COUNT];
	///TODO: write code to create Play mode menu

	PlayItemImages[ITM_By_Type] = "images\\PlayItems\\Playitems_By_type.jpg";
	PlayItemImages[ITM_By_color] = "images\\PlayItems\\Playitems_By_color.jpg";
	PlayItemImages[ITM_Type_color] = "images\\PlayItems\\Playitems_bytype&color.jpg";

	PlayItemImages[ITM_To_Draw_Mode] = "images\\PlayItems\\Playitems_To_Draw.jpg";
	PlayItemImages[ITM_P_EXIT] = "images\\PlayItems\\Playitems_Exit.jpg";
	PlayItemImages[ITM_WHITE] = "images\\PlayItems\\square-512.jpg";
	for (int i = 0; i < PLAY_ITM_COUNT - 1; i++)
		pWind->DrawImage(PlayItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	for (int i = PLAY_ITM_COUNT - 1; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(PlayItemImages[PLAY_ITM_COUNT - 1], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
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

void Output::DrawSquare(Point P1, GfxInfo SquareGfxInfo, bool selected) const {

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;

	if (SquareGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;
	P1.x -= 50;
	P1.y -= 50;
	Point P2;
	P2.x = P1.x + 100;
	P2.y = P1.y + 100;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);


}

void Output::DrawHexagon(Point P1, GfxInfo HexInfo, bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = HexInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;

	if (HexInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(HexInfo.FillClr);
	}
	else
		style = FRAME;
	//co-ordinates of Hexagon from origin	
	int x[6] = { 100,50,-50,-100,-50,50 };
	int y[6] = { 0,sqrt(3) * 50,sqrt(3) * 50,0,-1 * (sqrt(3) * 50),-1 * (sqrt(3) * 50) };
	//adding them to our refrence point
	for (int i = 0; i < 6; i++)
	{
		x[i] += P1.x;
		y[i] += P1.y;
	}

	pWind->DrawPolygon(x, y, 6, style);



};
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
void Output::DrawCir(Point P1, Point P2, GfxInfo CirGfxInfo, bool selected) const
{
	int r = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CirGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CirGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CirGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, r, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

