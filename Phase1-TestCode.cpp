
#include "HelperFn.h"
#include "GUI\Input.h"
#include "GUI\Output.h"


//This is a test code to test the Input and Output classes

int main()
{

	Point P;
	Point P1;
	Point P2;

	//Create Input and Output objects to test
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();

	/////////////////////////////////////////////////////////////////////////////////////
	//// TEST 0:	Testing the helper functions
	/////////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST0: Testing the helper functions");
	pIn->GetPointClicked(P);	//Wait for any click

	////////////
	//TODO: Add code here to 
	// 1- Read a (string) from the user --> just call the already impemented Input::GetString(...) fn
	// 2- Pass this string to IsValue(...) helper function 
	// 3- Print a message indicating its output (whether it's a value or not)
	// 4- -- REPEAT the same previous 3 steps to test: IsVariable(...) helper function
	// 5- -- REPEAT the same first 3 steps to test: ValueORVariable(...) helper function
	////////////
	pOut->PrintMessage("Enter a Double Value");
	string x;
	x = pIn->GetString(pOut);
	bool y;
	y = IsValue(x);
	if (y == true)
		pOut->PrintMessage("Input is a value");
	else
		pOut->PrintMessage("Input is an Invalid value");

	pIn->GetPointClicked(P);	//Wait for any click
	
	pOut->PrintMessage("Enter a variable name");
	string A;
	A = pIn->GetString(pOut);
	bool B;
	B = IsVariable(A);
	if (B == true)
		pOut->PrintMessage("Input is a variable");
	else
		pOut->PrintMessage("Input is an Invalid variable");

	pIn->GetPointClicked(P);	//Wait for any click
	
	pOut->PrintMessage("Testing ValueOrVariable");
	pOut->PrintMessage("Enter a Value or Variable");
	string c;
	c = pIn->GetString(pOut);
	OpType d;
	d = ValueOrVariable(c);
	if (d == VALUE_OP)
		pOut->PrintMessage("Input is a value");
	else if (d == VARIABLE_OP)
		pOut->PrintMessage("Input is a variable");
	else
		pOut->PrintMessage("Input is invalid");
	pIn->GetPointClicked(P);	//Wait for any click
	//Starting the input and output classes test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(P);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	Create The FULL Tool bar, the drawing area, the output bar and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	Drawing all the Statements with all possible states:
	//			Normal, highlighted, empty, filled with code
	//			Also drawing connectors
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any statement in any status, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click

	/// 2.1- Assignment statement test
	//Drawing assignment statements in all posible states

	pOut->PrintMessage("Drawing Simple Assignment statements in ALL STATES, Click to continue");

	//Drawing (normal) (empty) assignment statement --> STATE 1
	P.x = 100;	P.y = 100;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " = ");

	//Drawing (highlighted) (empty) assignment statement --> STATE 2
	P.x = 300;	P.y = 100;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " = ", true);

	//Drawing a resized empty assignment statement
	P.x = 100;	P.y = 200;
	pOut->DrawAssign(P, 80, UI.ASSGN_HI, " = ");

	//Drawing edited (normal) (non-empty) assignment statement --> STATE 3
	P.x = 100;	P.y = 300;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = 3000");

	//Drawing (highlighted) (non-empty) assignment statement --> STATE 4
	P.x = 300;	P.y = 300;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = 3000", true);

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	///2.2- Variable assignment & single operator assignment
	pOut->PrintMessage("Drawing other Assignment statements in ALL STATES, Click to continue");

	//Drawing (normal) (empty) assignment statement --> STATE 1
	P.x = 100;	P.y = 100;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " = ");

	//Drawing (highlighted) (empty) assignment statement --> STATE 2
	P.x = 300;	P.y = 100;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " = ", true);

	//Drawing a resized empty assignment statement
	P.x = 100;	P.y = 200;
	pOut->DrawAssign(P, 80, UI.ASSGN_HI, " = ");

	//Drawing edited (normal) (non-empty) assignment statement --> STATE 3
	P.x = 100;	P.y = 300;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "S = S + y");

	//Drawing (highlighted) (non-empty) assignment statement --> STATE 4
	P.x = 300;	P.y = 300;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "S = y ", true);

	//Note: for other type of assignment, you can use the same draw assignment function but passing a different text

	////////////
	//TODO: Add code to draw other types of assignment statements (Variable and Operator) here in ALL STATES
	////////////

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.3- Conditional statement test
	//Drawing Conditional statements in all posible states
	pOut->PrintMessage("Drawing Conditional Statement in ALL STATES, Click to continue");
	P.x = 100;	P.y = 100;
	pOut->DrawRoh(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " ");

	////////////
	//TODO: Add code to draw different (Conditional) statements here in ALL STATES
	////////////
	// 
	//Drawing (highlighted) (empty) assignment statement --> STATE 2
	P.x = 300;	P.y = 100;
	pOut->DrawRoh(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " ", true);

	P.x = 100;	P.y = 200;
	pOut->DrawRoh(P, 80, UI.ASSGN_HI, " "); //Drawing a resized empty assignment statement

	P.x = 100;	P.y = 300;
	pOut->DrawRoh(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "S>2");

	//Drawing (highlighted) (non-empty) assignment statement --> STATE 4
	P.x = 300;	P.y = 300;
	pOut->DrawRoh(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "S>4", true);


	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.4- Read statement test
	//Drawing Read statements in all posible states
	pOut->PrintMessage("Drawing Read Statement in ALL STATES, Click to continue");

	////////////
	//TODO: Add code to draw different (Read) statements here in ALL STATES
	////////////
	P.x = 100;	P.y = 100;
	pOut->DrawPol(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "");

	P.x = 300;	P.y = 100;
	pOut->DrawPol(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "", true);

	P.x = 100;	P.y = 200;
	pOut->DrawPol(P, 80, UI.ASSGN_HI, "");

	P.x = 100;	P.y = 300;
	pOut->DrawPol(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "read s");
	P.x = 300;	P.y = 300;
	pOut->DrawPol(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "read s", true);


	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.5- Write statement test
	//Drawing Write statements in all posible states
	pOut->PrintMessage("Drawing Write Statement in ALL STATES, Click to continue");

	////////////
	//TODO: Add code to draw different (Write) statements here in ALL STATES
	////////////
	P.x = 100;	P.y = 100;
	pOut->DrawPol(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " ");

	P.x = 300;	P.y = 100;
	pOut->DrawPol(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " ", true);

	P.x = 100;	P.y = 200;
	pOut->DrawPol(P, 80, UI.ASSGN_HI, " ");

	P.x = 100;	P.y = 300;
	pOut->DrawPol(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "write s");
	P.x = 300;	P.y = 300;
	pOut->DrawPol(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "write s", true);


	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();


	/// 2.6- Start & End statements test
	//Drawing Start & End statements in all posible states
	pOut->PrintMessage("Drawing Start & End Statements in ALL STATES, Click to continue");

	////////////
	//TODO: Add code to draw different (Start & End) statements here  in ALL STATES
	////////////
	P.x = 100;	P.y = 100;
	pOut->DrawStart(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "");

	P.x = 300;	P.y = 100;
	pOut->DrawStart(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "", true);

	P.x = 100;	P.y = 200;
	pOut->DrawStart(P, 80, UI.ASSGN_HI, "");

	P.x = 100;	P.y = 300;
	pOut->DrawStart(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "");
	P.x = 300;	P.y = 300;
	pOut->DrawStart(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "", true);

	P.x = 500;	P.y = 100;
	pOut->DrawEnd(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "");

	P.x = 700;	P.y = 100;
	pOut->DrawEnd(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "", true);

	P.x = 200;	P.y = 200;
	pOut->DrawEnd(P, 80, UI.ASSGN_HI, "");

	P.x = 500;	P.y = 300;
	pOut->DrawEnd(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "");
	P.x = 700;	P.y = 300;
	pOut->DrawEnd(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "", true);



	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();


	/// 2.7- Connector test
	//Drawing Connector in all posible states
	pOut->PrintMessage("Drawing Connector in Normal and Highlighted STATES, Click to continue");

	////////////
	//TODO: Add code to draw different (Connectors) here:  Normal and Highlighted
	////////////
	P.x = 100;	P.y = 100; P1.x = 100; P1.y = 200;
	pOut->Drawconnectors(P, P1);

	P.x = 100;	P.y = 250; P1.x = 200; P1.y = 250;
	pOut->Drawconnectors(P, P1);
	P.x = 200;	P.y = 400; P1.x = 100; P1.y = 400;
	pOut->Drawconnectors(P, P1);
	P.x = 350;	P.y = 100; P1.x = 400; P1.y = 100;
	P2.x = 400;	P2.y = 200;
	pOut->Drawconnector(P, P1, P2);

	//Drawing (highlighted) (empty) assignment statement --> STATE 2
	P.x = 200;	P.y = 100; P1.x = 200; P1.y = 200;
	pOut->Drawconnectors(P, P1, true);

	P.x = 100;	P.y = 300; P1.x = 200; P1.y = 300;
	pOut->Drawconnectors(P, P1,true);

	P.x = 200;	P.y = 450; P1.x = 100; P1.y = 450;
	pOut->Drawconnectors(P, P1,true);

	P.x = 250;	P.y = 100; P1.x = 300; P1.y = 100;
	P2.x = 300;	P2.y = 200;
	pOut->Drawconnector(P, P1, P2, true);


	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();



	/// 2.8- Draw String TEST
	//Drawing a String in a specific location
	pOut->PrintMessage("Drawing A String, Click to continue");

	//Note: the function of this drawing is already implemented in Output class , you only need to call it

	////////////
	//TODO: Add code to: 
	// 1- Get a String from the user --> using the already-implemented Input::GetString(...) fn
	// 2- Draw that string in location (400, 200) --> using the already-implemented Output::DrawString(...) fn
	////////////
	string M = pIn->GetString(pOut);

	pOut->DrawString(400, 200, M);


	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: Read strings and a value from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click

	pOut->PrintMessage("Testing Input ability to read strings, values, variables and operators");

	//////////
	//TODO: Add code here to 
	// 1- Read a (double value) from the user and print it
	double m = pIn->GetValue(pOut);
	pOut->DrawDouble(100,100,m);
	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();
	// 2- Read a (variable name) from the user and print it
	// 3- Read an (arithmatic operator) from the user and print it
	// 4- Read a (comparison operator) from the user and print it
	////////////

	/*2)*/ 	pOut->PrintMessage("enter a variable name");
	string var= pIn->GetVariable(pOut);
	pOut->DrawString(100, 100, var);
	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();


	/*3)*/ pOut->PrintMessage("enter an arithmatic operator");
	string op= pIn->GetArithOperator(pOut);
	pOut->DrawString(100, 100, op);
	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/*4)*/ pOut->PrintMessage("enter a comparison operator ");
	string cop= pIn->GetCompOperator(pOut);
	pOut->DrawString(100, 100, cop);
	




	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	////////////
	//TODO:  You must add a case for EACH action in the following (switch case)
	////////////
	////COMPLETE THE SWITCH CASE WITH ALL THE ACTIONS

	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case ADD_VALUE_ASSIGN:
			pOut->PrintMessage("Action: add value assignment statement , Click anywhere");
			break;

		case ADD_CONDITION:
			pOut->PrintMessage("Action: add conditional statement , Click anywhere");
			break;

		case ADD_CONNECTOR:
			pOut->PrintMessage("Action: add a connector , Click anywhere");
			break;

		case SELECT:
			pOut->PrintMessage("Action: select action, Click anywhere");
			break;


		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break;

		case DSN_TOOL:
			pOut->PrintMessage("Action: a click on the Design Tool Bar, Click anywhere");
			break;

		case SWITCH_SIM_MODE:
			pOut->PrintMessage("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->CreateSimulationToolBar(); // THIS TESTS Output::CreateSimulationToolBar() function //////
			break;

		case SWITCH_DSN_MODE:
			pOut->PrintMessage("Action: Switch to Design Mode, creating Design tool bar");
			pOut->CreateDesignToolBar();
			break;
		case ADD_START:
			pOut->PrintMessage("Action: add start, Click anywhere");
			break;
		case ADD_END:
			pOut->PrintMessage("Action: add end, Click anywhere");
			break;
		case ADD_VAR_ASSIGN:
			pOut->PrintMessage("Action: add variable assignment statement , Click anywhere");
			break;
		case ADD_OPER_ASSIGN:
			pOut->PrintMessage("Action: add operator assignment statement , Click anywhere");
			break;
		case ADD_READ:
			pOut->PrintMessage("Action: read statment, Click anywhere");
			break;
		case ADD_WRITE:
			pOut->PrintMessage("Action:  write statment, Click anywhere");
			break;
		case EDIT_STAT:
			pOut->PrintMessage("Action: edit statment, Click anywhere");
			break;
		case DEL:
			pOut->PrintMessage("Action: delete statment, Click anywhere");
			break;
		case COPY:
			pOut->PrintMessage("Action: copy, Click anywhere");
			break;
		case CUT:
			pOut->PrintMessage("Action: cut, Click anywhere");
			break;
		case PASTE:
			pOut->PrintMessage("Action: paste, Click anywhere");
			break;
		case SAVE:
			pOut->PrintMessage("Action: save, Click anywhere");
			break;
		case LOAD:
			pOut->PrintMessage("Action: load, Click anywhere");
			break;
		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the drawing area, Click anywhere");
			break;
		case OUTPUT_AREA:
			pOut->PrintMessage("Action: a click on the output area, Click anywhere");
			break;
		case VALIDATE:
			pOut->PrintMessage("Action: Validate action, Click anywhere");
			break;
		case RUN:
			pOut->PrintMessage("Action: Run action, Click anywhere");
			break;


		case EXIT:
			break;
		}
	} while (ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(P);


	delete pIn;
	delete pOut;
	return 0;
}

