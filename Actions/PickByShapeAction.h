#ifndef PICK_BY_SHAPE
#define PICK_BY_SHAPE
#include "..\Figures\CFigure.h"
#include "Action.h"

class PickByShapeAction :
	public Action
{
	Point P;
	int NumberOfFiguresOnScreen;
	int CorrectCounter;
	int WrongCounter;

public:
	PickByShapeAction(ApplicationManager*);
	void UpdateScore(bool Correct);
	void ReadActionParameters();
	void Execute(bool WillRecord, string filename, bool where);
	void Undo();
	void Redo();
	~PickByShapeAction();
};


#endif
