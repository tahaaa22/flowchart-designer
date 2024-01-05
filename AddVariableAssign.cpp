#include "AddVariableAssign.h"
#include "ApplicationManager.h"
#include "VariableAssign.h"
#include "GUI\input.h"
#include "GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddVariableAssign::AddVariableAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddVariableAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Variable Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("enter a variable for left hand side ");
	LHS = pIn->GetVariable(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("enter a value for right hand side");
	RHS = pIn->GetValue(pOut);
	pOut->ClearStatusBar();

}

void AddVariableAssign::Execute()
{
	ReadActionParameters();
	
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	VariableAssign* pVariable = new VariableAssign(Corner, "", 0);
	pVariable->setLHS(LHS);
	pVariable->setRHS(RHS);
	
	pManager->AddStatement(pVariable);
		
}
