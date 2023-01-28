#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


class SaveAction :public Action
{
	string filename5;		//the name of file that we will save data into
	GfxInfo currentGfxInfo; // to get current color and current fill color from gfxinfo

public:

	SaveAction(ApplicationManager* pApp);

	string convertcolorToString(color color);

	void ReadActionParameters(); //reads file name and current clr 

	void Execute(bool WillRecord, string filename, bool where = true);

	void Undo();

	void Redo();

	~SaveAction();
};
