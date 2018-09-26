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

System::Void Sobutilnik::RegistrationForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	try
	{
		fieldCheck();
	}
	catch (const std::exception & e)
	{
		MessageBox::Show(marshal_as<String^>(e.what()));
		return;
	}
	locationCheckBox->Visible = false;
	this->ProfilePicture->Location = System::Drawing::Point(0, 0);
	ProfilePicture->Visible = true;
}

System::Void Sobutilnik::RegistrationForm::button3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	mainPage->dbConnection->Open();
	command = gcnew OleDbCommand();
	command->CommandType = CommandType::Text;
	command->CommandText = "INSERT INTO MyDatabase (w_name,w_surname,w_password,w_login,w_email,w_sex,w_birthday,w_geolocation,w_picture) \
		VALUES (@u_name,@u_surname,@u_password,@u_login,@u_email, @u_sex,@u_birthday,@u_geolocation,@u_picture)";
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
	if (ms != nullptr)
		command->Parameters->AddWithValue("@u_picture", ms->GetBuffer());
	else command->Parameters->AddWithValue("@u_picture", "NULL");

	command->ExecuteNonQuery();
	mainPage->dbConnection->Close();

	MessageBox::Show(marshal_as<String^>(Errors::SucsessfulReg));
	mainPage->Visible = true;
	this->Close();
}

System::Void Sobutilnik::RegistrationForm::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	openFileDialog1->InitialDirectory = "c:\\";
	openFileDialog1->Filter = "Image Files(*.BMP;*.JPG;*.GIF;*.PNG)|*.BMP;*.JPG;*.GIF;*.PNG";
	openFileDialog1->RestoreDirectory = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && openFileDialog1->FileName != nullptr) {
		ms = gcnew MemoryStream();
		SetProfilePicture->Image->Save(ms, SetProfilePicture->Image->RawFormat);
	}
}

void Sobutilnik::RegistrationForm::fieldCheck()
{
	String ^buffer;
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
	uniqUser("w_email", Errors::EmailNotUniq, emailTextBox->Text);
}

