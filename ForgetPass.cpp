#include <vcl.h>
#pragma hdrstop

#include "ForgetPass.h"
#include <iostream>
#include <iomanip> // for setw, setfill
#include <sstream> // for stringstream
#include <functional> // for hash
#include <regex> // for regular expressions
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
 // Function to hash the password
AnsiString hashPassword(const AnsiString& password) {
	std::hash<std::string> hasher;
	size_t hashed = hasher(password.c_str());
	std::stringstream ss;
	ss << std::setw(16) << std::setfill('0') << std::hex << hashed; // Convert hash to hexadecimal string
	return ss.str().c_str();
}

//---------------------------------------------------------------------------
void __fastcall TForm7::Button1Click(TObject *Sender)
{
    AnsiString identifier = Edit1->Text.Trim();
	AnsiString newPassword = Edit2->Text.Trim();
	AnsiString hashedPassword = hashPassword(newPassword);

	AnsiString sql = "SELECT * FROM USERS WHERE EMAIL = '" + identifier + "' OR USERNAME = '" + identifier + "'";
	Form7->UsersTable->SQL->Text = sql;

	try {
		Form7->UsersTable->Open();
		if (!Form7->UsersTable->IsEmpty()) {
			AnsiString currentPasswordHash = Form7->UsersTable->FieldByName("USERPASSWORD")->AsString;
			if (currentPasswordHash == hashedPassword) {
				ShowMessage("The new password cannot be the same as the old password.");
			} else {
				Form7->UsersTable->Edit();
				Form7->UsersTable->FieldByName("USERPASSWORD")->AsString = hashedPassword;
				Form7->UsersTable->Post();
				ShowMessage("Password has been reset successfully.");
				// Clear the edit cells after success
				Edit1->Text = "";
				Edit2->Text = "";
			}
		} else {
			ShowMessage("User not found.");
			// Clear the edit cells after user not found
			Edit1->Text = "";
			Edit2->Text = "";
		}
	} catch (Exception& ex) {
		ShowMessage("Error: " + ex.Message);
		// Clear the edit cells after an error
		Edit1->Text = "";
		Edit2->Text = "";
	}

	Form7->UsersTable->Close();
	Form7->Hide();
}


