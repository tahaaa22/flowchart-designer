#include "AddWritee.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

#include <sstream>
AddWritee::AddWritee(ApplicationManager* pAppManager) :Action(pAppManager)
{}
void AddWritee::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Write Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}
void AddWritee::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Writee* pWritee = new Writee(Corner, "write e");
	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()

	pManager->AddStatement(pWritee); // Adds the created statement to application manger's statement list
}