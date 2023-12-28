#pragma once
#include "Actions/Action.h"
class Copy : public Action
{
public:
	Copy(ApplicationManager* pAppManager);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
	void ReadActionParameters();
	void Execute();
};