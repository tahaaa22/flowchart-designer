#pragma once

#include "Actions/Action.h"
#include "..\Statements\Read.h"
	class AddRead : public Action
{
private:
	string text;
	Point Position;
public:
	AddRead(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();

};

