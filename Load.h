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
	//get data mn file to set biha data members
	//load all f application manager class to call all load functions from all classes (statements (readd, write, end ,start,...)
	// here we need to load and draw it  
	// if conditions to check the type of statement check line 49 in add value assign
	//call load all file name

};