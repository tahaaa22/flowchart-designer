#pragma once
#include "Actions\Action.h"

class AddnewConnector : public Action
{
private:
	Point Position1;	//Position where the user clicks to add the stat.
	Point Position2;	//Position where the user clicks to add the stat.


public:
	AddnewConnector(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

