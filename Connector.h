#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "GUI\UI_Info.h"
#include "GUI\output.h"
class Statement;

class Connector	//a connector that connects two statements (Source & Destination)
{
private:
	Statement *SrcStat;	//The source c of the connector
	Statement *DstStat;	//The destination statement of the connector
	Point Start;	//Start point of the connector
	Point End;		//End point of the connector
	bool Selected;	//true if the Connector is selected on the flowchart

public:
	Connector(Statement* Src, Statement* Dst);

	void SetSelected(bool s);

	void		setSrcStat(Statement *Src);
	Statement*	getSrcStat();	
	void		setDstStat(Statement *Dst);
	Statement*	getDstStat();

	void setStartPoint(Point P);
	Point getStartPoint();

	void setEndPoint(Point P);
	Point getEndPoint();

	void Draw(Output* pOut) const;
	void Drawcondconn(Output* pOut);
	virtual bool isClicked(Point p);

};

#endif