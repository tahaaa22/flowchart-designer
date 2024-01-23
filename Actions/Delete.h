#pragma once
#include "Actions\Action.h"
#include "ApplicationManager.h"
#include "Statements/Statement.h"
#include "..\Statements\Connector.h"
class Delete:public Action
{
private:
	Statement* pstate;
	Connector* pconn;
public:
	Delete(ApplicationManager* pAppManager);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};

