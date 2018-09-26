#include "Map.h"
#include "AnoutherAccount.h"

void Sobutilnik::Map::initLabels()
{
	mainPage->dbConnection->Open();
	command = gcnew OleDbCommand("SELECT * from MyDatabase where w_id like '%" + userId + "'", mainPage->dbConnection);
	reader = command->ExecuteReader();
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
	MainLogin->Text = reader->GetValue(4)->ToString();
	MainSex->Text = "Пол: " + sex;
	MainBirth->Text = reader->GetValue(7)->ToString();
	userDescriptionLabel->Text = reader->GetValue(10)->ToString();
	userHobbiesLabel->Text = reader->GetValue(11)->ToString();
	usersAlcoholLabel->Text = reader->GetValue(12)->ToString();
	Rating->Value = reader->GetInt32(13);
	array<byte> ^type = gcnew array<byte>(reader->GetByte(14));
	//reader->GetBytes(14, userId, type, 0, reader->GetInt32(15));//marshal_as<array<unsigned char>>(reader->GetValue(14)->ToString());
	//loadPhoto(type);

	mainPage->dbConnection->Close();
	resultListBox->Items->Add("Введите логин чтоб начать поиск");
	RatingPersent->Text = System::Convert::ToString(Rating->Value) + "%";
}

void Sobutilnik::Map::checkSearch()
{
	if (!searchField->Text->Length)
		throw std::logic_error(Errors::AllFieldMustBeFilled);

	searchResult->clear();
	mainPage->dbConnection->Open();
	command = gcnew OleDbCommand("SELECT * from MyDatabase where w_login like '%" + searchField->Text + "%'", mainPage->dbConnection);
	reader = command->ExecuteReader();
	resultListBox->Items->Clear();
	int itemCounter = 0;
	if (reader->HasRows) {
		while (reader->Read()) {
			int currentUsersId = reader->GetInt32(0);
			if (currentUsersId != userId) {
				searchResult->push_back(currentUsersId);
				resultListBox->Items->Add(reader->GetValue(1)->ToString() + " " + reader->GetValue(2)->ToString() + " " + reader->GetValue(4)->ToString());
			}
		}
		if(!resultListBox->Items->Count)
			resultListBox->Items->Add("Поиск не дал результатов:(");
	}
	mainPage->dbConnection->Close();
}

void Sobutilnik::Map::uniqUser(System::Object ^_type, const char* _error, System::Object ^_obj)
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

void Sobutilnik::Map::exitAcc()
{
	isExitButton = true;
	mainPage->Visible = true;
	this->deleteForm();
	this->Close();
}

void Sobutilnik::Map::deleteForm()
{
	if (components)
	{
		delete components;
	}
	delete profileImage;
	delete searchResult;
}

System::Void Sobutilnik::Map::Settings_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SettingsPanel->Visible = true;
	SettingsPanel->Location = System::Drawing::Point(215, 15);
	SettingsPanel->Size = System::Drawing::Size(854, 539);
	Map::Size = System::Drawing::Size(800, 515);

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

System::Void Sobutilnik::Map::Search_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	FriendsPanel->Visible = true;
	FriendsPanel->Location = System::Drawing::Point(215, 15);
	FriendsPanel->Size = System::Drawing::Size(854, 539);
	Map::Size = System::Drawing::Size(750, 430);

	profilePanel->Visible = false;
	HistoryPanel->Visible = false;
	SettingsPanel->Visible = false;
	MessagesPanel->Visible = false;
}

System::Void Sobutilnik::Map::ChangeProfileImage_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	openFileDialog1->InitialDirectory = "c:\\";
	openFileDialog1->Filter = "Image Files(*.BMP;*.JPG;*.GIF;*.PNG)|*.BMP;*.JPG;*.GIF;*.PNG";
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
	Map::Size = System::Drawing::Size(750, 430);

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
	marshal = gcnew marshal_context();

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
		for (size_t i = 0; i < fieldForChanges.size(); i++) {
			CmdRule += marshal_as<String^>(fieldForChanges[i]);
			if (i + 1 < fieldForChanges.size())
				CmdRule += ", ";
		}
		CmdRule += " WHERE w_id = @u_id";

		command = gcnew OleDbCommand();
		command->CommandType = CommandType::Text;
		command->CommandText = CmdRule;
		command->Connection = mainPage->dbConnection;

		for (size_t i = 0; i < pathFieldForChanges.size(); i++)
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
		MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {

		mainPage->dbConnection->Open();
		command = gcnew OleDbCommand();
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
		MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
		exitAcc();
	}
	else return;
	
}

System::Void Sobutilnik::Map::resultListBox_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (searchResult->size()) {
		AnoutherAccount^ userProfile = gcnew AnoutherAccount(searchResult[0][resultListBox->SelectedIndex], mainPage->dbConnection);
		userProfile->ShowDialog();
	}
}

System::Void Sobutilnik::Map::mapButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	geolocationForm = gcnew GeolocationForm();
	geolocationForm->Visible = true;
}

System::Void Sobutilnik::Map::addLinksButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	return System::Void();
}
