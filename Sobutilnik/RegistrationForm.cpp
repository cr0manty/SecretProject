#include "RegistrationForm.h"
#include "ErrorMessages.h"

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

	///email
	emailCheck();

	///login
	buffer = loginTextBox->Text;
	if (buffer->Length < 5)
		throw std::logic_error(Errors::LoginToSmall);
	loginCheck();

	///age

	///sex
	if(!SexFem->Checked && !SexMale->Checked)
		throw std::logic_error(Errors::SexNotChoosen);
}

void Sobutilnik::RegistrationForm::loginCheck()
{
	//loginTextBox->Text;
	//проверка базы на нахождение такого логина
	//если нет -return
	throw std::logic_error(Errors::LoginlNotUniq);
}

void Sobutilnik::RegistrationForm::emailCheck()
{
	//emailTextBox->Text
	//проверка базы на нахождение такого email
	//если нет -return
	throw std::logic_error(Errors::EmailNotUniq);
}

