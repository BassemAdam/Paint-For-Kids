#pragma once
#include "..\Figures\CFigure.h"
#include "Action.h"

class PickByColor :public Action
{
	CFigure* Fig;
	Point point;
	int  numOfcolors;
	int RandomFigNum;
	int NumOfColorsToPicked;
	int WrongPicks;
	int CorrestPicks;
	int* ArrayOfColors;
	
public:

	PickByColor(ApplicationManager*);


	void PrntScore(int); //printing score according to case right or wrong ,final result

	void ReadActionParameters();

	void Execute(bool WillRecord, string filename, bool where = true);

	void Undo() ;

	void Redo() ;

	~PickByColor();

};