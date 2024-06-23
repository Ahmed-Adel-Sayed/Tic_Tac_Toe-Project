#include <vcl.h>
#pragma hdrstop
#include "HomePage.h"
#include "Register.h"
#include "Login.h"
#include <regex> // for regular expressions
#include <sstream> // Add this header for std::stringstream
#include <iomanip> // Add this header for std::setw and std::setfill

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;


// Function to validate email format
bool isValidEmail(const AnsiString& email) {
	// Regular expression for email validation
	const std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
	return std::regex_match(email.c_str(), pattern);
}

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

void saveUserDetails(const AnsiString& email, const AnsiString& username, const AnsiString& password) {
	// Hash the password
	AnsiString hashedPassword = hashPassword(password);

    	// Check if the email or username already exists in the database
	Form2->UsersTable->SQL->Text = "SELECT COUNT(*) FROM users WHERE email = :email OR username = :username";
	Form2->UsersTable->Params->ParamByName("email")->AsString = email;
	Form2->UsersTable->Params->ParamByName("username")->AsString = username;
	Form2->UsersTable->Open();

	int userCount = Form2->UsersTable->Fields->Fields[0]->AsInteger;
	Form2->UsersTable->Close();

	if (userCount > 0) {
		ShowMessage("Email or username already exists. Please choose a different one.");
		return;
	}

	// Insert user details into the database
	// Assuming UsersTable is a TFDQuery component
	Form2->UsersTable->SQL->Text = "INSERT INTO users (email, username, userpassword) VALUES (:email, :username, :password)";

	Form2->UsersTable->Params->ParamByName("password")->AsString = hashedPassword;
	//Form2->UsersTable->Params->ParamByName("password")-> AsString = password;
	Form2->UsersTable->Params->ParamByName("username")->AsString = username;
	Form2->UsersTable->Params->ParamByName("email")->AsString = email;

	try {

	// Debugging statements
		ShowMessage("Inserting user details:");
		/*ShowMessage("Email: " + email);
		ShowMessage("Username: " + username);
		ShowMessage("Hashed Password: " + hashedPassword);*/
        Form2->UsersTable->ExecSQL();
		ShowMessage("Registered successfully");
    } catch (const Exception& e) {
		ShowMessage("Error inserting registration info: " + e.Message);
	}
}

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{

}

void __fastcall TForm2::Button1Click(TObject *Sender)
{


	AnsiString email = Edit1->Text.Trim();
	AnsiString username = Edit2->Text.Trim();
	AnsiString password = Edit3->Text.Trim();

    // Check if the password length is less than 5 characters
    if (password.Length() < 5) {
		ShowMessage("Choose a longer password.");
        return;
	}

	if (!isValidEmail(email)) {
		ShowMessage("Invalid email format.");
		return;
	}

	saveUserDetails(email, username, password);

	Edit1->Text=" ";
	Edit2->Text=" ";
	Edit3->Text=" ";


	this->Close();
	Hide();
	Form1->Show();
}
//---------------------------------------------------------------------------



