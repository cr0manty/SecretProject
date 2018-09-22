#include "LoginForm.h"
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

System::Void Sobutilnik::RegistrationForm::button3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Visible = false;
	LoginForm ^NewForm = gcnew LoginForm(mainPage);
	NewForm->ShowDialog();
	mainPage->dbConnection->Open();
	OleDbCommand ^command = gcnew OleDbCommand();
	command->CommandType = CommandType::Text;
	command->CommandText = "INSERT INTO MyDatabase (w_name,w_surname,w_password,w_login,w_email,w_sex,w_birthday,w_geolocation) \
		VALUES (@u_name,@u_surname,@u_password,@u_login,@u_email, @u_sex,@u_birthday,@u_geolocation)";
	command->Connection = mainPage->dbConnection;
	command->Parameters->AddWithValue("@u_name", nameTextBox->Text);
	command->Parameters->AddWithValue("@u_surname", surnameTextBox->Text);
	command->Parameters->AddWithValue("@u_password", passwordTextBox->Text);
	command->Parameters->AddWithValue("@u_login", loginTextBox->Text);
	command->Parameters->AddWithValue("@u_email", emailTextBox->Text);

	if (SexFem->Checked)
		command->Parameters->AddWithValue("@u_sex", "F");
	else
		command->Parameters->AddWithValue("@u_sex", "M");

	command->Parameters->AddWithValue("@u_birthday", monthCalendar1->SelectionRange->Start.ToShortDateString());
	command->Parameters->AddWithValue("@u_geolocation", locationCheckBox->Checked);
	command->ExecuteNonQuery();
	mainPage->dbConnection->Close();
	
}

void Sobutilnik::RegistrationForm::fieldCheck()
{
	String ^buffer;
	///empty check
	if (!nameTextBox->Text->Length || !surnameTextBox->Text->Length || !passwordTextBox->Text->Length || 
		!passwordCheckTextBox->Text->Length || !SexFem->Checked && !SexMale->Checked )
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
	///email and login
	if (loginTextBox->Text->Length < 5)
		throw std::logic_error(Errors::LoginToSmall);
	checkInfo();
}

