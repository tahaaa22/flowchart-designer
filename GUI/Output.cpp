#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1200;
	UI.height = 620;
	UI.wx = 15;
	UI.wy =15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 60;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);
	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode
	
	//fill the tool bar 
		
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem
	string MenuItemImages[DSN_ITM_CNT];
	MenuItemImages[ITM_START] = "images\\oval.jpg";
	MenuItemImages[ITM_END] = "images\\ovalE.jpg";
	MenuItemImages[ITM_VALUE_ASSIGN] = "images\\Assign.jpg";
	MenuItemImages[ITM_VAR_ASSIGN] = "images\\variable.jpg";
	MenuItemImages[ITM_OPER_ASSIGN] = "images\\operator.jpg";
	MenuItemImages[ITM_COND] = "images\\Condition.jpg";
	MenuItemImages[ITM_READ] = "images\\Read.jpg";
	MenuItemImages[ITM_WRITE] = "images\\write.jpg";
	MenuItemImages[ITM_CONNECTOR] = "images\\arrow.jpg"; 
	MenuItemImages[ITM_SELECT] = "images\\select.jpg";
	MenuItemImages[ITM_SAVE] = "images\\save 1.jpg";
	MenuItemImages[ITM_CUT] = "images\\cut.jpg";
	MenuItemImages[ITM_COPY] = "images\\copy.jpg";
	MenuItemImages[ITM_PASTE] = "images\\paste.jpg";
	MenuItemImages[ITM_DEL] = "images\\delete.jpg";
	MenuItemImages[ITM_EDIT] = "images\\edit.jpg";
	MenuItemImages[ITM_LOAD] = "images\\load.jpg";
	MenuItemImages[ITM_SWITCH_SIM_MODE] = "images\\switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list


	//Draw menu item one image at a time
	for(int i=0; i<DSN_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{
	
	UI.AppMode = SIMULATION;	//Simulation Mode
	string Images[SIM_ITM_CNT];
	Images[ITM_VALIDATE] = "images\\validate.jpg";
	Images[ITM_RUN] = "images\\run.jpg";
	Images[ITM_SWITCH_DSN_MODE] = "images\\switch.jpg";
	Images[ITM_WHITE1] = "images\\WHITE2.jpg";
	Images[ITM_WHITE2] = "images\\WHITE2.jpg";
	Images[ITM_WHITE3] = "images\\WHITE2.jpg";
	Images[ITM_WHITE4] = "images\\WHITE2.jpg";
	Images[ITM_WHITE5] = "images\\WHITE2.jpg";
	Images[ITM_WHITE6] = "images\\WHITE2.jpg";
	Images[ITM_WHITE7] = "images\\WHITE2.jpg"; 
	Images[ITM_WHITE8] = "images\\WHITE2.jpg";
	Images[ITM_WHITE9] = "images\\WHITE2.jpg";
	Images[ITM_WHITE10] = "images\\WHITE2.jpg";
	Images[ITM_WHITE11] = "images\\WHITE2.jpg";
	Images[ITM_WHITE12] = "images\\WHITE2.jpg";
	Images[ITM_WHITE13] = "images\\WHITE2.jpg";
	Images[ITM_WHITE14] = "images\\WHITE2.jpg";
	Images[ITM_WHITE15] = "images\\WHITE2.jpg";
	Images[ITM_EXIT1] = "images\\EXIT.jpg";
	///TODO: add code to create the simulation tool bar
	//Draw menu item one image at a time
	for (int i = 0; i < SIM_ITM_CNT; i++)
		pWind->DrawImage(Images[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
void Output::DrawDouble(const int iX, const int iY, const double dNumber) {
	pWind->SetPen(BLACK, 2);
	pWind->DrawDouble(iX, iY, dNumber);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);
	
		
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/4, Left.y + height/4, Text);
}
void Output::DrawStart(Point left, int width, int height, string Text, bool selected)
{
	if (selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);

	pWind->DrawEllipse(left.x, left.y, left.x + width, left.y + height);

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(left.x + width / 2.5, left.y + height / 4, "Start");
}
void Output::DrawEnd(Point left, int width, int height, string Text, bool selected)
{
	if (selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);

	pWind->DrawEllipse(left.x, left.y, left.x + width, left.y + height);

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(left.x + width / 2.5, left.y + height / 4, "End");
}
void Output::DrawRoh(Point left, int width, int height, string text, bool selected) {
	if (selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);
	const int iVertices = 4;
	const int aX[4] = { left.x,left.x + (width / 2),left.x + width ,left.x + (width / 2) };
	const int aY[4] = { left.y , left.y + (height / 2), left.y, left.y - (height / 2) };
	pWind->DrawPolygon(aX, aY, 4);
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(left.x + width / 2.5, left.y - (height / 4), text);
}
void Output::DrawPol(Point left, int width, int height, string text, bool selected)
{
	if (selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);
	const int iVertices = 4;
	const int aX[4] = { left.x,left.x + width ,left.x + width - (0.2 * width), left.x - (0.2 * width) };
	const int aY[4] = { left.y , left.y, left.y + (height),left.y + (height) };
	pWind->DrawPolygon(aX, aY, 4);
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(left.x + width / 4, left.y + height / 4, text);
}

//TODO: Add similar functions for drawing all other statements.
//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
//		Decide the parameters that should be passed to each of them

//TODO: Add DrawConnector function
void Output::Drawconnector(Point start, Point Mid, Point end, bool selected) {

	if (selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);
	pWind->DrawLine(start.x, start.y, Mid.x, Mid.y);
	pWind->DrawLine(Mid.x, Mid .y, end.x, end.y);
	pWind->DrawTriangle(end.x - 4, end.y, end.x + 4, end.y, end.x, end.y + 4);
}
void Output::Drawconnectors(Point start, Point end, bool selected) {

	if (selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3); 
	if (start.x == end.x) {
		pWind->DrawLine(start.x, start.y, end.x, end.y);
		pWind->DrawTriangle(end.x - 4, end.y, end.x + 4, end.y, end.x, end.y + 4);
	}
	else  if (start.x < end.x) {
		pWind->DrawLine(start.x, start.y, end.x, end.y);
		pWind->DrawTriangle(end.x, end.y - 4, end.x, end.y + 4, end.x + 4, end.y);
	}
	else if (start.x > end.x) {
		pWind->DrawLine(start.x, start.y, end.x, end.y);
		pWind->DrawTriangle(end.x, end.y - 4, end.x, end.y + 4, end.x - 4, end.y);
	}
	else if (start.x != end.x && start.y != end.y) {

	}
	
	
	pWind->SetPen(BLACK, 2);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
