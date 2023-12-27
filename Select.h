#ifndef SELECT_H
#define SELECT_H

#include "Actions\Action.h"


class Select : public Action
{
private:
	
	Point Position;	//Position where the user clicks to add the stat.
	

public:
	Select(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

#endif