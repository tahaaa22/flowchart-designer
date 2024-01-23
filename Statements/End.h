#pragma once
#include "Statement.h"

	class End : public Statement
	{
	private:
		string text;
		Connector* pOutConn;
		Point Inlet;
		Point LeftCorner;
		virtual void UpdateStatementText();

	public:
		End(Point Lcorner, string TEXT = "End");
		void SetText(const string& L);
		void SetID(int ID);
		virtual void Draw(Output* pOut) const;
		bool isClicked(Point p);
		Point getInlet();
		void Save(ofstream& OutFile);
	};


