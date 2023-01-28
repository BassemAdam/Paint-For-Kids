#ifndef START_RECORD
#define START_RECORD

#include "Action.h"

class StartRecordingAction :public Action {

private:

public:

	StartRecordingAction(ApplicationManager* pApp);

	virtual void Execute(bool isBeingPlayed, string filename, bool where = true);
	virtual void ReadActionParameters();
	virtual void Undo();
	virtual void Redo();
	~StartRecordingAction();
};

#endif

