#pragma once
#include "Actions/Action.h"
class Switch_sim : public Action
{
private:
	Point Position;
public:
	Switch_sim(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();


};