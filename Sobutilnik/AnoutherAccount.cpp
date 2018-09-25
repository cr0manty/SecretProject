#include "AnoutherAccount.h"

System::Void Sobutilnik::AnoutherAccount::AnoutherAccount_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	dbConnection->Open();
	command = gcnew OleDbCommand("SELECT * from MyDatabase where w_id like '%" + userID + "'", dbConnection);
	reader = command->ExecuteReader();
	reader->Read();

	String^ sex = nullptr;
	if (reader->GetValue(6)->ToString() == "M")
		sex = "Муж.";
	else sex = "Жен.";
	AnoutherAccount::Text = "Account login: " + reader->GetValue(4)->ToString();
	userFirstName->Text = reader->GetValue(1)->ToString();
	userSurname->Text = reader->GetValue(2)->ToString();
	userLogin->Text = reader->GetValue(4)->ToString();
	userSex->Text = "Пол: " + sex;
	UserBirth->Text = reader->GetValue(7)->ToString();
	userDescriptionLabel->Text = reader->GetValue(10)->ToString();
	userHobbiesLabel->Text = reader->GetValue(11)->ToString();
	usersAlcoholLabel->Text = reader->GetValue(12)->ToString();
	Rating->Value = reader->GetInt32(13);
	RatingPersent->Text = System::Convert::ToString(Rating->Value) + "%";
	FriendOrNot->Text = reader->GetValue(1)->ToString();
	if(!true) //если друг, то не работает
		FriendOrNot->Text += " не";
	FriendOrNot->Text += " является вашим другом";
	dbConnection->Close();
}
