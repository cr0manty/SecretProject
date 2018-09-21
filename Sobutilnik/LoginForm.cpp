#include "LoginForm.h"
#include "ErrorMessages.h"

void Sobutilnik::LoginForm::findAccount()
{
	mainPage->dbConnection->Open();
	String ^select = "SELECT * from MyDatabase where w_login like '%" + textBox1->Text + "%'";
	OleDbCommand ^command = gcnew OleDbCommand(select, mainPage->dbConnection);

	OleDbDataReader ^reader = command->ExecuteReader();
	reader->Read();

	if (!reader->HasRows) {
		mainPage->dbConnection->Close();
		throw std::logic_error(Errors::AccountNotFound);
	}
	
	String^ pass = reader->GetValue(3)->ToString();
	mainPage->dbConnection->Close();

	if (pass != textBox2->Text)
		throw std::logic_error(Errors::WrongPassword);
}
