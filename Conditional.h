#pragma once
#include "Statements/Statement.h"
class Conditional : public Statement
{
	private:
		string LHS;	
		double RHS;	
		Connector* pOutConn;	
		Point Inlet;	
		Point Outlet;	
		
		Point LeftCorner;

		virtual void UpdateStatementText();

	public:
		Conditional(Point Lcorner, string LeftHS = "", double RightHS=0);
		bool isClicked(Point p);
		void setLHS(const string& L);
		void setRHS(double R);
		void SetID(int ID);
		virtual void Draw(Output* pOut) const;
		Point getInlet();
		Point getOutlet();
	};


