#include "AddConnector.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"



//constructor: set the ApplicationManager pointer inside this action
AddnewConnector::AddnewConnector(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddnewConnector::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Connector : Click the scource statement to add the Connector");

	pIn->GetPointClicked(Position1);
	pOut->PrintMessage("Connector : Click the destination statement to add the Connector");

	pIn->GetPointClicked(Position2);

	pOut->ClearStatusBar();

}

void AddnewConnector::Execute()
{
	ReadActionParameters();

	Statement* srcstat= pManager->GetStatement(Position1);
	Statement* endstat = pManager->GetStatement(Position2);


	Connector* pConn = new Connector(srcstat, endstat);
	pManager->AddConnector(pConn); // Adds the created statement to application manger's statement list
}


