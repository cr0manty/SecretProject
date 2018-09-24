#include "RegistrationForm.h"
#include "LoginForm.h"

System::Void Sobutilnik::FirstPage::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Visible = false;
	newMap = gcnew Map(this);
	
	newMap->ShowDialog();

}

System::Void Sobutilnik::FirstPage::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	newRegistr = gcnew RegistrationForm(this);
	newRegistr->ShowDialog();
}

System::Void Sobutilnik::FirstPage::button3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	newLogin = gcnew LoginForm(this);
	newLogin->ShowDialog();
}
