#include "RegistrationForm.h"
#include "LoginForm.h"

System::Void Sobutilnik::FirstPage::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Visible = false;
	Map ^newForm = gcnew Map(this); 
	
	newForm->ShowDialog();
	//this->Close();

}

System::Void Sobutilnik::FirstPage::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	RegistrationForm^ form = gcnew RegistrationForm(this);
	form->ShowDialog();
}

System::Void Sobutilnik::FirstPage::button3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LoginForm^ form = gcnew LoginForm(this);
	form->ShowDialog();
}
