#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <fstream> 
#include"Actions\Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	bool WillRecord; //if recording
	int FigCount; //Actual number of figures
	Action* UndoList[5]; //Undo List
	Action* RedoList[5]; //Redo List
	Action* RecordingList[20];
	Action* ActionsList[200]; //Last 200 Actions List
	int RecordingListCount; //Current size of Recording List
	int UndoListCurrentSize; //Current size of Undo List
	int RedoListCurrentSize; //Current size of Redo List
	int ActionsListCurrentSize; //Current size of Actions List
	bool MuteState; // Mute State
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); //Constructor
	~ApplicationManager(); //Destructor
	void ResetArrOfclr();
	// -- Action-Related Functions
	ActionType GetUserAction() const; //Reads the input command from the user and returns the corresponding action type
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void SetSelectedFigure(CFigure*);
	CFigure* GetSelectedFigure();
	void UndoPrevAction(); //Undo Last Action
	void RedoPrevAction(); //Redo Last Undone Action 
	void ToggleMute(); //Change Mute State
	bool IsMute(); //Get Mute State

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void DeleteFigure(CFigure*); //Delete the figure from FigList
	bool IsFoundInFigList(CFigure*);

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	//-- Save Management Functions RHG
	void SaveFigcount(ofstream & outputFile);
	void clearAll();
	void ResetData();
	void SaveAll(ofstream& outputFile);

	//-- Pick By color Function RHG
	void ArrOfclr();
	int getFigCount();

	//Recording Functions
	bool IsEmpty();
	void PlayRecording(int RecordingListCount);// plays an action of recording
	void AddRecordingFigure(Action* rAction);//adds figures to the recording list
	void AddActionToUndoList(Action*);
	void AddActionToActionsList(Action*);
	bool getWillRecord();// setter and getter fir the will record boolean.
	void setWillRecord(bool willrecord);
	int GetRecordingListCount();//count of recording list

	//Play functions
	CFigure* GetRandFig();// Random figure on screen 
	int GetNumberofSelectedFigure(CFigure* PlayFig);// Number of passed in Figure.
	int GetNumberofSelectedFigure(CFigure* PlayFig, GfxInfo GfxInfo);
	
	void Reset();
};

#endif