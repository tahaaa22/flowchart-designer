#include "AddValueAssign.h"
#include "..\Statements\ValueAssign.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddValueAssign::AddValueAssign(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddValueAssign::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
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



void AddValueAssign::Execute()
{
	ReadActionParameters();



	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	ValueAssign* pAssign = new ValueAssign(Corner, "", 0);


	pManager->AddStatement(pAssign);

}

