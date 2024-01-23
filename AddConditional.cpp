#include "AddConditional.h"
#include "Conditional.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddConditional::AddConditional(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddConditional::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("conditional Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("enter a value for left hand side ");
	LHS = pIn->GetVariable(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("enter a value for right hand side");
	RHS = pIn->GetValue(pOut);
	pOut->ClearStatusBar();

}

void AddConditional::Execute()
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Conditional* pCon = new Conditional(Corner, "", 0);
	pCon->setLHS(LHS);
	pCon->setRHS(RHS);
	pManager->AddStatement(pCon);

}

