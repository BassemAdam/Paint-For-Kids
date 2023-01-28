#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(); //for load function to allow read of type and then set parameters in each shape later
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int, int);
	virtual void Move(int, int);
	virtual void PrintInfo(Output*);
	void Save(ofstream& outputFile);
	void Load(ifstream& inputFile);
	virtual string GetFigureType();
};

#endif