#ifndef MOVE_FIGURE_ACTION_H
#define MOVE_FIGURE_ACTION_H

#include "Action.h"

//Move Figure Action class
class MoveFigureAction : public Action
{
private:
	Point POld, PNew; //Old and new centers
	GfxInfo RectGfxInfo;
	bool SelectedFlag;
public:
	MoveFigureAction(ApplicationManager* pApp); //Constructor

	virtual void ReadActionParameters(); //Reads move parameters

	virtual void Execute(bool WillRecord, string filename, bool where = true); //Execute the action

	void Undo(); //Undo the action

	void Redo(); //Redo the action

	~MoveFigureAction(); //Destructor
};

#endif