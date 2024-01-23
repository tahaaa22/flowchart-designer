#pragma once
#include "Actions/Action.h"
#include "..\Statements\OperatorAssign.h"

	class AddOperatorAssign : public Action
	{
	private:
		string LHS;
		double RHS;
		Point Position;	

	public:
		AddOperatorAssign(ApplicationManager* pAppManager);
		virtual void ReadActionParameters();
		virtual void Execute();

	};

