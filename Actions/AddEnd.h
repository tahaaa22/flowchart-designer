#pragma once
#include "Actions/Action.h"
#include "End.h"
	class AddEnd : public Action
	{
	private:
		Point Position;
		string text;
	public:
		AddEnd(ApplicationManager* pAppManager);

		virtual void ReadActionParameters();

		virtual void Execute();

	};
