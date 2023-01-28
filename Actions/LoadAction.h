#pragma once
#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


class LoadAction :public Action
{
	string filename;
	GfxInfo currentGfxInfo; 
public:
	
	LoadAction(ApplicationManager* pApp); //thats allow application manager to execute loadaction

	void ReadActionParameters(); 

	void Execute(bool WillRecord, string filename, bool where = true);

	color convertStringToColor(string color);

	void Undo();

	void Redo();

	~LoadAction();
};
