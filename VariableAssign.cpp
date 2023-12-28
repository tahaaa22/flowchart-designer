#include "VariableAssign.h"

#include <sstream>

using namespace std;

VariableAssign::VariableAssign(Point Lcorner, string LeftHS, double RightHS)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void VariableAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void VariableAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}

bool VariableAssign::isClicked(Point p)
{
	if (p.y <= LeftCorner.y + UI.ASSGN_HI && p.y >= LeftCorner.y && p.x <= LeftCorner.x + UI.ASSGN_WDTH && p.x >= LeftCorner.x)
	{
		return true;
	}

	return false;
}

void VariableAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void VariableAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << " = " << RHS;
	Text = T.str();
}
Point VariableAssign::getInlet()
{
	return Inlet;
}

Point VariableAssign::getOutlet()
{
	return Outlet;
}