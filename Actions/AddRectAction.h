#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddRectAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo; //Rectangle graphics info
public:
	AddRectAction(ApplicationManager *pApp); //Constructor

	virtual void ReadActionParameters(); //Reads rectangle parameters
	
	virtual void Execute(bool WillRecord, string filename, bool where = true) ; //Execute the action

	void Undo(); //Undo the action

	void Redo(); //Redo the action

	~AddRectAction(); //Destructor
};

#endif