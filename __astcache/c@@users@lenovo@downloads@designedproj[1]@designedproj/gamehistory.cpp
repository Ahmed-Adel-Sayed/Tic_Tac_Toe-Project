#include <vcl.h>
#pragma hdrstop

#include "HomePage.h"
#include "Register.h"
#include "Login.h"
#include "playervsplayer.h"
#include "aivsplayer.h"
#include "gamehistory.h"
#include <iostream>
#include <vector>
#include <string>

#include <string> // For std::string
#include <cstdlib> // For std::atoi
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;

int currentRecordIndex = 0;
int currentRecordIndexloc = 0;
std::vector<int> recordPositions;
AnsiString history;
AnsiString positions;

//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
	 int idFromForm1 = ((TForm1*)Owner)->ID; // Access integer ID property from Form1
     Form6->ButtonNext->Caption = "Replay";
	 Form6->ButtonPrevious->Visible = false;
}

//---------------------------------------------------------------------------
void clearBoard() {
	Form6->Button1->Caption = "";
	Form6->Button2->Caption = "";
	Form6->Button3->Caption = "";
	Form6->Button4->Caption = "";
	Form6->Button5->Caption = "";
	Form6->Button6->Caption = "";
	Form6->Button7->Caption = "";
	Form6->Button8->Caption = "";
	Form6->Button9->Caption = "";
}

AnsiString getCharAtIndex(const AnsiString& inputString, int index) {
	int count = 0;
	for (int i = 1; i <= inputString.Length(); ++i) {
		char c = inputString[i];
		if (c == ',') {
			if (count == index) {
				return "";  // Return an empty string for empty positions
			}
			count++;
		} else {
			if (count == index) {
				return AnsiString(c);
			}
		}
	}
	return "";  // Return an empty string if index is out of bounds
}

int getintAtIndex(const AnsiString& inputString, int index) {
	int count = 0;
	std::string number;
	for (int i = 1; i <= inputString.Length(); ++i) {
		char c = inputString[i];
		if (c == ',') {
			if (count == index) {
                // Convert the collected number to an integer and return it
                return number.empty() ? -1 : std::atoi(number.c_str());
			}
            count++;
            number.clear(); // Reset the number string for the next number
		} else {
			if (count == index) {
				number += c; // Collect the digit for the current number
			}
		}
	}

	// Check the last number in the string
	if (count == index) {
		return number.empty() ? -1 : std::atoi(number.c_str());
	}

	return -1;  // Return -1 if index is out of bounds
}

void readGameResults(int userID) {
	try {
		// Only initialize the query if it's the first time or if the table is closed
		if (currentRecordIndex == 0 || Form6->GameresultsTable->Active == false) {
			Form6->GameresultsTable->SQL->Text = "SELECT history, GameID, WinOrLose, gamenumber ,positions, playertype ,opponent FROM GameResults WHERE ID = :userID";
			Form6->GameresultsTable->Params->ParamByName("userID")->AsInteger = userID;
			Form6->GameresultsTable->Open();
		}

		// Check if there are more records to display
		if (!Form6->GameresultsTable->Eof) {
			int gameID = Form6->GameresultsTable->FieldByName("GameID")->AsInteger;
			int gamenumber = Form6->GameresultsTable->FieldByName("gamenumber")->AsInteger;

			AnsiString winOrLose = Form6->GameresultsTable->FieldByName("WinOrLose")->AsString;
			history = Form6->GameresultsTable->FieldByName("history")->AsString;
			positions = Form6->GameresultsTable->FieldByName("positions")->AsString;
			AnsiString playertype = Form6->GameresultsTable->FieldByName("playertype")->AsString;
			AnsiString opponent = Form6->GameresultsTable->FieldByName("opponent")->AsString;

			// Display the data in the form controls
			Form6->Label5->Caption = gamenumber;
			Form6->Label8->Caption = winOrLose;
			Form6->Label7->Caption = opponent;
			Form6->Label6->Caption = playertype;
			Form6->Button1->Caption = getCharAtIndex(history, 0);
			Form6->Button2->Caption = getCharAtIndex(history, 1);
			Form6->Button3->Caption = getCharAtIndex(history, 2);
			Form6->Button4->Caption = getCharAtIndex(history, 3);
			Form6->Button5->Caption = getCharAtIndex(history, 4);
			Form6->Button6->Caption = getCharAtIndex(history, 5);
			Form6->Button7->Caption = getCharAtIndex(history, 6);
			Form6->Button8->Caption = getCharAtIndex(history, 7);
			Form6->Button9->Caption = getCharAtIndex(history, 8);

		Form6->ButtonNext->Caption = "Replay";
		Form6->ButtonPrevious->Visible = false;

			// Parse positions
		recordPositions.clear();
		for (int i = 0; i < 9; ++i) {
		int pos = getintAtIndex(positions, i);
		if (pos != -1) {
		recordPositions.push_back(pos);
		}
}
		  // Show the contents of recordPositions vector
			AnsiString message = "recordPositions vector: ";
			for (size_t i = 0; i < recordPositions.size(); ++i) {
				message += recordPositions[i];
				message += " ";
			}
			ShowMessage(message);
			// Move to the next record
			Form6->GameresultsTable->Next();
			currentRecordIndex++;
			currentRecordIndexloc=0;
		} else {
			// If no more records, reset the index and close the table
			ShowMessage("No more records to display.");
			Form6->GameresultsTable->Close();
			currentRecordIndex = 0;
		}
	} catch (const Exception& e) {
		ShowMessage("Error reading game results: " + e.Message);
	}
}
//-------------------------------------------------------------------------------
AnsiString serializeChars(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9) {
	AnsiString result;
	result = c1; result += ','; result += c2;result += ','; result += c3;
	result += ',';result += c4; result += ',';result += c5; result += ',';
	result += c6;result += ','; result += c7;result += ','; result += c8;
	result += ',';result += c9;
	return result;
}

void displayCurrentMove(int moveIndex) {
	clearBoard();
	// Iterate through all moves up to the current move index
    for (int i = 0; i <= moveIndex; ++i) {
		int posIndex = recordPositions[i] - 1;
		AnsiString charAtPos = getCharAtIndex(history, posIndex);
        switch (posIndex) {
            case 0: Form6->Button1->Caption = charAtPos; break;
            case 1: Form6->Button2->Caption = charAtPos; break;
            case 2: Form6->Button3->Caption = charAtPos; break;
			case 3: Form6->Button4->Caption = charAtPos; break;
            case 4: Form6->Button5->Caption = charAtPos; break;
            case 5: Form6->Button6->Caption = charAtPos; break;
            case 6: Form6->Button7->Caption = charAtPos; break;
            case 7: Form6->Button8->Caption = charAtPos; break;
            case 8: Form6->Button9->Caption = charAtPos; break;
        }
	}
}

void __fastcall TForm6::Button10Click(TObject *Sender)
{
		   readGameResults(Form1->ID);
}
//---------------------------------------------------------------------------


void __fastcall TForm6::Button11Click(TObject *Sender)
{
	 this->Close();
	 Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ButtonPreviousClick(TObject *Sender)
{
	if (currentRecordIndexloc > 0) {
			currentRecordIndexloc--;
	displayCurrentMove(currentRecordIndexloc);
	} else {
		ShowMessage("No previous moves.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ButtonNextClick(TObject *Sender)
{       if (ButtonNext->Caption == "Replay") {
        ButtonNext->Caption = "Next";
        ButtonPrevious->Visible = true;
	}
	if (currentRecordIndexloc < recordPositions.size()) {
	displayCurrentMove(currentRecordIndexloc);
	currentRecordIndexloc++;

	} else {
		ShowMessage("No next moves.");
	}
}

//---------------------------------------------------------------------------

/*
int getintAtIndex(const AnsiString& inputString, int index) {
    int count = 0;
    for (int i = 1; i <= inputString.Length(); ++i) {
        char c = inputString[i];
        if (c == ',') {
            if (count == index) {
                return -1;  // Return -1 for empty positions
            }
            count++;
        } else {
            if (count == index) {
                return static_cast<int>(c); // Return the ASCII value of the character
            }
		}
	}
	return -1;  // Return -1 if index is out of bounds
}
*/
	//insertGameResult(1,2,"win","X,X,X,X");
   //	readGameResults(Form1->ID);

   /*	AnsiString inputString =
	int index = 2;
	char charAtIndex = getCharAtIndex(inputString, index);
	ShowMessage("Character at index " + IntToStr(index) + ": " + charAtIndex);
	char c1 = 'x';
	char c2 = 'o';
	char c3 = 'o';
	char c4 = 'x';
	char c5 = 'o';
	char c6 = 'o';
	char c7 = 'o';
	char c8 = 'o';
	char c9 = 'x';

	AnsiString serializedString = serializeChars(c1, c2, c3, c4, c5, c6, c7, c8, c9);
	ShowMessage("Serialized string: " + serializedString);*/
