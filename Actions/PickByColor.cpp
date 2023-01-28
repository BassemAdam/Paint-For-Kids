#pragma once
#include "PickByColor.h"
#include "..\ApplicationManager.h"
#include"SaveAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"LoadAction.h"

PickByColor::PickByColor(ApplicationManager* pApp) :Action(pApp)
{
	numOfcolors = 0; WrongPicks = 0;CorrestPicks = 0;

}

void PickByColor::ReadActionParameters()
{
	pManager->ArrOfclr(); // calculating number of each color in array by calling each figure increment function

	 ArrayOfColors = Fig->getArrOfColors();  //getting array of colors which is static  ;so at the end we reset it in the end game

	for (int i = 0;i < 6;i++)
		if (ArrayOfColors[i] != 0)numOfcolors++; //calculating variety of colors
	

}


void PickByColor::Execute(bool WillRecord, string filename, bool where )
{
	pManager->Reset();
	
	// alternative
	//LoadAction* L = new LoadAction(pManager);
	//L->Execute(false, "Details", 0);

	pManager->UpdateInterface();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	ReadActionParameters();

	if (numOfcolors > 1)
	{

		
		// alterntaive 
		//RandomFigNum = rand() % pManager->getFigCount();

		Fig = pManager->GetRandFig(); //random figure returned 

		//use randfig to determine the promt for the game 
		if (Fig->GetGfxInfo().isFilled) //checking firt if shape is filled to be valid for pick by color game
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				NumOfColorsToPicked = ArrayOfColors[0]; //if random is color black then num of colors to picked is number of colors black
				pOut->PrintMessage("pick all black figures !");
			}
			else if (Fig->GetGfxInfo().FillClr == YELLOW)
			{
				NumOfColorsToPicked = ArrayOfColors[1];
				pOut->PrintMessage("pick all yellow figures !");
			}
			else if (Fig->GetGfxInfo().FillClr == ORANGE)
			{
				NumOfColorsToPicked = ArrayOfColors[2];
				pOut->PrintMessage("pick all orange figures !");

			}
			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				NumOfColorsToPicked = ArrayOfColors[3];
				pOut->PrintMessage("pick all red figures!");

			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				NumOfColorsToPicked = ArrayOfColors[4];
				pOut->PrintMessage("pick all green figures!");

			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				NumOfColorsToPicked = ArrayOfColors[5];
				pOut->PrintMessage("pick all blue figures!");

			}
		}

		//after promiting the kid 
		//we get click from the kid and check if the clicked fig color is the same as fig
		CFigure* ClickedFigure;

		while (NumOfColorsToPicked > 0)
		{

			pIn->GetPointClicked(point.x, point.y);

			if (point.y > UI.ToolBarHeight || point.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				ClickedFigure = pManager->GetFigure(point.x, point.y);

				if (ClickedFigure != NULL&&ClickedFigure->IsHidden())
				{

					if ( Fig->GetGfxInfo().FillClr == ClickedFigure->GetGfxInfo().FillClr)
					{
						PrntScore(1);
						ClickedFigure->SetHidden(0);

						//alternative
						//pManager->DeleteFigure(ClickedFigure);

						pManager->UpdateInterface();
						NumOfColorsToPicked--;
					}
					else
					{
						PrntScore(2);
						ClickedFigure->SetHidden(0);
						pManager->UpdateInterface();
					}
				}
			}
			else
			{
				pOut->PrintMessage("Game ended ! BYE");
				NumOfColorsToPicked = -1;
			}
		}
		if (NumOfColorsToPicked == 0) {
			PrntScore(3);

		}
			
	}
	else
		pOut->PrintMessage("Sorry you should have 2 or more filled colors to play pick by color");
	
	
	pManager->ResetArrOfclr();
	//delete L;
}

void PickByColor::PrntScore(int x)
{
	Output* pOut = pManager->GetOutput();

	string message;
	if (x == 1)
	{
		CorrestPicks++;
		message = "CORRECT!,Score = " + to_string(CorrestPicks) + " Right, and " + to_string(WrongPicks) + " Wrong.";
	}
	else if (x == 2)
	{
		WrongPicks++;
		message = "WRONG TRY Again!,Score = " + to_string(CorrestPicks) + " Right, and " + to_string(WrongPicks) + " Wrong.";
	}
	else
		message = "Congratulations YOU WIN!, Final Score = " + to_string(CorrestPicks) + " Right, and " + to_string(WrongPicks) + " Wrong.";

	pOut->PrintMessage(message);

}


void PickByColor::Undo() {}

void PickByColor::Redo() {}

PickByColor::~PickByColor()
{

}