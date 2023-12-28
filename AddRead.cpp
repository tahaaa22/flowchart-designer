#include "AddRead.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

#include <sstream>
AddRead::AddRead(ApplicationManager* pAppManager) :Action(pAppManager)
{}
void AddRead::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Read Statement: Click to add the statement");
	pIn->GetPointClicked(Position);
	pOut->PrintMessage("enter the text");
	text = pIn->GetString(pOut);
	pOut->ClearStatusBar();
}
void AddRead::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Read* pRead = new Read(Corner, "Read r");
	pRead->SetText(text);
	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()

	pManager->AddStatement(pRead); // Adds the created statement to application manger's statement list
}
