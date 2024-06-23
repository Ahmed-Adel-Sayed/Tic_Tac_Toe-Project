#include <vcl.h>
#pragma hdrstop
#include "Register.h"
#include "HomePage.h"
#include "Login.h"
#include "ForgetPass.h"
#include <iostream>
#include <iomanip> // for setw, setfill
#include <sstream> // for stringstream
#include <functional> // for hash
#include <regex> // for regular expressions
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Hide();
	Form2->Show();
}
//---------------------------------------------------------------------------

// Function to hash the password
AnsiString hashPassword(const AnsiString& password) {
	// You should implement your own secure password hashing function here
	// For demonstration purposes, let's assume a simple hashing using concatenation
	std::hash<std::string> hasher;
	size_t hashed = hasher(password.c_str());
	std::stringstream ss;
	ss << std::setw(16) << std::setfill('0') << std::hex << hashed; // Convert hash to hexadecimal string
	return ss.str().c_str();
}

bool loginUser( const AnsiString& identifier, const AnsiString& password) {

	AnsiString sql = "SELECT USERPASSWORD , ID FROM USERS WHERE EMAIL = '" + identifier + "' OR USERNAME = '" + identifier + "'";
    // Set the SQL query for the query component
   Form1->UsersTable->SQL->Text = sql;

    try {
		Form1->UsersTable->Open();
		if (!Form1->UsersTable->IsEmpty()) {
			AnsiString dbHashedPassword = Form1->UsersTable->FieldByName("USERPASSWORD")->AsString;

			AnsiString inputHashedPassword = hashPassword(password);
			/*ShowMessage("Hashed Password: " + inputHashedPassword);
			ShowMessage("DbHashed Password: " + dbHashedPassword);*/

			if (dbHashedPassword == inputHashedPassword) {
				ShowMessage("Login successful.");
			    Form1->ID = Form1->UsersTable->FieldByName("ID")->AsInteger;
				Form1->UsersTable->Close();
				return true;
            } else {
				ShowMessage("Incorrect password.");
            }
        } else {
			ShowMessage("User not found.");
        }
    } catch (Exception& ex) {
        ShowMessage("Error: " + ex.Message);
    }

	Form1->UsersTable->Close();
	return false;

}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	// Handle login button click
	AnsiString identifier = Edit1->Text.Trim(); // Assuming Edit1 is where the user enters their email/username
	AnsiString password = Edit2->Text.Trim(); // Assuming Edit2 is where the user enters their password

	// Call the loginUser function
	bool loggedIn = loginUser(identifier, password);

	Edit1->Text="";
	Edit2->Text="";

	if (loggedIn) {

	   Hide();// Hide the current form and show another form or perform any other action
		Form3->Show();  // Assuming Form3 is your main application form after login

	} else {
		ShowMessage("Login failed. Please check your credentials.");
	}

}
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  Form7->Show();
}
//---------------------------------------------------------------------------


