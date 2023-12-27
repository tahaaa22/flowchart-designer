#include "AddConnector.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddConnector::AddConnector(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddConnector::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Connector : Click the scource statement to add the Connector");

	pIn->GetPointClicked(Position1);
	pOut->PrintMessage("Connector : Click the destination statement to add the Connector");

	pIn->GetPointClicked(Position2);

	pOut->ClearStatusBar();

	//TODO: Ask the user in the status bar to enter the LHS and set the data member

	//TODO: Ask the user in the status bar to enter the RHS and set the data member

	//Note: You should validate the LHS to be variable name and RHS to be a value
	//      Call the appropriate functions for this.
}



void AddConnector::Execute()
{
	ReadActionParameters();

	Statement* srcstat= pManager->GetStatement(Position1);
	Statement* endstat = pManager->GetStatement(Position2);


	Connector* pConn = new Connector(srcstat, endstat);

	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()

	pManager->AddConnector(pConn); // Adds the created statement to application manger's statement list
}


