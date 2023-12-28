#pragma once
#include "Actions/Action.h"
class Switch_design : public Action
{
private:
	Point Position;
public:
	Switch_design(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();


};