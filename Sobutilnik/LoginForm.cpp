#include "LoginForm.h"
#include "ErrorMessages.h"

void Sobutilnik::LoginForm::findAccount()
{
	mainPage->dbConnection->Open();
	String ^select = "SELECT * from MyDatabase where w_login like '%" + LoginField->Text + "%'";
	OleDbCommand ^command = gcnew OleDbCommand(select, mainPage->dbConnection);
	OleDbDataReader ^reader = command->ExecuteReader();
	
	if (!LoginField->Text->Length || !PassField->Text->Length) {
		mainPage->dbConnection->Close();
		throw std::logic_error(Errors::AllFieldMustBeFilled);
	}
	reader->Read();

	String^ pass = reader->GetValue(3)->ToString();
	mainPage->dbConnection->Close();

	if (pass != PassField->Text)
		throw std::logic_error(Errors::AccountNotFound);
}
