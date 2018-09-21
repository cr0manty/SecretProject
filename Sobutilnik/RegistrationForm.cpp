#include "RegistrationForm.h"
#include "ErrorMessages.h"

void Sobutilnik::RegistrationForm::checkInfo()
{
	mainPage->dbConnection->Open();
	String ^select = "SELECT * from MyDatabase where w_login like '%" + loginTextBox->Text + "%'";
	OleDbCommand ^command = gcnew OleDbCommand(select, mainPage->dbConnection);
	OleDbDataReader ^reader = command->ExecuteReader();
	//я не понимаю почему оно работает, но оно работает корректно для логина и email, значит не нужно это трогать
	if (reader->HasRows) {
		mainPage->dbConnection->Close();
		throw std::logic_error(Errors::EmailOrLoginNotUniq);
	}
	mainPage->dbConnection->Close();
}

void Sobutilnik::RegistrationForm::fieldCheck()
{
	String ^buffer;
	///username
	if (!nameTextBox->Text->Length)
		throw std::logic_error(Errors::FirstnameEmpty);

	///surname
	if (!surnameTextBox->Text->Length)
		throw std::logic_error(Errors::SurnameEmpty);

	///password
	buffer = passwordTextBox->Text;
	if (!buffer->Length || !passwordCheckTextBox->Text->Length)
		throw std::logic_error(Errors::PasswordIsEmpty);
	if (isdigit(buffer[0]) || islower(buffer[0]))
		throw std::logic_error(Errors::PasswordFirstSymbol);
	if (buffer->Length < 8)
		throw std::logic_error(Errors::PasswordToSmall);
	if (buffer != passwordCheckTextBox->Text)
		throw std::logic_error(Errors::PasswordNotEqual);

	///age

	///sex
	if(!SexFem->Checked && !SexMale->Checked)
		throw std::logic_error(Errors::SexNotChoosen);

	///email and login
	if (loginTextBox->Text->Length < 5)
		throw std::logic_error(Errors::LoginToSmall);
	checkInfo();
}

