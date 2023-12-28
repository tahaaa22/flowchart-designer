#include "Delete.h"
#include "ApplicationManager.h"
#include "Statements/Statement.h"

Delete::Delete(ApplicationManager* pAppManager): Action(pAppManager)
{}
void Delete::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Point s;
	Point c;
	pOut->ClearStatusBar();
	pOut->PrintMessage("select the statement to delete");
	pIn->GetPointClicked(s);
	pIn->GetPointClicked(c);
	pstate = pManager->GetStatement(s);
	pconn = pManager->GetConnector(c);
}

void Delete::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pstate != NULL)
	{
		pManager->deletestate(pstate);
		pManager->GetOutput()->PrintMessage("Statement Deleted");

	}
	if (pconn != NULL)
	{
		pManager->deletecon(pconn);
		pManager->GetOutput()->PrintMessage("connector Deleted");
	}
	pOut->ClearDrawArea();
}
