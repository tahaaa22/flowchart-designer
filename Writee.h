#pragma once
#include "Statements/Statement.h"
class Writee : public Statement
{
	private:
		string text;
		Connector* pOutConn;	
		Point Inlet;	
		Point Outlet;	
		Point LeftCorner;

		virtual void UpdateStatementText();

	public:
		Writee(Point Lcorner, string TEXT = "WRITE X");
		void SetText(const string& L);
		virtual void Draw(Output* pOut) const;
		void SetID(int ID);
	};


