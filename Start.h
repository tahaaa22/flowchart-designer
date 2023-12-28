#pragma once
#include "Statements/Statement.h"
class Start : public Statement
{
	private:
		string text;
		Connector* pOutConn;
		Point Outlet;
		Point LeftCorner;

		virtual void UpdateStatementText();

	public:
		Start(Point Lcorner, string TEXT = "Start");
		virtual bool isClicked(Point p);
		void SetText(const string & L);
		virtual void Draw(Output * pOut) const;
		void SetID(int ID);
		Point getOutlet();
};

