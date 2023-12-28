#include "Paste.h"
#include "ApplicationManager.h"
#include "Statements\ValueAssign.h"
#include"Conditional.h"
#include "End.h"
#include "Read.h"
#include "Start.h"
#include "VariableAssign.h"
#include "Writee.h"
#include "OperatorAssign.h"

Paste::Paste(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Paste::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Click anywhere to paste ");
	pIn->GetPointClicked(P);


}

void Paste::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	Statement* state = pManager->GetClipboard();
	if (ValueAssign* s = dynamic_cast<ValueAssign*>(state))
	{
		ValueAssign* vs = new ValueAssign(P, "", 0);
		pManager->AddStatement(vs);
	}

	if (End* destination = dynamic_cast<End*>(state))
	{
		End* vs = new End(P, "Start");
		pManager->AddStatement(vs);
	}
	

	if (Conditional* source = dynamic_cast<Conditional*>(state))
	{
		Conditional* vs = new Conditional(P, "", 0);
		pManager->AddStatement(vs);
	}

	if (OperatorAssign* source = dynamic_cast<OperatorAssign*>(state))
	{
		OperatorAssign* vs = new OperatorAssign(P, "", 0);
		pManager->AddStatement(vs);
	}


	if (Read* source = dynamic_cast<Read*>(state))
	{
		Read* vs = new Read(P, "Read X");
		pManager->AddStatement(vs);
	}

	if (VariableAssign* source = dynamic_cast<VariableAssign*>(state))
	{
		VariableAssign* vs = new VariableAssign(P, "", 0);
		pManager->AddStatement(vs);
	}


	if (Writee* source = dynamic_cast<Writee*>(state))
	{
		Writee* vs = new Writee(P, "WRITE X");
		pManager->AddStatement(vs);
	}


}