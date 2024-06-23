
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
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

AnsiString positions = "";  // This will store the click sequence
std::vector<int> clickOrder; // Vector to keep track of click order

char current = 'X';
char playertype;
AnsiString opponent= "human";

//----------------------------------------------------------------------------
void insertGameResult(int userID, const AnsiString& winOrLose, const AnsiString& history, const AnsiString& positions ,const AnsiString& playertype,const AnsiString& opponent ) {
	try {
		int nextGameID = 1; // Default to 1 if there are no existing records
		int nextGameNumber = 1; // Default to 1 if there are no existing records

		// Check if the user ID exists in the GameResults table, if not, insert it
        Form4->GameresultsTable->SQL->Text = "SELECT ID FROM GameResults WHERE ID = :userID";
		Form4->GameresultsTable->Params->ParamByName("userID")->AsInteger = userID;
		Form4->GameresultsTable->Open();
        if (Form4->GameresultsTable->Eof) {
			// Insert the user ID into the GameResults table
			Form4->GameresultsTable->SQL->Text = "SELECT MAX(GameID) AS MaxGameID FROM GameResults";
			Form4->GameresultsTable->Open();
			if (!Form4->GameresultsTable->Eof) {
				nextGameID = Form4->GameresultsTable->FieldByName("MaxGameID")->AsInteger + 1;
			}

			Form4->GameresultsTable->Close();
			Form4->GameresultsTable->SQL->Text = "INSERT INTO GameResults (ID,GameID) VALUES (:userID,:gameID)";
			Form4->GameresultsTable->Params->ParamByName("userID")->AsInteger = userID;
			Form4->GameresultsTable->Params->ParamByName("gameID")->AsInteger = nextGameID;
			Form4->GameresultsTable->ExecSQL();
		}
		Form4->GameresultsTable->Close();

		// Get the current maximum GameID and gamenumber for the user
		Form4->GameresultsTable->SQL->Text = "SELECT MAX(GameID) AS MaxGameID FROM GameResults ";
		Form4->GameresultsTable->Open();
        if (!Form4->GameresultsTable->Eof) {
			nextGameID = Form4->GameresultsTable->FieldByName("MaxGameID")->AsInteger + 1;
		}
		Form4->GameresultsTable->Close();
		Form4->GameresultsTable->SQL->Text = "SELECT MAX(gamenumber) AS MaxGameNumber FROM GameResults WHERE ID = :userID";
		Form4->GameresultsTable->Params->ParamByName("userID")->AsInteger = userID;
		Form4->GameresultsTable->Open();
        if (!Form4->GameresultsTable->Eof) {
			//nextGameID = Form4->GameresultsTable->FieldByName("MaxGameID")->AsInteger + 1;
			nextGameNumber = Form4->GameresultsTable->FieldByName("MaxGameNumber")->AsInteger + 1;
		}

		Form4->GameresultsTable->Close();

		// Insert the new game result
		Form4->GameresultsTable->SQL->Text = "INSERT INTO GameResults (ID, gamenumber, GameID, WinOrLose, history, positions ,playertype ,opponent) VALUES (:userID, :gamenumber, :gameID, :winOrLose, :history, :positions ,:playertype,:opponent)";
		Form4->GameresultsTable->Params->ParamByName("userID")->AsInteger = userID;
		Form4->GameresultsTable->Params->ParamByName("gamenumber")->AsInteger = nextGameNumber;
		Form4->GameresultsTable->Params->ParamByName("gameID")->AsInteger = nextGameID;
		Form4->GameresultsTable->Params->ParamByName("winOrLose")->AsString = winOrLose;
		Form4->GameresultsTable->Params->ParamByName("history")->AsString = history;
		Form4->GameresultsTable->Params->ParamByName("positions")->AsString = positions;
		Form4->GameresultsTable->Params->ParamByName("playertype")->AsString = playertype;
		Form4->GameresultsTable->Params->ParamByName("opponent")->AsString = opponent;
		Form4->GameresultsTable->ExecSQL();

        ShowMessage("Game result inserted successfully");
    } catch (const Exception& e) {
		ShowMessage("Error inserting game result: " + e.Message);
    }
}


AnsiString serializeChars(AnsiString c1, AnsiString c2, AnsiString c3, AnsiString c4, AnsiString c5, AnsiString c6, AnsiString c7, AnsiString c8, AnsiString c9) {
	AnsiString result;
	result = c1; result += ','; result += c2; result += ','; result += c3;
	result += ','; result += c4; result += ','; result += c5; result += ',';
	result += c6; result += ','; result += c7; result += ','; result += c8;
	result += ','; result += c9;
	return result;
}

//------------------------------------------------------------------------------

 bool TForm4::checkisWinner() {
	// Check rows
	if (Button1->Caption == Button2->Caption && Button1->Caption == Button3->Caption && !Button1->Caption.IsEmpty()) {

		Button1->Font->Style = TFontStyles() << fsBold;
		Button2->Font->Style = TFontStyles() << fsBold;
		Button3->Font->Style = TFontStyles() << fsBold;

		return true;
	}
	if (Button4->Caption == Button5->Caption && Button4->Caption == Button6->Caption && !Button4->Caption.IsEmpty()) {
        Button4->Font->Style = TFontStyles() << fsBold;
		Button5->Font->Style = TFontStyles() << fsBold;
		Button6->Font->Style = TFontStyles() << fsBold;
        return true;
	}
    if (Button7->Caption == Button8->Caption && Button7->Caption == Button9->Caption && !Button7->Caption.IsEmpty()) {

		Button7->Font->Style = TFontStyles() << fsBold;
        Button8->Font->Style = TFontStyles() << fsBold;
		Button9->Font->Style = TFontStyles() << fsBold;
        return true;
    }

    // Check columns
    if (Button1->Caption == Button4->Caption && Button1->Caption == Button7->Caption && !Button1->Caption.IsEmpty()) {

		Button1->Font->Style = TFontStyles() << fsBold;
		Button4->Font->Style = TFontStyles() << fsBold;
		Button7->Font->Style = TFontStyles() << fsBold;
        return true;
    }
	if (Button2->Caption == Button5->Caption && Button2->Caption == Button8->Caption && !Button2->Caption.IsEmpty()) {

        Button2->Font->Style = TFontStyles() << fsBold;
        Button5->Font->Style = TFontStyles() << fsBold;
		Button8->Font->Style = TFontStyles() << fsBold;
        return true;
	}
    if (Button3->Caption == Button6->Caption && Button3->Caption == Button9->Caption && !Button3->Caption.IsEmpty()) {

		Button3->Font->Style = TFontStyles() << fsBold;
		Button6->Font->Style = TFontStyles() << fsBold;
		Button9->Font->Style = TFontStyles() << fsBold;
		return true;
	}

	// Check diagonals
	if (Button1->Caption == Button5->Caption && Button1->Caption == Button9->Caption && !Button1->Caption.IsEmpty()) {

		Button1->Font->Style = TFontStyles() << fsBold;
		Button5->Font->Style = TFontStyles() << fsBold;
        Button9->Font->Style = TFontStyles() << fsBold;
        return true;
	}
    if (Button3->Caption == Button5->Caption && Button3->Caption == Button7->Caption && !Button3->Caption.IsEmpty()) {

        Button3->Font->Style = TFontStyles() << fsBold;
        Button5->Font->Style = TFontStyles() << fsBold;
        Button7->Font->Style = TFontStyles() << fsBold;
		return true;
	}

	return false;
}



//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
	Label1->Caption = "Choose X or O";
    WinnerLabel->Caption = "";
	currentLabel->Caption = "";
	Button1->Hide();
	Button2->Hide();
	Button3->Hide();
	Button4->Hide();
	Button5->Hide();
	Button6->Hide();
	Button7->Hide();
	Button8->Hide();
	Button9->Hide();
	Button10->Hide();

	int idFromForm1 = ((TForm1*)Owner)->ID; // Access integer ID property from Form1
	int idFromForm6 = ((TForm6*)Owner)->gameID;
}

// Helper function to get the button number
int TForm4::getButtonNumber(TButton* button) {
	if (button == Button1) return 1;
	if (button == Button2) return 2;
	if (button == Button3) return 3;
	if (button == Button4) return 4;
	if (button == Button5) return 5;
	if (button == Button6) return 6;
	if (button == Button7) return 7;
	if (button == Button8) return 8;
	if (button == Button9) return 9;
	return 0; // Should not happen
}

void __fastcall TForm4::ButtonClick(TObject *Sender) {
	TButton* clickedButton = dynamic_cast<TButton*>(Sender);
	if (clickedButton->Caption.IsEmpty()) { // Ensure the button is not already clicked
		clickedButton->Caption = current;

		// Record the button click
		int buttonNumber = getButtonNumber(clickedButton);
		clickOrder.push_back(buttonNumber);

		if (checkisWinner()) {
			if(current==playertype){
			WinnerLabel->Caption = "won";
			ShowMessage("You Won the Game!!");
			}
			else{
            WinnerLabel->Caption = "lose";
			ShowMessage("You Lost the Game!!");
			}
			Form4->Button10->Show();
			Form4->Button1->Enabled=false;
			Form4->Button2->Enabled=false;
			Form4->Button3->Enabled=false;
			Form4->Button4->Enabled=false;
			Form4->Button5->Enabled=false;
			Form4->Button6->Enabled=false;
			Form4->Button7->Enabled=false;
			Form4->Button8->Enabled=false;
			Form4->Button9->Enabled=false;
		}
        if (!checkisWinner() && !Button1->Caption.IsEmpty() && !Button2->Caption.IsEmpty() && !Button3->Caption.IsEmpty() &&
			!Button4->Caption.IsEmpty() && !Button5->Caption.IsEmpty() && !Button6->Caption.IsEmpty() &&
			!Button7->Caption.IsEmpty() && !Button8->Caption.IsEmpty() && !Button9->Caption.IsEmpty()) {
			ShowMessage("Draw");
			WinnerLabel->Caption = "draw";
			Form4->Button10->Show();
			Form4->Button1->Enabled=false;
			Form4->Button2->Enabled=false;
			Form4->Button3->Enabled=false;
			Form4->Button4->Enabled=false;
			Form4->Button5->Enabled=false;
			Form4->Button6->Enabled=false;
			Form4->Button7->Enabled=false;
			Form4->Button8->Enabled=false;
			Form4->Button9->Enabled=false;
		}


		if (current == 'X')
			current = 'O';
		else
			current = 'X';

		currentLabel->Caption = current;
	}
}

// Helper function to convert vector to AnsiString
AnsiString vectorToAnsiString(const std::vector<int>& vec) {
	AnsiString result = "";
	for (size_t i = 0; i < vec.size(); ++i) {
		if (i != 0) {
			result += ",";
		}
		result += AnsiString(vec[i]);
	}
	return result;
}

void __fastcall TForm4::Button10Click(TObject *Sender) {
	AnsiString chars = serializeChars(Button1->Caption, Button2->Caption, Button3->Caption, Button4->Caption, Button5->Caption, Button6->Caption, Button7->Caption, Button8->Caption, Button9->Caption);

	// Convert click order to AnsiString
	positions = vectorToAnsiString(clickOrder);

	insertGameResult(Form1->ID, WinnerLabel->Caption, chars, positions,playertype,opponent);

	// Clear click order for the next game
	clickOrder.clear();
	positions = "";

	Button10->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button11Click(TObject *Sender)
{
	current = 'X';
	playertype='X';
	Label1->Caption = "It is your turn player";
	Form4->Button11->Hide();
	Form4->Button12->Hide();
	Form4->Button1->Show();
	Form4->Button2->Show();
	Form4->Button3->Show();
	Form4->Button4->Show();
	Form4->Button5->Show();
	Form4->Button6->Show();
	Form4->Button7->Show();
	Form4->Button8->Show();
	Form4->Button9->Show();

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button12Click(TObject *Sender)
{
	current = 'O';
	playertype= 'O';
    Label1->Caption = "It is your turn player";
    Form4->Button11->Hide();
	Form4->Button12->Hide();
	Form4->Button1->Show();
	Form4->Button2->Show();
	Form4->Button3->Show();
	Form4->Button4->Show();
	Form4->Button5->Show();
	Form4->Button6->Show();
	Form4->Button7->Show();
	Form4->Button8->Show();
	Form4->Button9->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button13Click(TObject *Sender)
{
	this->Close();
	Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button14Click(TObject *Sender)
{
	this->Close();
    Form6->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button15Click(TObject *Sender) {
	Button10->Hide();
	Form4->Button11->Show();
	Form4->Button12->Show();
	// Reset all buttons
    Button1->Caption = "";
    Button2->Caption = "";
    Button3->Caption = "";
    Button4->Caption = "";
    Button5->Caption = "";
    Button6->Caption = "";
    Button7->Caption = "";
    Button8->Caption = "";
    Button9->Caption = "";

    // Enable all buttons
    Button1->Enabled = true;
    Button2->Enabled = true;
    Button3->Enabled = true;
    Button4->Enabled = true;
    Button5->Enabled = true;
    Button6->Enabled = true;
    Button7->Enabled = true;
    Button8->Enabled = true;
    Button9->Enabled = true;
	Button10->Enabled = true;
	Button1->Hide();
	Button2->Hide();
	Button3->Hide();
	Button4->Hide();
	Button5->Hide();
	Button6->Hide();
	Button7->Hide();
	Button8->Hide();
	Button9->Hide();
    // Reset labels and other game state variables
    WinnerLabel->Caption = "";
    currentLabel->Caption = current;
    clickOrder.clear();
	positions = "";

    // Reset the current player to 'X'
    current = 'X';
    playertype = 'X';
	Label1->Caption = "It is your turn player";
        // Reset font properties for all buttons
	ResetButtonFonts();
}
void __fastcall TForm4::ResetButtonFonts() {
	// Reset font size and style for all buttons
	TFont *defaultFont = new TFont;
	defaultFont->Name = "Segoe UI";
	defaultFont->Size = -18;
	defaultFont->Style = TFontStyles();
	// Apply default font and width to all buttons
	TButton *buttons[] = { Button1, Button2, Button3, Button4, Button5, Button6, Button7, Button8, Button9 };
	for (TButton *button : buttons) {
		button->Font = defaultFont;
	}
	// Free the allocated font object
	delete defaultFont;
}
