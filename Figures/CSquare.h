#ifndef CSQR_H
#define CSQR_H

#include "CFigure.h"

class CSquare : public CFigure
{
public:
	CSquare();//for load function to allow read of type and then set parameters in each shape later
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int, int) ;
	virtual void Move(int, int) ;
	virtual void PrintInfo(Output*) ;
	void Save(ofstream& outputFile);
	void Load(ifstream& inputFile);
	virtual string GetFigureType();
};

#endif
