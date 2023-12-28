#pragma once
#include "Statements/Statement.h"
	class OperatorAssign : public Statement
	{
	private:
		string LHS;
		string RHS;

		Connector* pOutConn;
	
		Point Inlet;	
		Point Outlet;	

		Point LeftCorner;	//left corenr of the statement block.

		virtual void UpdateStatementText();

	public:
		OperatorAssign(Point Lcorner, string LeftHS = "", double RightHS = 0);

		void setLHS(const string& L);
		void setRHS(double R);
		virtual void Draw(Output* pOut) const;


	};


