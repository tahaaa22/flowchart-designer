#include "Statement.h"

Statement::Statement()	
{ 
	//TODO: set the ID with a unique value
	Text = "";
	Selected = false;		
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

void Statement::setisconnected(bool connected)
{
	isconnected = connected;
}
bool Statement::getisconnected()
{
	return isconnected;
}
