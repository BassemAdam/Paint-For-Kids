#ifndef UNDO_ACTION_H
#define UNDO_ACTION_H

#include "Action.h"

//Undo Action Class
class UndoAction :public Action
{
public:
	UndoAction(ApplicationManager* pApp); //Constructor

	virtual void ReadActionParameters();

	virtual void Execute(bool WillRecord, string filename, bool where = true); //Execute the action

	void Undo();

	void Redo();

	~UndoAction(); //Destructor
};

#endif