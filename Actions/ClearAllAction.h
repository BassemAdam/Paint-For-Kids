#ifndef CLEAR_ALL_ACTION_H
#define CLEAR_ALL_ACTION_H

#include "Action.h"

//Clear All Action Class
class ClearAllAction :public Action
{
public:
	ClearAllAction(ApplicationManager* pApp); //Constructor

	virtual void ReadActionParameters();

	virtual void Execute(bool WillRecord, string filename, bool where); //Execute the action

	void Undo();

	void Redo();

	~ClearAllAction(); //Destructor
};

#endif