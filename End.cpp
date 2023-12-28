#include "End.h"
#include <sstream>
#include <fstream>


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
bool End::isClicked(Point p)
{
	float radiusX = UI.ASSGN_WDTH / 2.0f;
	float radiusY = UI.ASSGN_HI / 2.0f;
	float centerX = LeftCorner.x + radiusX;
	float centerY = LeftCorner.y + radiusY;

	// Check if the mouse is inside the bounding box
	if (p.x < LeftCorner.x || p.x > LeftCorner.x + UI.ASSGN_WDTH || p.y < LeftCorner.y || p.y > LeftCorner.y + UI.ASSGN_HI)
	{
		return false;
	}

	// Check if the mouse is inside the ellipse equation
	float normalizedX = (p.x - centerX) / radiusX;
	float normalizedY = (p.y - centerY) / radiusY;
	return (normalizedX * normalizedX + normalizedY * normalizedY) <= 1.0f;
}


void End::UpdateStatementText()
{
	ostringstream T;
	T << text;
	Text = T.str();
}

Point End::getInlet()
{
	return Inlet;
}


void End::Save(ofstream& OutFile) {
	OutFile << "END " << ID << " " << (LeftCorner.x +UI.ASSGN_WDTH)/2 << " " << (LeftCorner.y + UI.ASSGN_HI) / 2;
}

