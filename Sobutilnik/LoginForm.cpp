#include "LoginForm.h"

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
	mainPage->dbConnection->Close();
	throw std::logic_error(Errors::AccountNotFound);
}

System::Void Sobutilnik::LoginForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	int userId;
	try
	{
		userId = findAccount();
	}
	catch (const std::exception & e)
	{
		MessageBox::Show(marshal_as<String^>(e.what()));
		return;
	}
	mainPage->Visible = false;
	NewForm = gcnew Map(mainPage, userId);

	this->Visible = false;
	NewForm->ShowDialog();
	this->Close();
}