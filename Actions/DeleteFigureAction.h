#ifndef DELETE_FIGURE_ACTION_H
#define DELETE_FIGURE_ACTION_H

#include "Action.h"

//Delete Figure Action class
class DeleteFigureAction : public Action
{
public:
	DeleteFigureAction(ApplicationManager* pApp); //Constructor

	void ReadActionParameters();

	virtual void Execute(bool WillRecord, string filename, bool where = true); //Execute the action
	
	void Undo(); //Undo the action
	
	void Redo(); //Redo the action

	~DeleteFigureAction(); //Destructor
};

#endif