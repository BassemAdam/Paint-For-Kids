#ifndef TO_PLAY_H
#define TO_PLAY_H
#include "Action.h"
#include"SaveAction.h"

class SwitchToPlayAction :public Action {

private:

public:

	SwitchToPlayAction(ApplicationManager* pApp);

	virtual void Execute(bool WillRecord, string filename, bool where = true);
	virtual void ReadActionParameters();
	virtual void Undo();
	virtual void Redo();
	~SwitchToPlayAction();
};









#endif