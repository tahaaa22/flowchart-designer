#pragma once
#include "Actions/Action.h"
class Copy : public Action
{
public:
	Copy(ApplicationManager* pAppManager);
	void Execute();
};