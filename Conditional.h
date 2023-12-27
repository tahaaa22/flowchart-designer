#pragma once
#include "Statements/Statement.h"
class Conditional : public Statement
{
	private:
		string LHS;	//Left Handside of the assignment (name of a variable)
		double RHS;	//Right Handside (Value)
		Connector* pOutConn;	
		Point Inlet;	
		Point Outlet;	

		Point LeftCorner;

		virtual void UpdateStatementText();

	public:
		Conditional(Point Lcorner, string LeftHS = "", double RightHS=0);

		void setLHS(const string& L);
		void setRHS(double R);

		virtual void Draw(Output* pOut) const;

	};


