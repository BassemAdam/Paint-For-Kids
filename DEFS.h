#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,
	DRAW_SQR,
	DRAW_TRI,
	DRAW_HEXA,
	DRAW_CIRC,
	_DELETE,
	MOVE_SHAPE,
	ChangeDraw,
	FILL,
	C_BLACK,
	C_YELLOW,
	C_ORANGE,
	C_RED,
	C_GREEN,
	C_BLUE,
	UNDO,
	REDO,
	UN_HIGHLIGHT,
	CLEAN_ALL,
	START_RECORDING,
	STOP_RECORDING,
	PLAY_RECORDING,
	SelectOne,
	SAVE_GRAPH,
	LOAD_GRAPH,
	EXIT,
	TO_DRAW, //Switch interface to Draw mode
	TO_PLAY, //Switch interface to Play mode
	EMPTY, //A click on empty place in the toolbar
	DRAWING_AREA, //A click on the drawing area
	STATUS, //A click on the status bar
	By_Type,
	By_color,
	Type_color,
	Mute,
	P_EXIT
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif
