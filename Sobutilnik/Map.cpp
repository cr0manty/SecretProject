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

	userFirstName->Text = reader->GetValue(1)->ToString();
	UserName->Text = reader->GetValue(1)->ToString();
	userSurname->Text = reader->GetValue(2)->ToString();
	userLogin->Text = reader->GetValue(4)->ToString();
	userMail->Text = reader->GetValue(5)->ToString();
	userSex->Text = "Пол: " + reader->GetValue(6)->ToString();
	GeoPosition->Checked = reader->GetBoolean(8);
	userDescriptionLabel->Text = reader->GetValue(10)->ToString();
	userHobbiesLabel->Text = reader->GetValue(11)->ToString();
	usersAlcoholLabel->Text = reader->GetValue(12)->ToString();
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

	while (reader->Read()) {
		String^ name = reader->GetValue(1)->ToString();
		String^ surname = reader->GetValue(2)->ToString();
		String^ login = reader->GetValue(4)->ToString();

		resultListBox->Items->Add(name + " " + surname + " " + login + "\n");
	}
	mainPage->dbConnection->Close();
}

System::Void Sobutilnik::Map::Settings_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SettingsPanel->Visible = true;
	SettingsPanel->Location = System::Drawing::Point(215, 15);

	FriendsPanel->Visible = false;
	profilePanel->Visible = false;
	HistoryPanel->Visible = false;
	MessagesPanel->Visible = false;
}

System::Void Sobutilnik::Map::Messages_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MessagesPanel->Visible = true;
	MessagesPanel->Location = System::Drawing::Point(215, 15);
	
	FriendsPanel->Visible = false;
	profilePanel->Visible = false;
	HistoryPanel->Visible = false;
	SettingsPanel->Visible = false;

}

System::Void Sobutilnik::Map::History_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	HistoryPanel->Visible = true;
	HistoryPanel->Location = System::Drawing::Point(215, 15);

	FriendsPanel->Visible = false;
	profilePanel->Visible = false;
	SettingsPanel->Visible = false;
	MessagesPanel->Visible = false;
}

System::Void Sobutilnik::Map::Friends_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	FriendsPanel->Visible = true;
	FriendsPanel->Location = System::Drawing::Point(215, 15);

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

	FriendsPanel->Visible = false;
	HistoryPanel->Visible = false;
	SettingsPanel->Visible = false;
	MessagesPanel->Visible = false;
}

System::Void Sobutilnik::Map::saveChanges_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	/*String^ CmdRule = "UPDATE MyDatabase SET ";
	marshal_context^ marshal = gcnew marshal_context();

	if (userDescriptionChangeField->Text->Length) {
		CmdRule += "w_userDescription = @u_userDescription";
	}

	if (userHobbyChangeField->Text->Length) {
		CmdRule += "w_userHobby = @u_userHobby";
	}

	if (userHobbyChangeField->Text->Length) {
		CmdRule += "w_userDrinks = @u_userDrinks";
	}
	

	CmdRule += " WHERE w_id = @u_id";
	OleDbCommand ^command = gcnew OleDbCommand();
	command->CommandType = CommandType::Text;
	command->CommandText = CmdRule;
	command->Connection = mainPage->dbConnection;
	if (userDescriptionChangeField->Text->Length)
		command->Parameters->AddWithValue("@u_userDescription", userDescriptionChangeField->Text);
	command->Parameters->AddWithValue("@u_id", userId);
	mainPage->dbConnection->Open();
	command->ExecuteNonQuery();
	mainPage->dbConnection->Close();

	MessageBox::Show(marshal_as<String^>(Errors::DataWasSucsessfulyUpdated));

	return;
	throw std::logic_error(Errors::NonFieldWasChanged);*/
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
	throw std::logic_error(Errors::NonFieldWasChanged);
}