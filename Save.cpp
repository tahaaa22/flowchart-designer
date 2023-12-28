#include "Save.h"
#include "ApplicationManager.h"
#include <fstream>
Save::Save(ApplicationManager* pAppManager) :Action(pAppManager)
{}
void Save::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Enter the File name ");
	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearStatusBar();
	name = pIn->GetString(pOut);


}

void Save::Execute() {
	ReadActionParameters();
	pManager->SaveAll(out);
	out.open(name, ios::in);
}