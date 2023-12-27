#include "Select.h"
#include "..\flowcharts\ApplicationManager.h"

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
	ReadActionParameters();
	pManager->GetStatement(Position);


	
}

