#include "LoginForm.h"
#include "ErrorMessages.h"

void Sobutilnik::LoginForm::findAccount()
{
	if (!LoginField->Text->Length || !PassField->Text->Length)
		throw std::logic_error(Errors::AllFieldMustBeFilled);

	mainPage->dbConnection->Open();
	String ^select = "SELECT * from MyDatabase where w_login like '%" + LoginField->Text + "%'";
	OleDbCommand ^command = gcnew OleDbCommand(select, mainPage->dbConnection);
	OleDbDataReader ^reader = command->ExecuteReader();

	if (reader->HasRows) {
		reader->Read();

		String^ pass = reader->GetValue(3)->ToString();
		mainPage->dbConnection->Close();

		if (pass != PassField->Text)
			throw std::logic_error(Errors::AccountNotFound);
		return;
	}
	throw std::logic_error(Errors::AccountNotFound);
}
