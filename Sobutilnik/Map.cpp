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
	mainPage->dbConnection->Open();
	String^ update = "UPDATE MyDatabase SET w_userDescription = '%" + userDescriptionChangeField->Text + "%' WHERE w_name like Sasha";
	OleDbCommand ^command = gcnew OleDbCommand(update, mainPage->dbConnection);
	//command->CommandType = CommandType::Text;
	//command->CommandText = 
	//command->Parameters->AddWithValue("@u_userDescription", userDescriptionChangeField->Text);
	//
	//command->Connection = mainPage->dbConnection;
	
	command->ExecuteNonQuery(); 
	MessageBox::Show("Update Success!");
	mainPage->dbConnection->Close();
	/*mainPage->dbConnection->Open();
	OleDbCommand ^command = gcnew OleDbCommand();
	command->CommandType = CommandType::Text;
	command->Connection = mainPage->dbConnection;
	command->CommandText = "UPDATE MyDatabase SET w_userDescription = "+ userDescriptionChangeField->Text + " WHERE w_name = Sasha";
	
	command->ExecuteNonQuery(); " + userDescriptionChangeField->Text + "
	mainPage->dbConnection->Close();*/
}

System::Void Sobutilnik::Map::button3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	return System::Void();
}

System::Void Sobutilnik::Map::button4_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	return System::Void();
}

