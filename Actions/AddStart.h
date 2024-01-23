#pragma once
#include "Actions/Action.h"
#include "..\Statements\Start.h"
	class AddStart: public Action
	{
	private:
		Point Position;
		string text;
	public:
		AddStart(ApplicationManager* pAppManager);

		virtual void ReadActionParameters();

		virtual void Execute();

	};


