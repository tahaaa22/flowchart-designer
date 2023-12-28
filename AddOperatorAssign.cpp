#include "AddOperatorAssign.h"
#include "OperatorAssign.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddOperatorAssign::AddOperatorAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddOperatorAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Value Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("enter a value for left hand side ");
	LHS = pIn->GetValue(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("enter a value for right hand side");
	RHS = pIn->GetValue(pOut);
	pOut->ClearStatusBar();

}



void AddOperatorAssign::Execute()
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	OperatorAssign* pAssign = new OperatorAssign(Corner, "", 0);


	pManager->AddStatement(pAssign);

}
