#include "AnoutherAccount.h"

void Sobutilnik::AnoutherAccount::ReadyOrNot(bool _ready)
{
	if (!_ready) {
		userFirstName->ForeColor = Color::IndianRed;
		userSurname->ForeColor = Color::IndianRed;
		Invite->Enabled = false;
	}
	else {
		userFirstName->ForeColor = Color::Green;
		userSurname->ForeColor = Color::Green;
	}
}

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
	command = gcnew OleDbCommand("SELECT * from MyDatabase where w_id like @u_id", dbConnection);
	command->Parameters->AddWithValue("@u_id", friendID);
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
	ReadyOrNot(reader->GetBoolean(9));
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
	command = gcnew OleDbCommand();
	command->CommandType = CommandType::Text;
	command->Connection = dbConnection;

	if (type == NotFriend) {
		
		command->CommandText = "INSERT INTO Friends (w_userId, w_friendId, w_frRequest) VALUES (@u_userId, @u_firendId, @u_frRequest)";
		command->Parameters->AddWithValue("@u_userId", myId);
		command->Parameters->AddWithValue("@u_firendId", friendID);
		command->Parameters->AddWithValue("@u_frRequest", myId);
		command->ExecuteReader();
		dbConnection->Close();
		MessageBox::Show("Заявка успешно отправлена!");
		AddDeleteFriend->Text = "Отменить заявку";
		return;
	}
	else {
		command->CommandText = "DELETE FROM Friends WHERE (w_userId = @u_id AND w_friendId = @u_friendId) or\
			 (w_userId = @u_friendId AND w_friendId = @u_id)";
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
	this->Close();
}
