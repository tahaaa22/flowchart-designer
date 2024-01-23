#pragma once
#include "Actions/Action.h"
class Exit : public Action
{
private:
	Point Position;
public:
	Exit(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();

};