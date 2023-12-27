#include "AddEnd.h"
#include "ApplicationManager.h"
#include "End.h"
#include "GUI\input.h"
#include "GUI\Output.h"

#include <sstream>
AddEnd::AddEnd(ApplicationManager* pAppManager) :Action(pAppManager)
{}
void AddEnd::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("End Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}
void AddEnd::Execute()
{
	ReadActionParameters();

	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	End* pEnd = new End(Corner, "End");

	pManager->AddStatement(pEnd); 
}