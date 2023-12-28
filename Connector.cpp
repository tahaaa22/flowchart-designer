#include "Connector.h"
#include "Statements\ValueAssign.h"
#include"Conditional.h"
#include "End.h"
#include "Read.h"
#include "Start.h"
#include "VariableAssign.h"
#include "Writee.h"
#include "OperatorAssign.h"


Connector::Connector(Statement* Src, Statement* Dst)	
//When a connector is created, it must have a source statement and a destination statement
//There are NO FREE connectors in the flowchart
{

	SrcStat = Src;
	DstStat = Dst;
	if (Src  && Dst )
	{
		set_inlet_outlet();
	}
	
	Selected = false;
}

void Connector::set_inlet_outlet()
{
	if (ValueAssign* source = dynamic_cast<ValueAssign*>(SrcStat))
	{
		Startp = source->getOutlet();
	}

	if (ValueAssign* destination = dynamic_cast<ValueAssign*>(DstStat))
		Endp = destination->getInlet();

	
	if (End* destination = dynamic_cast<End*>(DstStat))
		Endp = destination->getInlet();

	if (Start* source = dynamic_cast<Start*>(SrcStat))
	{
		Startp = source->getOutlet();
	}

	if (Conditional* source = dynamic_cast<Conditional*>(SrcStat))
	{
		Startp = source->getOutlet();
	}

	if (Conditional* destination = dynamic_cast<Conditional*>(DstStat))
		Endp = destination->getInlet();

	if (OperatorAssign* source = dynamic_cast<OperatorAssign*>(SrcStat))
	{
		Startp = source->getOutlet();
	}

	if (OperatorAssign* destination = dynamic_cast<OperatorAssign*>(DstStat))
		Endp = destination->getInlet();


	if (Read* source = dynamic_cast<Read*>(SrcStat))
	{
		Startp = source->getOutlet();
	}

	if (Read* destination = dynamic_cast<Read*>(DstStat))
		Endp = destination->getInlet();

	if (VariableAssign* source = dynamic_cast<VariableAssign*>(SrcStat))
	{
		Startp = source->getOutlet();
	}

	if (VariableAssign* destination = dynamic_cast<VariableAssign*>(DstStat))
		Endp = destination->getInlet();

	if (Writee* source = dynamic_cast<Writee*>(SrcStat))
	{
		Startp = source->getOutlet();
	}

	if (Writee* destination = dynamic_cast<Writee*>(DstStat))
		Endp = destination->getInlet();
}



void Connector::SetSelected(bool s)
{
		Selected = s;
}

void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}


void Connector::setStartPoint(Point P)
{	Startp = P;	}

Point Connector::getStartPoint()
{	return Startp;	}

void Connector::setEndPoint(Point P)
{	Endp = P;	}

Point Connector::getEndPoint()
{	return Endp;	}

void Connector::Draw(Output* pOut) const
{
	pOut->Drawconnectors(Startp, Endp, Selected);

	///TODO: Call Output to draw a connector from SrcStat to DstStat on the output window
}

void Connector::Drawcondconn(Output* pOut)
{
	pOut->Drawconnector(Startp, Endp, Selected);

}

bool Connector::isClicked(Point p)
{
	if (p.y >= Startp.y && p.y <= Endp.y && p.x <= Startp.x && p.x >= Endp.x)
	{
		return true;
	}
	if (p.y >= Startp.y && p.y <= Endp.y && p.x >= Startp.x && p.x <= Endp.x)
	{
		return true;
	}
	return false;
}

