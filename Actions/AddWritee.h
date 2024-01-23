#pragma once
#include "Actions/Action.h"
#include "Writee.h"
class AddWritee : public Action
{
private:
	string text;
	Point Position;
public:
	AddWritee(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();

};

