#include "Start.h"
#include <sstream>
#include <fstream>
Start::Start(Point Lcorner, string TEXT)
{
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

void Start::SetID(int Id) {
	ID = Id++;
}

void Start::Draw(Output* pOut) const 
{
	pOut->DrawStart(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}
bool Start::isClicked(Point p)
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


void Start::UpdateStatementText()
{
	ostringstream T;
	T << text;
	Text = T.str();
}


Point Start::getOutlet()
{
	return Outlet;
}

void Start::Save(ofstream& OutFile) {
	OutFile << "STRT " << ID << " " << (LeftCorner.x + UI.ASSGN_WDTH) / 2 << " " << (LeftCorner.y + UI.ASSGN_HI) / 2;
}
