#include "End.h"
#include <sstream>
End::End(Point Lcorner, string TEXT) {
	text = TEXT;
	UpdateStatementText();
	LeftCorner = Lcorner;
	pOutConn = NULL;

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;
}
void End::SetText(const string& L) {
	text = L;
	UpdateStatementText();
}
void End::Draw(Output* pOut) const {
	pOut->DrawEnd(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}
void End ::SetID(int Id) {
	ID = Id++;
}
void End::UpdateStatementText()
{
	ostringstream T;
	T << text;
	Text = T.str();
}