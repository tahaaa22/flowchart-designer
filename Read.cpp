#include "Read.h"
#include <sstream>
Read::Read(Point Lcorner, string TEXT) {
	text = TEXT;
	UpdateStatementText();
	LeftCorner = Lcorner;
	pOutConn = NULL;

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}
void Read::SetText(const string& L) {
	text = L;
	UpdateStatementText();
}
void Read::Draw(Output* pOut) const {
	pOut->DrawPol(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}
void Read::SetID(int Id) {
	ID = Id++;
}
void Read::UpdateStatementText()
{
	ostringstream T;
	T << text;
	Text = T.str();
}
bool Read::isClicked(Point p)
{
	if (p.y <= LeftCorner.y + UI.ASSGN_HI && p.y >= LeftCorner.y && p.x <= LeftCorner.x + UI.ASSGN_WDTH && p.x >= LeftCorner.x)
	{
		return true;
	}

	return false;
}
Point Read::getInlet()
{
	return Inlet;
}

Point Read::getOutlet()
{
	return Outlet;
}