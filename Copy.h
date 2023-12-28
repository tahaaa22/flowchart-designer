#pragma once
#include "Actions/Action.h"
class Copy : public Action
{
public:
	Copy(ApplicationManager* pAppManager);
	
	virtual void ReadActionParameters();
	virtual void Execute();
	
};