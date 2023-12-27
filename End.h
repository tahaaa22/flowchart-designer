#pragma once
#include "Statements/Statement.h"
	class End : public Statement
	{
	private:
		string text;
		Connector* pOutConn;
		Point Inlet;
		Point LeftCorner;

		virtual void UpdateStatementText();

	public:
		End(Point Lcorner, string TEXT = "START");
		void SetText(const string& L);
		virtual void Draw(Output* pOut) const;
	};


