#include "Paste.h"
#include "ApplicationManager.h"

Paste::Paste(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Paste::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Click anywhere to paste ");
	pIn->GetPointClicked(P);


}

void Paste::Execute() {
	ReadActionParameters();
	pManager->GetClipboard();


}