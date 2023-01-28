#ifndef EXIT_ACTION_H
#define EXIT_ACTION_H

#include "Action.h"

//Exit Action class
class ExitAction :public Action
{
public:
	ExitAction(ApplicationManager* pApp);//Constructor

	virtual void ReadActionParameters();

	virtual void Execute(bool WillRecord, string filename, bool where); //Execute the action

	void Undo();

	void Redo();

	~ExitAction(); //Destructor
};

#endif