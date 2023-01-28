#ifndef Toggle_Mute_ACTION_H
#define Toggle_Mute_ACTION_H

#include "Action.h"

//Toggle Mute Action Class
class ToggleMuteAction :public Action
{
public:
	ToggleMuteAction(ApplicationManager* pApp); //Constructor

	virtual void ReadActionParameters();

	virtual void Execute(bool WillRecord, string filename, bool where = true); //Execute the action

	void Undo();

	void Redo();

	~ToggleMuteAction(); //Destructor
};

#endif