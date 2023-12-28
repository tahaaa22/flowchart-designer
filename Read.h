#pragma once
#include "Statements/Statement.h"
class Read : public Statement
{
private:
	string text;
	Connector* pOutConn;
	Point Inlet;
	Point Outlet;
	Point LeftCorner;

	virtual void UpdateStatementText();

	public:
		Read(Point Lcorner, string TEXT = "Read X");
		void SetText(const string& L);
		virtual void Draw(Output* pOut) const;
		void SetID(int ID);

};

