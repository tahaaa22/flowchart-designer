#include "Copy.h"
#include "ApplicationManager.h"
Copy::Copy(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Copy::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Point s;

	pOut->PrintMessage("copied current selected item");

	
}

 void Copy::Execute()
{
	 Output* pOut = pManager->GetOutput();
	 ReadActionParameters();
	Statement* statptr = pManager->GetSelectedStatement();
	pManager->SetClipboard(statptr);
}
