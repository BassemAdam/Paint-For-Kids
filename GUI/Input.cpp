#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQR: return DRAW_SQR;
			case ITM_TRI: return DRAW_TRI;
			case ITM_HEXA: return DRAW_HEXA;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_BLACK: return C_BLACK;
			case ITM_YELLOW: return C_YELLOW;
			case ITM_ORANGE: return C_ORANGE;
			case ITM_RED: return C_RED;
			case ITM_GREEN: return C_GREEN;
			case ITM_BLUE: return C_BLUE;
			case ITM_SelectOne: return SelectOne;
			case ITM_ChangeDraw: return ChangeDraw;
			case ITM_FILL: return FILL;
			case ITM_MOVE_SHAPE:  return MOVE_SHAPE;
			case ITM_DELETE: return _DELETE;
			case ITM_CLEAN_ALL: return CLEAN_ALL;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_START_RECORDING: return START_RECORDING;
			case ITM_STOP_RECORDING:  return STOP_RECORDING;
			case ITM_PLAY_RECORDING:  return PLAY_RECORDING;
			case ITM_SAVE_GRAPH: return SAVE_GRAPH;
			case ITM_LOAD_GRAPH: return LOAD_GRAPH;
			case ITM_Mute: return Mute;
			case ITM_TO_PLAY: return TO_PLAY;
			case ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		{
			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < UI.ToolBarHeight)
			{
				//Check whick Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_By_Type: return By_Type;
				case ITM_By_color:return By_color;
				case ITM_Type_color: return Type_color;
				case ITM_To_Draw_Mode: return TO_DRAW;
				case ITM_P_EXIT: return EXIT;
				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}

			//[2] User clicks on the drawing area
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return DRAWING_AREA;
			}

			//[3] User clicks on the status bar
			return STATUS;
		}
	}
}

/////////////////////////////////

Input::~Input()
{
}
