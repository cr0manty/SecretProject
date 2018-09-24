#include "Map.h"
#include "ErrorMessages.h"
#include <vector>

void Sobutilnik::Map::initLabels()
{
	mainPage->dbConnection->Open();
	String ^select = "SELECT * from MyDatabase where w_id like '%" + userId + "'";
	OleDbCommand ^command = gcnew OleDbCommand(select, mainPage->dbConnection);
	OleDbDataReader ^reader = command->ExecuteReader();
	reader->Read();
	String^ sex = nullptr;
	if (reader->GetValue(6)->ToString() == "M")
		sex = "Муж.";
	else sex = "Жен.";

	////////настройки///////
	userFirstName->Text = reader->GetValue(1)->ToString();
	userSurname->Text = reader->GetValue(2)->ToString();
	userLogin->Text = reader->GetValue(4)->ToString();
	userMail->Text = reader->GetValue(5)->ToString();
	userSex->Text = "Пол: " + sex;
	UserBirth->Text = reader->GetValue(7)->ToString();
	GeoPosition->Checked = reader->GetBoolean(8);
	
	////////Мой профиль////////
	MainName->Text = reader->GetValue(1)->ToString();
	MainSurname->Text = reader->GetValue(2)->ToString();
	userLogin->Text = reader->GetValue(4)->ToString();
	MainSex->Text = "Пол: " + sex;
	MainBirth->Text = reader->GetValue(7)->ToString();
	userDescriptionLabel->Text = reader->GetValue(10)->ToString();
	userHobbiesLabel->Text = reader->GetValue(11)->ToString();
	usersAlcoholLabel->Text = reader->GetValue(12)->ToString();
	RatingPersent->Text = System::Convert::ToString(Rating->Value) + "%";

	mainPage->dbConnection->Close();
}

void Sobutilnik::Map::checkSearch()
{
	if (!searchField->Text->Length)
		throw std::logic_error(Errors::AllFieldMustBeFilled);

	resultListBox->Items->Clear();
	mainPage->dbConnection->Open();
	String ^select = "SELECT * from MyDatabase where w_login like '%" + searchField->Text + "%'";
	OleDbCommand ^command = gcnew OleDbCommand(select, mainPage->dbConnection);
	OleDbDataReader ^reader = command->ExecuteReader();

	int itemCounter = 0;
	while (reader->Read()) {
		int currentUsersId = Convert::ToInt16(reader->GetValue(0)->ToString());
		searchResult->insert(std::pair<int,int>(itemCounter++, 2));
		resultListBox->Items->Add(reader->GetValue(1)->ToString() + " " + reader->GetValue(2)->ToString() + " " + reader->GetValue(4)->ToString());
	}


	mainPage->dbConnection->Close();
}

void Sobutilnik::Map::uniqUser(System::Object ^_type, const char* _error, System::Object ^_obj)
{
	mainPage->dbConnection->Open();
	String ^select = "SELECT * from MyDatabase where " + _type + " like '%" + _obj+ "%'";
	OleDbCommand ^command = gcnew OleDbCommand(select, mainPage->dbConnection);
	OleDbDataReader ^reader = command->ExecuteReader();
	reader->Read();

	if (reader->HasRows) {
		mainPage->dbConnection->Close();
		throw std::logic_error(_error);
	}
	mainPage->dbConnection->Close();

}

void Sobutilnik::Map::exitAcc()
{
	//все формы закрываются, а 1 пересоздается
}

System::Void Sobutilnik::Map::Settings_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SettingsPanel->Visible = true;
	SettingsPanel->Location = System::Drawing::Point(215, 15);
	SettingsPanel->Size = System::Drawing::Size(854, 539);

	FriendsPanel->Visible = false;
	profilePanel->Visible = false;
	HistoryPanel->Visible = false;
	MessagesPanel->Visible = false;
}

System::Void Sobutilnik::Map::Messages_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MessagesPanel->Visible = true;
	MessagesPanel->Location = System::Drawing::Point(215, 15);
	MessagesPanel->Size = System::Drawing::Size(854, 539);
	
	FriendsPanel->Visible = false;
	profilePanel->Visible = false;
	HistoryPanel->Visible = false;
	SettingsPanel->Visible = false;

}

System::Void Sobutilnik::Map::History_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	HistoryPanel->Visible = true;
	HistoryPanel->Location = System::Drawing::Point(215, 15);
	HistoryPanel->Size = System::Drawing::Size(854, 539);

	FriendsPanel->Visible = false;
	profilePanel->Visible = false;
	SettingsPanel->Visible = false;
	MessagesPanel->Visible = false;
}

System::Void Sobutilnik::Map::Friends_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	FriendsPanel->Visible = true;
	FriendsPanel->Location = System::Drawing::Point(215, 15);
	FriendsPanel->Size = System::Drawing::Size(854, 539);

	profilePanel->Visible = false;
	HistoryPanel->Visible = false;
	SettingsPanel->Visible = false;
	MessagesPanel->Visible = false;
}

System::Void Sobutilnik::Map::ChangeProfileImage_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	openFileDialog1->InitialDirectory = "c:\\";
	openFileDialog1->Filter = "Image Files(*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF";
	openFileDialog1->RestoreDirectory = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && openFileDialog1->FileName != nullptr) {
		profileImage = openFileDialog1->FileName;
		ProfileImage->Load(profileImage);
		PictureProfile->Load(profileImage);
		//Внесение в бд картинки
	}
}

System::Void Sobutilnik::Map::profileButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	profilePanel->Visible = true;
	profilePanel->Location = System::Drawing::Point(215, 15);
	FriendsPanel->Size = System::Drawing::Size(854, 539);

	FriendsPanel->Visible = false;
	HistoryPanel->Visible = false;
	SettingsPanel->Visible = false;
	MessagesPanel->Visible = false;
}

System::Void Sobutilnik::Map::saveChanges_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	std::vector<const char*> fieldForChanges;
	std::vector<const char*> Changes;
	std::vector<const char*> pathFieldForChanges;
	String^ CmdRule = "UPDATE MyDatabase SET ";
	marshal_context^ marshal = gcnew marshal_context();

	if (userDescriptionChangeField->Text->Length) {
		fieldForChanges.push_back("w_userDescription = @u_userDescription");
		Changes.push_back(marshal->marshal_as<const char*>(userDescriptionChangeField->Text));
		pathFieldForChanges.push_back("@u_userDescription");
	}

	if (userHobbyChangeField->Text->Length) {
		fieldForChanges.push_back("w_userHobby = @u_userHobby");
		Changes.push_back(marshal->marshal_as<const char*>(userHobbyChangeField->Text));
		pathFieldForChanges.push_back("@u_userHobby");
	}

	if(newSurnameField->Text->Length)
	{
		fieldForChanges.push_back("w_surname = @u_surname");
		Changes.push_back(marshal->marshal_as<const char*>(newSurnameField->Text));
		pathFieldForChanges.push_back("@u_surname");
	}

	if (newNameField->Text->Length)
	{
		fieldForChanges.push_back("w_name = @u_name");
		Changes.push_back(marshal->marshal_as<const char*>(newNameField->Text));
		pathFieldForChanges.push_back("@u_name");
	}

	if (newEmail->Text->Length)
	{
		try{
			uniqUser("w_email", Errors::EmailNotUniq, newEmail->Text);
		}
		catch (const std::exception & e)
		{
			MessageBox::Show(marshal_as<String^>(e.what()));
			return;
		}
		fieldForChanges.push_back("w_email = @u_email");
		Changes.push_back(marshal->marshal_as<const char*>(newEmail->Text));
		pathFieldForChanges.push_back("@u_email");
	}

	if (newLogin->Text->Length)
	{
		try {
			uniqUser("w_login", Errors::LoginNotUniq, newLogin->Text);
		}
		catch (const std::exception & e)
		{
			MessageBox::Show(marshal_as<String^>(e.what()));
			return;
		}
		fieldForChanges.push_back("w_email = @u_email");
		Changes.push_back(marshal->marshal_as<const char*>(newLogin->Text));
		pathFieldForChanges.push_back("@u_email");
	}

	if (userDrinksChangeField->Text->Length) {
		fieldForChanges.push_back("w_userDrinks = @u_userDrinks");
		Changes.push_back(marshal->marshal_as<const char*>(userDrinksChangeField->Text));
		pathFieldForChanges.push_back("@u_userDrinks");
	}

	if (fieldForChanges.size()) {
		for (int i = 0; i < fieldForChanges.size(); i++) {
			CmdRule += marshal_as<String^>(fieldForChanges[i]);
			if (i + 1 < fieldForChanges.size())
				CmdRule += ", ";
		}
		CmdRule += " WHERE w_id = @u_id";

		OleDbCommand ^command = gcnew OleDbCommand();
		command->CommandType = CommandType::Text;
		command->CommandText = CmdRule;
		command->Connection = mainPage->dbConnection;

		for (int i = 0; i < pathFieldForChanges.size(); i++)
			command->Parameters->AddWithValue(marshal_as<String^>(pathFieldForChanges[i]), marshal_as<String^>(Changes[i]));

		command->Parameters->AddWithValue("@u_id", userId);
		mainPage->dbConnection->Open();
		command->ExecuteNonQuery();
		mainPage->dbConnection->Close();

		MessageBox::Show(marshal_as<String^>(Errors::DataWasSucsessfulyUpdated));
		initLabels();
		return;
	}
	MessageBox::Show(marshal_as<String^>(Errors::NonFieldWasChanged));
}

System::Void Sobutilnik::Map::DeleteAcc_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (MessageBox::Show(marshal_as<String^>(Errors::ConfirmDeletAcc), "Удаление аккаунта", MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK) {

		mainPage->dbConnection->Open();
		OleDbCommand ^command = gcnew OleDbCommand();
		command->CommandType = CommandType::Text;
		command->CommandText = "DELETE FROM MyDatabase WHERE w_id = @u_id";
		command->Connection = mainPage->dbConnection;
		command->Parameters->AddWithValue("@u_id", userId);
		command->ExecuteReader();
		mainPage->dbConnection->Close();
		exitAcc();
	}
	else return;
}

System::Void Sobutilnik::Map::ExitAccount_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (MessageBox::Show(marshal_as<String^>(Errors::ExitFromAcc), "Выход из аккаунта", MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK) {
		exitAcc();
	}
	else return;
}

System::Void Sobutilnik::Map::resultListBox_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e)
{

	std::map<int, int>::iterator iter = searchResult->find(resultListBox->SelectedIndex);
	int id = int::Parse(iter->second.ToString());

	mainPage->dbConnection->Open();
	String ^select = "SELECT * from MyDatabase where w_id like '%" + id + "'";
	OleDbCommand ^command = gcnew OleDbCommand(select, mainPage->dbConnection);
	OleDbDataReader ^reader = command->ExecuteReader();
	reader->Read();

	Form^ userProfile = gcnew Form();
	userProfile->Size = System::Drawing::Size(600,400);
	userProfile->Location = Point(30,20);
	userProfile->Visible = true;
	userProfile->Text = reader->GetValue(1)->ToString()+" "+reader->GetValue(2)->ToString();

	mainPage->dbConnection->Close();
}
