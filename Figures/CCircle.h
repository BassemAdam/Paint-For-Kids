#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Point2;
	
public:
	CCircle();//for load function to allow read of type and then set parameters in each shape later
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output*) const;
	virtual bool IsInside(int, int);
	void PrintInfo(Output*);
	void Save(ofstream& outputFile);
	void Load(ifstream& inputFile);
	virtual void Move(int, int);
	virtual string GetFigureType();
};

#endif