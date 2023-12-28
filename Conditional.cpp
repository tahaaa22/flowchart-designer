#include "Conditional.h"
#include <sstream>

using namespace std;

Conditional::Conditional(Point Lcorner, string LeftHS, double RightHS)
{
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

void Conditional::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void Conditional::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}

void Conditional::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawRoh(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}
void Conditional::SetID(int Id) {
	ID = Id++;
}

//This function should be called when LHS or RHS changes
void Conditional::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << " = " << RHS;
	Text = T.str();
}

bool Conditional::isClicked(Point p)
{
	if (p.y <= LeftCorner.y + UI.ASSGN_HI && p.y >= LeftCorner.y && p.x <= LeftCorner.x + UI.ASSGN_WDTH && p.x >= LeftCorner.x)
	{
		return true;
	}

	return false;
}
Point Conditional::getInlet()
{
	return Inlet;
}

Point Conditional::getOutlet()
{
	return Outlet;
}