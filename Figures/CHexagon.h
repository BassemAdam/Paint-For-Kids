#ifndef CHEXA_H
#define CHEXA_H
#include "CFigure.h"

class CHexagon : public CFigure
{
public:
	CHexagon();//for load function to allow read of type and then set parameters in each shape later
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int, int);
	void PrintInfo(Output* pOut);
	void Save(ofstream& outputFile);
	virtual void Move(int, int);
	void Load(ifstream& inputFile);
	virtual string GetFigureType();
};

#endif