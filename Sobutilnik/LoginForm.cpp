#include "LoginForm.h"
#include "ErrorMessages.h"

int Sobutilnik::LoginForm::findAccount()
{
	if (!LoginField->Text->Length || !PassField->Text->Length)
		throw std::logic_error(Errors::AllFieldMustBeFilled);
	
	
	mainPage->dbConnection->Open();
	command = gcnew OleDbCommand("SELECT * from MyDatabase where w_login like '%" + LoginField->Text + "%'", mainPage->dbConnection);
	reader = command->ExecuteReader();

	if (reader->HasRows) {
		reader->Read();

		int userId = reader->GetInt32(0);
		String^ pass = reader->GetValue(3)->ToString();
		mainPage->dbConnection->Close();

		if (pass != PassField->Text)
			throw std::logic_error(Errors::AccountNotFound);
		return userId;
	}
	throw std::logic_error(Errors::AccountNotFound);
}
