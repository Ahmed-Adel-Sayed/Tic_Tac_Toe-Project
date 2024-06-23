//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <cstdlib>
#include "HomePage.h"
#include "Register.h"
#include "Login.h"
#include "playervsplayer.h"
#include "aivsplayer.h"
#include "gamehistory.h"
#include <iostream>
#include <vector>
#include <string>
#include <exception>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	  int idFromForm1 = ((TForm1*)Owner)->ID; // Access integer ID property from Form1
}
//---------------------------------------------------------------------------

/*
void insertGameResult(int userID, int gameID, const AnsiString& winOrLose,const AnsiString& history) {
	try {
		// Execute SQL insert statement for GameResults table
		Form3->GameresultsTable->SQL->Text = "INSERT INTO GameResults (id, GameID, WinOrLose ,history ) VALUES (:userID, :gameID, :winOrLose,:history)";
		Form3->GameresultsTable->Params->ParamByName("userID")->AsInteger = userID;
		Form3->GameresultsTable->Params->ParamByName("gameID")->AsInteger = gameID;
		Form3->GameresultsTable->Params->ParamByName("winOrLose")->AsString = winOrLose;
		Form3->GameresultsTable->Params->ParamByName("history")->AsString = history;
		Form3->GameresultsTable->ExecSQL();
		ShowMessage("Game result inserted successfully");
	} catch (const Exception& e) {
		ShowMessage("Error inserting game result: " + e.Message);
	}
}


void readGameResults(int userID) {
	try {
		// Execute SQL select statement to retrieve game results for the specified user ID
		Form3->GameresultsTable->SQL->Text = "SELECT history,GameID, WinOrLose FROM GameResults WHERE ID = :userID";
		Form3->GameresultsTable->Params->ParamByName("userID")->AsInteger = userID;
		Form3->GameresultsTable->Open();
		// Process the retrieved game results
		while (!Form3->GameresultsTable->Eof) {
			int gameID = Form3->GameresultsTable->FieldByName("GameID")->AsInteger;
			AnsiString winOrLose = Form3->GameresultsTable->FieldByName("WinOrLose")->AsString;
			AnsiString history = Form3->GameresultsTable->FieldByName("history")->AsString;
			// Do something with the game result data (e.g., display it)
			ShowMessage("Game ID: " + IntToStr(gameID) + ", Result: " + winOrLose + ", history: " + history);
			Form3->GameresultsTable->Next();
		}
		// Close the query
		Form3->GameresultsTable->Close();
	} catch (const Exception& e) {
		ShowMessage("Error reading game results: " + e.Message);
	}
}

char getCharAtIndex(const AnsiString& inputString, int index) {
	int count = 0;
	for (int i = 1; i <= inputString.Length(); ++i) {
		char c = inputString[i];
		if (c != ',') {
			if (count == index) {
				return c;
			}
			count++;
		}
	}
	return '\0';
}
AnsiString serializeChars(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9) {
	AnsiString result;
	result = c1; result += ','; result += c2;result += ','; result += c3;
	result += ',';result += c4; result += ',';result += c5; result += ',';
	result += c6;result += ','; result += c7;result += ','; result += c8;
	result += ',';result += c9;
	return result;
}
	 //  insertGameResult(1,2,"win","X,X,X,X");
	//readGameResults(Form1->ID);

   /*	AnsiString inputString = "x,o,o,x,o,o,o,o,x";
	int index = 2;
	char charAtIndex = getCharAtIndex(inputString, index);
	ShowMessage("Character at index " + IntToStr(index) + ": " + charAtIndex);   */
	/*char c1 = 'x';
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

//---------------------------------------------------------------------------



void __fastcall TForm3::playerClick(TObject *Sender)
{
	this->Close();
   Hide();
   Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::AIClick(TObject *Sender)
{
	this->Close();
	Hide();
	Form5->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::historyClick(TObject *Sender)
{
    this->Close();
	Hide();
	Form6->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::exitClick(TObject *Sender)
{
 terminateProgram();
}
//---------------------------------------------------------------------------
	void TForm3::terminateProgram() {
	std::terminate();
}
