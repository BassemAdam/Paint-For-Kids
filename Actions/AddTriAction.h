#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H

#include "Action.h"

//Add Triangle Action class
class AddTriAction : public Action
{
private:
	Point P1, P2, P3; //Triangle Corners
	GfxInfo TriGfxInfo; //Triangle graphics info
public:
	AddTriAction(ApplicationManager* pApp); //Constructor

	virtual void ReadActionParameters(); //Reads Triangle parameters

	virtual void Execute(bool WillRecord, string filename, bool where = true); //Execute the action

	void Undo(); //Undo the action

	void Redo(); //Redo the action

	~AddTriAction(); //Destructor
};

#endif