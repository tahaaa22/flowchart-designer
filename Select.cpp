#include "Select.h"
#include "ApplicationManager.h"

//constructor: set the ApplicationManager pointer inside this action
Select::Select(ApplicationManager* pAppManager):Action(pAppManager)
{}

void Select::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("click to select the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	
}

void Select::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	Statement* statptr = pManager->GetStatement(Position);
	Connector* connptr = pManager->GetConnector(Position);
	
	if (statptr != NULL)
	{
		if ((pManager->GetSelectedStatement()) == NULL)
		{
			statptr->SetSelected(true);
			statptr->Draw(pOut);
			pManager->SetSelectedStatement(statptr);
		}
		else if (statptr == (pManager->GetSelectedStatement()))
		{
			statptr->SetSelected(false);
			statptr->Draw(pOut);
			pManager->SetSelectedStatement(NULL);
		}
		else
		{
			pManager->GetSelectedStatement()->SetSelected(false);
			pManager->GetSelectedStatement()->Draw(pOut);
			statptr->SetSelected(true);
			statptr->Draw(pOut);
			pManager->SetSelectedStatement(statptr);
		}

	}

	if (connptr != NULL)
	{
		if ((pManager->GetSelectedConnector()) == NULL)
		{
			connptr->SetSelected(true);
			connptr->Draw(pOut);
			pManager->SetSelectedConnector(connptr);
		}
		else if (connptr == (pManager->GetSelectedConnector()))
		{
			connptr->SetSelected(false);
			connptr->Draw(pOut);
			pManager->SetSelectedConnector(NULL);
		}
		else
		{
			pManager->GetSelectedConnector()->SetSelected(false);
			pManager->GetSelectedConnector()->Draw(pOut);
			connptr->SetSelected(true);
			connptr->Draw(pOut);
			pManager->SetSelectedConnector(connptr);
		}

	}


		/*if ((pManager->GetSelectedStatement()) == NULL)
		{
			statptr->SetSelected(true);
			statptr->Draw(pOut);
			pManager->SetSelectedStatement(statptr);
		}
		else if(statptr== (pManager->GetSelectedStatement()))
		{
			statptr->SetSelected(false);
			statptr->Draw(pOut);
		}*/

	
	
	
}

