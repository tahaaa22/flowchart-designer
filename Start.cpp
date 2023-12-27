#include "Start.h"
#include <sstream>
Start::Start(Point Lcorner, string TEXT) {
	text = TEXT;
	UpdateStatementText();
	LeftCorner = Lcorner;
	pOutConn = NULL;
	Outlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}
void Start::SetText(const string& L) {
	text = L;
	UpdateStatementText();
}
void Start::Draw(Output* pOut) const {
	pOut->DrawStart(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}
void Start::UpdateStatementText()
{
	ostringstream T;
	T << text;
	Text = T.str();
}

	