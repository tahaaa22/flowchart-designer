

#include "Input.h" 

#include "Output.h" 





Input::Input(window* pW)

{

	pWind = pW; //point to the passed window 

}



void Input::GetPointClicked(Point& P) const

{

	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click 

}



string Input::GetString(Output* pO) const

{

	string Label;

	char Key;

	while (1)

	{

		pWind->WaitKeyPress(Key);

		if (Key == 27)	//ESCAPE key is pressed 

			return "";	//returns nothing as user has cancelled label 

		if (Key == 13)	//ENTER key is pressed 

			return Label;

		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed 

			Label.resize(Label.size() - 1);

		else

			Label += Key;

		if (pO)

			pO->PrintMessage(Label);

	}

}



string Input::GetVariable(Output* pO) const
{
	/*variable name*/
	string varname;
	char key;
	bool valid2 =false;
	while (1)
	{
		pWind->WaitKeyPress(key);
		bool valid = IsVariable(varname);
		if (key == 27)	//ESCAPE key is pressed 
		{
			return "";	//returns nothing as user has cancelled variable name 
		}
		else if (key == 13 && (varname.size() >= 1) && valid)	//ENTER key is pressed 
		{
			return varname;
		}
		else if ((key == 8) && (varname.size() >= 1))
		{
			varname.resize(varname.size() - 1); // Remove the last character 
		}
		else
		{
			varname += key;
			valid2 = IsVariable(varname);
		}
		if(!valid2)
			varname.resize(varname.size() - 1);

		if (pO)
		{
			pO->PrintMessage(varname); // Display the current variable name 
		}
	}
}



string Input::GetArithOperator(Output* pO) const
{
	/*arithmatic operator*/
	char Op;
	string stOp;
	while (1)
	{
		pWind->WaitKeyPress(Op);
		if (Op == 13 && (stOp.size() >= 1))	//ENTER key is pressed 
		{
			return stOp;
		}
		if (Op == 27)	//ESCAPE key is pressed 
		{
			return "";	//returns nothing as user has cancelled arithmatic operator 
		}
		if (Op == '+' || Op == '-' || Op == '*' || Op == '/')
		{
			
			stOp += Op;
		}
		if (pO)
		{
			pO->PrintMessage(stOp); // Display the current variable name 
		}
	}

}



string Input::GetCompOperator(Output* pO) const
{
	/*comparison operator*/
	char compOp;
	string wholeop;
	while (1)
	{
		pWind->WaitKeyPress(compOp);
		
		if (compOp == 27)	//ESCAPE key is pressed 
		{
			return "";	//returns nothing as user has cancelled comparison operator 
		}
		if (compOp == '=' || compOp == '!' || compOp == '<' || compOp == '>')
		{
			char nextkey;
			wholeop += compOp;
			pWind->WaitKeyPress(nextkey);
			if (nextkey == 13)	//ENTER key is pressed 
			{
				if (pO)
				{
					pO->PrintMessage(wholeop); // Display the current variable name 
					return wholeop;
				}
				
			}
			else if ((wholeop == "=" && nextkey == '=') || (wholeop == "<" && nextkey == '=') || (wholeop == ">" && nextkey == '=') || (wholeop == "!" && nextkey == '='))
			{
				wholeop += nextkey;
				// Return valid comparison operator 
			}
		}
		if (pO)
		{
			pO->PrintMessage(wholeop); // Display the current variable name 
			return wholeop;
		}


	}

}





double Input::GetValue(Output* pO) const	// Reads a double value from the user  

{

	///TODO: add code to read a double value from the user and assign it to D 



	double D = 0;



	//This function should make any needed validations on the entered text  

	// to make sure it is a double value (e.g. 12.5, -12.5, -23, -23., -23.0 …etc.). 



	pO->PrintMessage("Please enter a value");



	//Read a double value from the user 



	return D;

}





ActionType Input::GetUserAction() const

{

	//This function reads the position where the user clicks to determine the desired action 



	int x, y;

	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click 



	if (UI.AppMode == DESIGN)	//application is in design mode 

	{

		//[1] If user clicks on the Toolbar 

		if (y >= 0 && y < UI.ToolBarHeight)

		{

			//Check whick Menu item was clicked 

			//This assumes that menu items are lined up horizontally 

			int ClickedItem = (x / UI.MenuItemWidth);

			//Divide x coord of the point clicked by the menu item width (int division) 

			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on 

			switch (ClickedItem)

			{

			case ITM_START: return ADD_START;

			case ITM_END: return ADD_END;

			case ITM_VALUE_ASSIGN: return ADD_VALUE_ASSIGN;

			case ITM_VAR_ASSIGN: return ADD_VAR_ASSIGN;

			case ITM_OPER_ASSIGN: return ADD_OPER_ASSIGN;

			case ITM_COND: return ADD_CONDITION;

			case ITM_READ: return ADD_READ;

			case ITM_WRITE: return ADD_WRITE;



			case ITM_CONNECTOR: return ADD_CONNECTOR;



			case ITM_SELECT: return SELECT;

			//case ITM_EDIT_STAT: return EDIT_STAT;



			case ITM_DEL: return DEL;

			case ITM_COPY: return COPY;

			case ITM_CUT: return CUT;

			case ITM_PASTE: return PASTE;



			case ITM_SAVE: return SAVE;

			case ITM_LOAD: return LOAD;



			case ITM_SWITCH_SIM_MODE: return SWITCH_SIM_MODE;



			case ITM_EXIT: return EXIT;



			default: return DSN_TOOL;

			}

		}



		//[2] User clicks on the drawing area 

		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)

		{

			if (x <= UI.DrawingAreaWidth)

				return DRAWING_AREA;

			else

				return OUTPUT_AREA;

		}



		//[3] User clicks on the status bar 

		return STATUS;

	}

	else	//Application is in Simulation mode 

	{

		if (y >= 0 && y < UI.ToolBarHeight)

		{

			//Check whick Menu item was clicked 

			//This assumes that menu items are lined up horizontally 

			int ClickedItem = (x / UI.MenuItemWidth);

			//Divide x coord of the point clicked by the menu item width (int division) 

			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on 

			switch (ClickedItem)

			{

			case ITM_VALIDATE: return VALIDATE;

			case ITM_RUN: return RUN;

			case ITM_SWITCH_DSN_MODE: return SWITCH_DSN_MODE;



			}

		}

		//[2] User clicks on the drawing area 

		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)

		{

			if (x <= UI.DrawingAreaWidth)

				return DRAWING_AREA;

			else

				return OUTPUT_AREA;

		}

		// TODO: This should be changed after creating the compelete simulation bar  

		return STATUS;

	}



}





Input::~Input()

{

}

