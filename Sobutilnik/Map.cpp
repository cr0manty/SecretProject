#include "Map.h"
#include "ErrorMessages.h"

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

void Sobutilnik::Map::editOneField(const char* _edit, System::Object ^ _object)
{
	OleDbCommand ^command = gcnew OleDbCommand();
	command->CommandType = CommandType::Text;
	command->CommandText = "UPDATE MyDatabase SET " + marshal_as<String^>(_edit) + " = @u_editField WHERE w_id = @u_id";;
	command->Parameters->AddWithValue("@u_editField", _object->ToString());
	command->Parameters->AddWithValue("@u_id", userId);
	command->Connection = mainPage->dbConnection;

	mainPage->dbConnection->Open();
	command->ExecuteNonQuery();
	mainPage->dbConnection->Close();

	MessageBox::Show(marshal_as<String^>(Errors::DataWasSucsessfulyUpdated));
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
	
}

System::Void Sobutilnik::Map::descriptionChangeButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	editOneField("w_userDescription", userDescriptionChangeField->Text);
}

System::Void Sobutilnik::Map::hobbyChangeButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	editOneField("w_userHobby",userHobbyChangeField->Text);
}

System::Void Sobutilnik::Map::drinksChangeButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	editOneField("w_userDescription", userDescriptionChangeField->Text);
}
