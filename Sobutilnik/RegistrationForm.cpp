#include "RegistrationForm.h"

void Sobutilnik::RegistrationForm::uniqUser(System::Object ^ _type, const char * _error, System::Object ^ _obj)
{
	mainPage->dbConnection->Open();
	command = gcnew OleDbCommand("SELECT * from MyDatabase where " + _type + " like '%" + _obj + "%'", mainPage->dbConnection);
	reader = command->ExecuteReader();
	reader->Read();

	if (reader->HasRows) {
		mainPage->dbConnection->Close();
		throw std::logic_error(_error);
	}
	mainPage->dbConnection->Close();
}


void Sobutilnik::RegistrationForm::fieldCheck()
{
	/*String ^buffer;
	///empty check
	if (!nameTextBox->Text->Length || !surnameTextBox->Text->Length || !passwordTextBox->Text->Length ||
		!passwordCheckTextBox->Text->Length || !SexFem->Checked && !SexMale->Checked)
		throw std::logic_error(Errors::AllFieldMustBeFilled);

	///password
	buffer = passwordTextBox->Text;
	if (isdigit(buffer[0]) || islower(buffer[0]))
		throw std::logic_error(Errors::PasswordFirstSymbol);
	if (buffer->Length < 8)
		throw std::logic_error(Errors::PasswordToSmall);
	if (buffer != passwordCheckTextBox->Text)
		throw std::logic_error(Errors::PasswordNotEqual);

	///age
	if (monthCalendar1->TodayDate.Year - monthCalendar1->SelectionRange->Start.Year < 18)
		throw std::logic_error(Errors::UserTooYong);

	if (monthCalendar1->TodayDate.Year - monthCalendar1->SelectionRange->Start.Year == 18) {
		if (monthCalendar1->TodayDate.DayOfYear > monthCalendar1->SelectionRange->Start.DayOfYear)
			throw std::logic_error(Errors::UserTooYong);
	}
	///login
	if (loginTextBox->Text->Length < 5)
		throw std::logic_error(Errors::LoginToSmall);
	uniqUser("w_login", Errors::LoginNotUniq, loginTextBox->Text);
	///email
	if (emailTextBox->Text->Length < 5)
		throw std::logic_error(Errors::LoginToSmall);
	uniqUser("w_email", Errors::EmailNotUniq, emailTextBox->Text);*/
}

