#include "AnoutherAccount.h"

Sobutilnik::UserType Sobutilnik::AnoutherAccount::friendOrNo()
{
	dbConnection->Open();
	command = gcnew OleDbCommand("SELECT * from Friends where(w_userId = @u_id AND w_friendId = @u_friendId) or\
			 (w_userId = @u_friendId AND w_friendId = @u_id)", dbConnection);
	command->Parameters->AddWithValue("@u_id", myId);
	command->Parameters->AddWithValue("@u_friendId", friendID);
	reader = command->ExecuteReader();
	reader->Read();
	if (reader->HasRows) {
		if (reader->GetBoolean(2) == false) {
			AddDeleteFriend->Text = "Отменить заявку";
			dbConnection->Close();
			return Request;
		}
		else {
			AddDeleteFriend->Text = "Удалить друга";
			dbConnection->Close();
			return Friend;
		}
	}
	AddDeleteFriend->Text = "Добавить в друзья";
	dbConnection->Close();
	return NotFriend;
}

System::Void Sobutilnik::AnoutherAccount::AnoutherAccount_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	dbConnection->Open();
	command = gcnew OleDbCommand("SELECT * from MyDatabase where w_id like '%" + friendID + "'", dbConnection);
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
	RatingPersent->Text = Rating->Value.ToString() + "%";
	dbConnection->Close();
}

System::Void Sobutilnik::AnoutherAccount::AddDeleteFriend_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	dbConnection->Open();
	if (type == NotFriend) {
		
		command = gcnew OleDbCommand("INSERT INTO Friends (w_userId, w_friendId) VALUES (@u_userId, @u_firendId)", dbConnection);
		MessageBox::Show("Заявка успешно отправлена!");
		AddDeleteFriend->Text = "Отменить заявку";
	}
	else {
		command = gcnew OleDbCommand("DELETE FROM Friends WHERE (w_userId = @u_id AND w_friendId = @u_friendId) or\
			 (w_userId = @u_friendId AND w_friendId = @u_id)", dbConnection);
		if (type == Request) {
			MessageBox::Show("Заявка отменена!");
			AddDeleteFriend->Text = "Добавить в друзья";
		}
		else {

			MessageBox::Show("Друг удален!");
			AddDeleteFriend->Text = "Добавить в друзья";
		}

	}
	command->Parameters->AddWithValue("@u_userId", myId);
	command->Parameters->AddWithValue("@u_firendId", friendID);

	command->ExecuteReader();
	dbConnection->Close();
}
