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
	SettingsPanel->Location = System::Drawing::Point(580, 10);
}

System::Void Sobutilnik::Map::Messages_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MessagesPanel->Visible = true;
	MessagesPanel->Location = System::Drawing::Point(580, 10);
}

System::Void Sobutilnik::Map::History_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	HistoryPanel->Visible = true;
	HistoryPanel->Location = System::Drawing::Point(580, 10);
}

System::Void Sobutilnik::Map::Friends_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	FriendsPanel->Visible = true;
	FriendsPanel->Location = System::Drawing::Point(580, 10);
}

System::Void Sobutilnik::Map::SettingsCloseButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SettingsPanel->Visible = false;
}

System::Void Sobutilnik::Map::MessagesCloseButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MessagesPanel->Visible = false;
}

System::Void Sobutilnik::Map::HistoryCloseButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	HistoryPanel->Visible = false;
}

System::Void Sobutilnik::Map::FriendsCloseButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	FriendsPanel->Visible = false;
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
