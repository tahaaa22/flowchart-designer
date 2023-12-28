#include "Writee.h"
#include <sstream>
Writee::Writee(Point Lcorner, string TEXT ) {
	text = TEXT;
	UpdateStatementText();
	LeftCorner = Lcorner;
	pOutConn = NULL;	

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}
void Writee::SetText(const string& L) {
	text = L;
	UpdateStatementText();
}
void Writee::Draw(Output* pOut) const {
	pOut->DrawPol(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}
void Writee::SetID(int Id) {
	ID = Id++;
}
void Writee::UpdateStatementText()
{
	ostringstream T;
	T << text;
	Text = T.str();
}