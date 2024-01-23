#include "Switch_design.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"


Switch_design::Switch_design(ApplicationManager* pAppManager) :Action(pAppManager)
{

}

void Switch_design::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("switching to design");

	


}
void Switch_design::Execute()
{
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->ClearOutputBar();
	pOut->CreateDesignToolBar();


}