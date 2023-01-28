#ifndef PLAY_RECORD
#define PLAY_RECORD

#include "Action.h"

class PlayRecordingAction :public Action {

private:

public:

	PlayRecordingAction(ApplicationManager* pApp);
	virtual void Execute(bool isBeingPlayed, string filename, bool where = true);
	virtual void ReadActionParameters();
	virtual void Undo();
	virtual void Redo();
	~PlayRecordingAction();
};

#endif
