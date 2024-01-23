#include "Switch_sim.h"
#include "ApplicationManager.h"

Switch_sim::Switch_sim(ApplicationManager* pAppManager):Action(pAppManager)
{

}
void Switch_sim::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("switching to simulation ");


 }
void Switch_sim::Execute()
{

		Output* pOut = pManager->GetOutput();
		pOut->ClearStatusBar();
		pOut->CreateSimulationToolBar();

 }

