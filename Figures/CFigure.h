#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:

	static int count; // count of figures
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	Point Center; //Center of the figure
	bool Hidden; //Hidden status
	/// Add more parameters if needed.
	static int ArrOfColors[];

public:
	
	 int* getArrOfColors();

	CFigure(); //to allow zero argument constructor in children
	CFigure(GfxInfo FigureGfxInfo);
	void ResetArrOfClrs(); //Resets array of colours
	static void resetID(); //delets all IDs
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	bool IsHidden() const; //check if figure will be drawn
	void SetHidden(bool) ; //set hide status
	int GetID(); //returns id of figure
	void SetID(int);// sets id of figure
	Point GetCenter();//Returns center of figure
	GfxInfo GetGfxInfo()const; //returns graphics info of figures
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	void ChngGfxInfo(GfxInfo); //Change Graphics info
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual bool IsInside(int,int) = 0; //checks if the points clicked are inside a figure
	virtual void Move(int, int) = 0; //Moving center of figures to the new point
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure
	void incrementArrOfClrs();
	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output*) = 0;	//print all figure info on the status bar

	//converting color type to string to be able to write it in text files
	string convertcolorToString(color color); //note i should have used those conversions static in load,save but when i did it gets errors
	//converting string type to color to be able to read it from text files
	color convertStringToColor(string color); //Converts string into a color type
	virtual string GetFigureType()=0; //Get Figure type
	
};

#endif