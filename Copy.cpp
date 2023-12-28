#include "Copy.h"
#include "ApplicationManager.h"
Copy::Copy(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Copy::ReadActionParameters() {

}

void Copy::Execute() {
	Statement* statptr = pManager->GetSelectedStatement();
	pManager->SetClipboard(statptr);
}
