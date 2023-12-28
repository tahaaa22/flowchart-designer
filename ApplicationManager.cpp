#include "ApplicationManager.h"
#include "AddWritee.h"
#include "AddRead.h"
#include "AddStart.h"
#include "AddConditional.h"
#include "AddEnd.h"
#include "AddVariableAssign.h"
#include "AddOperatorAssign.h"
#include "Actions\AddValueAssign.h"
#include "Actions\AddValueAssign.h"
#include "GUI\Input.h"
#include "GUI\Output.h"



//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0; 
	pSelectedStat = NULL;	//no Statement is selected yet
	pSelectedCon = NULL;	//no Statement is selected yet
	pClipboard = NULL;
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//


ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
		case ADD_VALUE_ASSIGN:
			pAct = new AddValueAssign(this);
			break;

		case ADD_WRITE:
			pAct = new AddWritee(this);
			break;

		case ADD_READ:
			pAct = new AddRead(this);
			break;

		case ADD_Start:
			pAct = new AddStart(this);
			break; 

		case ADD_END:
			pAct = new AddEnd(this);
			break;

		case ADD_VAR_ASSIGN:
			pAct = new AddVariableAssign(this);
			break;
		case ADD_OPER_ASSIGN:
			pAct = new AddOperatorAssign(this);
			break;

		case ADD_CONDITION:
			pAct = new AddConditional(this);

			break;

		case ADD_CONNECTOR:
			pAct = new AddnewConnector(this);
			break;

		case SELECT:
			pAct = new Select(this);

			break;

		case EXIT:
			///create Exit Action here
			
			break;
		
		case STATUS:
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}



//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//


//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
	
}

////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[i]->isClicked(P))
		{
			return (StatList[i]);
		}

	}
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL


	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities

	return NULL;
}

void ApplicationManager::AddConnector(Connector* pConn)
{
	if (ConnCount < MaxCount)
		ConnList[ConnCount++] = pConn;
}

Connector* ApplicationManager::GetConnector(Point P) const
{
	for (int i = 0; i < ConnCount; i++)
	{
		if (ConnList[i]->isClicked(P))
		{
			return (ConnList[i]);
		}
	}
	return nullptr;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}

Connector* ApplicationManager::GetSelectedConnector() const
{
	return pSelectedCon;
}

void ApplicationManager::SetSelectedConnector(Connector* pConn)
{
	pSelectedCon = pConn;
}


////////////////////////////////////////////////////////////////////////////////////
//Returns the Clipboard
Statement *ApplicationManager::GetClipboard() const
{	return pClipboard;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the Clipboard
void ApplicationManager::SetClipboard(Statement *pStat)
{	pClipboard = pStat;	}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//


//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();

	//Draw all statements
	for(int i=0; i<StatCount; i++)
		StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::deletestate(Statement* state)
{
	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[i] == state) {
			delete StatList[i];
			StatList[i] = StatList[StatCount - 1];

	      }

    }
}
void ApplicationManager::deletecon(Connector* con)
{
	for (int i = 0; i < ConnCount; i++)
	{
		if (ConnList[i] == con) {
			delete ConnList[i];
			ConnList[i] = ConnList[ConnCount - 1];
		}

	}
}
void ApplicationManager::deletecon(Connector* con)
{

}
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	
}
