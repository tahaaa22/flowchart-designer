#pragma once
#include "Actions/Action.h"
#include <fstream>
#include <iostream>
class Load : public Action
{
public:
	ifstream in;
	Point P;
	Load(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();

};