#include "Exit.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"
Exit::Exit(ApplicationManager* pAppManager) :Action(pAppManager)
{

}
void Exit::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Exit Statement: Click again to Exit");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

}
void Exit::Execute()
{
	ReadActionParameters();

}