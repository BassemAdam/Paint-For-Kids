#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "LoadAction.h"
class  ToDraw :public Action
{

public:

	ToDraw(ApplicationManager* pApp);



	void ReadActionParameters();

	void Execute(bool WillRecord, string filename, bool where = true);

	void Undo();

	void Redo();

	~ToDraw();
};