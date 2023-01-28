#ifndef REDO_ACTION_H
#define REDO_ACTION_H

#include "Action.h"

//Redo Action Class
class RedoAction :public Action
{
public:
	RedoAction(ApplicationManager* pApp); //Constructor

	virtual void ReadActionParameters();

	virtual void Execute(bool WillRecord, string filename, bool where = true); //Execute the action

	void Undo();

	void Redo();

	~RedoAction(); //Destructor
};

#endif