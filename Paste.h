#pragma once
#include "Actions/Action.h"
class Paste : public Action
{
public:
	Point P;
	Paste(ApplicationManager* pAppManager);
	void ReadActionParameters();
	void Execute();
};