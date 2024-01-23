#pragma once
#include "Statements/Statement.h"


class VariableAssign : public Statement
{
private:
	string LHS;
	string RHS;

	Connector* pOutConn;	//Value Assignment Stat. has one Connector to next statement
	//Each statement type in flowchart has a predefined number of (output) connectors
	//For example, conditional statement always has 2 output connectors

	//Note: We don't need to keep track with input connectors
	//      Whenever we want to iterate on all statements of the flowchart
	//      we will begin with Start statement then its output connector
	//      then the connector's destination statement and so on (follow the connectors)

	Point Inlet;	//A point where connections enters this statement 
	//It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
	//It's used as the (Start) point of the (Output) connector

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	VariableAssign(Point Lcorner, string LeftHS = "", double RightHS = 0);

	void setLHS(const string& L);
	void setRHS(double R);
	virtual void Draw(Output* pOut) const;
	bool isClicked(Point p);
	Point getInlet();
	Point getOutlet();
	void Save(ofstream& OutFile);
}; 
