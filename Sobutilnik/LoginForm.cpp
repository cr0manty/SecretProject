#include "LoginForm.h"
#include "ErrorMessages.h"

void Sobutilnik::LoginForm::findAccount()
{
	mainPage->dbConnection->Open();
	OleDbCommand ^command = gcnew OleDbCommand();
	command->CommandType = CommandType::Text;
	command->Connection = mainPage->dbConnection;
	command->CommandText = "SELECT * from MyDatabase where w_login like '@u_login'";
	command->Parameters->AddWithValue("@u_login", textBox1->Text);

	OleDbDataReader ^myOleDbDataReader = command->ExecuteReader();
	String^ pass = myOleDbDataReader->GetString(0);//сравнить строку w_pass с textbox2 
	mainPage->dbConnection->Close();

	if (pass != textBox2->Text)
		throw std::logic_error(Errors::AccountNotFound);
}
