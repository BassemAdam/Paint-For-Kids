#ifndef ADD_HEXA_ACTION_H
#define ADD_HEXA_ACTION_H

#include "Action.h"
#include "..\Figures\CHexagon.h"

//Add Hexagon Action class
class AddHexaAction : public Action
{
private:
	Point P1; //Hexagon center
	GfxInfo HexaGfxInfo; //Hexagon graphics info
public:
	AddHexaAction(ApplicationManager* pApp); //Constructor

	virtual void ReadActionParameters(); //Reads hexagon parameters

	virtual void Execute(bool WillRecord, string filename, bool where = true); //Execute the action

	void Undo(); //Undo the action

	void Redo(); //Redo the action

	~AddHexaAction(); //Destructor
};

#endif