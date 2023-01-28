#ifndef PICK_BY_BOTH
#define PICK_BY_BOTH
#include "..\Figures\CFigure.h"
#include "Action.h"

class PickByBothAction :
	public Action
{
	Point P;
	int NumberOfFiguresOnScreen;
	int CorrectCounter;
	int WrongCounter;
	string StringColor;
	color PlayFigureColor;

public:
	PickByBothAction(ApplicationManager*);
	void UpdateScore(bool Correct);
	void ReadActionParameters();
	void Execute(bool WillRecord, string filename, bool where);
	void Undo();
	void Redo();
	~PickByBothAction();

};


#endif

