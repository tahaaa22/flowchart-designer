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
	pOut->ClearStatusBar();
	pOut->PrintMessage("deleting current selected item");
	pOut->ClearStatusBar();
	/*pOut->PrintMessage("select the statement to delete");
	pIn->GetPointClicked(s);
	pstate = pManager->GetStatement(s);
	if (!pstate)
	pconn = pManager->GetConnector(s);*/
}

void Delete::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pstate = pManager->GetSelectedStatement();
	if(!pstate)
		pconn = pManager->GetSelectedConnector();

	if (pstate != NULL)
	{
		
		if (pstate->getisconnected())
		{
			pManager->deletestat_conn(pstate);
			pManager->GetOutput()->PrintMessage("Statement Deleted");

		}
		else
		{
			pManager->deletestate(pstate);
			pManager->GetOutput()->PrintMessage("Statement Deleted");
		}
	}
	if (pconn != NULL)
	{
		pManager->deletecon(pconn);
		pManager->GetOutput()->PrintMessage("connector Deleted");
	}
	pOut->ClearDrawArea();
}
