#pragma once
#include "Actions/Action.h"
#include <fstream>
#include <iostream>
class Save :public Action
{
	string name;
public:
	ofstream out;
	Point P;
	Save(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();
};