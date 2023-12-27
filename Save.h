#pragma once
#include "Actions/Action.h"
class Save: public Action
{
public:
	Save(ApplicationManager* pAppManager);
	void SaveAction();
	void Execute();
};

