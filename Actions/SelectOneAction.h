#ifndef ADD_SelectOneAction_H
#define ADD_SelectOneAction_H

#include "Action.h"


//Add Select One Action class
class SelectOneAction : public Action
{
private:
	Point P;
public:
	SelectOneAction(ApplicationManager* pApp);
	//Reads click parameters
	virtual void ReadActionParameters();
	//Selecting a figure
	virtual void Execute(bool WillRecord, string filename, bool where = true);
	void Undo();
	void Redo();
	~SelectOneAction();
};

#endif