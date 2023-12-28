#include "AddStart.h"
#include "ApplicationManager.h"
#include "Start.h"
#include "GUI\input.h"
#include "GUI\Output.h"

#include <sstream>
AddStart::AddStart(ApplicationManager* pAppManager) :Action(pAppManager)
{}
void AddStart::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("Start Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}
void AddStart::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Start* pStart = new Start(Corner, "Start");
	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()

	pManager->AddStatement(pStart); // Adds the created statement to application manger's statement list
}