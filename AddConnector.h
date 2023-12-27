
#include "Actions\Action.h"
#include "Connector.h"

class AddConnector : public Action
{
private:
	

	Point Position1;	//Position where the user clicks to add the stat.
	Point Position2;	//Position where the user clicks to add the stat.

	

public:
	AddConnector(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

