#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H

#include "Action.h"

//Add Square Action class
class AddSqrAction : public Action
{
private:
	Point P1; //Square Center
	GfxInfo SqrGfxInfo; //Square graphics info
public:
	AddSqrAction(ApplicationManager* pApp); //Constructor

	virtual void ReadActionParameters(); //Reads square parameters

	virtual void Execute(bool WillRecord, string filename, bool where = true); //Execute the action

	void Undo(); //Undo the action

	void Redo(); //Redo the action

	~AddSqrAction(); //Destructor
};

#endif