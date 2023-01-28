#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle();//for load function to allow read of type and then set parameters in each shape later
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int, int);
	virtual void Move(int, int);
	virtual void PrintInfo(Output*);
	void Save(ofstream& outputFile);
	void Load(ifstream& inputFile);
	virtual string GetFigureType();
};

#endif