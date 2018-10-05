#include "Map.h"
#include "AnoutherAccount.h"

//друзья и поиск
System::Void Sobutilnik::Map::resultListBox_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (searchResult->size() && searchButton->Visible) {
		AnoutherAccount^ userProfile = gcnew AnoutherAccount(searchResult[0][resultListBox->SelectedIndex], userId, false);
		userProfile->ShowDialog();
	}
	else if (friends->size()) {
		if (!friends[0][resultListBox->SelectedIndex].second && !checkRequest(friends[0][resultListBox->SelectedIndex].first)) {
			if (MessageBox::Show(" ", "Добавить пользователч в друзья?", MessageBoxButtons::YesNo) ==
				System::Windows::Forms::DialogResult::Yes)
				AcceptFriendReq(true, friends[0][resultListBox->SelectedIndex].first);
			else AcceptFriendReq(false, friends[0][resultListBox->SelectedIndex].first);
			checkFriends();
		}
		else {
			AnoutherAccount^ userProfile = gcnew AnoutherAccount(friends[0][resultListBox->SelectedIndex].first, userId,
				friends[0][resultListBox->SelectedIndex].second);
			userProfile->ShowDialog();
			checkFriends();
		}
	}
}

void Sobutilnik::Map::checkSearch()
{
	if (!searchField->Text->Length)
		throw std::logic_error(Errors::AllFieldMustBeFilled);

	searchResult->clear();
	dbConnection->Open();
	command = gcnew OleDbCommand("SELECT * from MyDatabase where w_login like @u_login", dbConnection);
	command->Parameters->AddWithValue("@u_login", searchField->Text);
	reader = command->ExecuteReader();
	resultListBox->Items->Clear();
	if (reader->HasRows) {
		while (reader->Read()) {
			int currentUsersId = reader->GetInt32(0);
			if (currentUsersId != userId) {
				searchResult->push_back(currentUsersId);
				resultListBox->Items->Add(reader->GetValue(1)->ToString() + " " + reader->GetValue(2)->ToString() + " " + reader->GetValue(4)->ToString());
			}
		}
		if (!resultListBox->Items->Count)
			resultListBox->Items->Add("Поиск не дал результатов:(");
	}
	dbConnection->Close();
}

std::vector<std::pair<int, bool>> Sobutilnik::Map::findFriends()
{
	std::vector<std::pair<int, bool>> friends;
	command = gcnew OleDbCommand("SELECT * from Friends where w_userId like @u_id", dbConnection);
	command->Parameters->AddWithValue("@u_id", userId);
	dbConnection->Open();
	reader = command->ExecuteReader();
	while (reader->Read())
		friends.push_back(std::make_pair<int, bool>(reader->GetInt32(1), reader->GetBoolean(2)));

	command = gcnew OleDbCommand("SELECT * from Friends where w_friendId like @u_id", dbConnection);
	command->Parameters->AddWithValue("@u_id", userId);
	reader = command->ExecuteReader();
	while (reader->Read())
		if(reader->GetInt32(0) != userId )
			friends.push_back(std::make_pair<int, bool>(reader->GetInt32(0), reader->GetBoolean(2)));

	dbConnection->Close();
	return friends;
}

bool Sobutilnik::Map::checkFriendList(int _friendId, std::vector<std::pair<int, bool>> friends)
{
	for (auto i : friends)
		if (i.first == _friendId)
			return true;
	return false;
}

bool Sobutilnik::Map::checkRequest(int _friendId)
{
	command = gcnew OleDbCommand("SELECT * from Friends where (w_userId = @u_id AND w_friendId = @u_friendId) or\
			 (w_userId = @u_friendId AND w_friendId = @u_id)", dbConnection);
	command->Parameters->AddWithValue("@u_id", userId);
	command->Parameters->AddWithValue("@u_friendId", _friendId);
	dbConnection->Open();
	reader = command->ExecuteReader();
	reader->Read();
	if (reader->GetInt32(3) == userId) {
		dbConnection->Close();
		return true;
	}
	dbConnection->Close();
	return false;
}

void Sobutilnik::Map::checkFriends()
{
	label11->Text = "Друзья:";
	searchButton->Visible = false;
	searchField->Visible = false;
	friends = new std::vector<std::pair<int, bool>>(findFriends());
	resultListBox->Items->Clear();

	if (friends->size())
		for (auto i : friends[0]) {
			command = gcnew OleDbCommand("SELECT * from MyDatabase where w_id like @u_id", dbConnection);
			command->Parameters->AddWithValue("@u_id", i.first);
			dbConnection->Open();
			reader = command->ExecuteReader();
			reader->Read();
			String ^listBoxText = reader->GetValue(1)->ToString() + " " + reader->GetValue(2)->ToString() + " " + reader->GetValue(4)->ToString();
			if (!i.second)
				listBoxText += "   [Req]";
			resultListBox->Items->Add(listBoxText);
			dbConnection->Close();
		}
	else {
		resultListBox->Items->Add("В вашем списке друзей пусто:(");
		dbConnection->Close();
	}
}

void Sobutilnik::Map::AcceptFriendReq(bool _accept, int _friendId)
{
	dbConnection->Open();
	if (_accept) {
		command = gcnew OleDbCommand("UPDATE Friends SET w_isFriend = @u_isFriend WHERE (w_userId = @u_id AND w_friendId = @u_friendId) or\
			 (w_userId = @u_friendId AND w_friendId = @u_id)", dbConnection);
		command->Parameters->AddWithValue("@u_isFriend", true);
		MessageBox::Show("Заявка принята!");
	}

	else {
		command = gcnew OleDbCommand("DELETE FROM Friends WHERE (w_userId = @u_id AND w_friendId = @u_friendId) or\
			 (w_userId = @u_friendId AND w_friendId = @u_id)", dbConnection);
		MessageBox::Show("Запрос отклонен!");
	}
	command->Parameters->AddWithValue("@u_id", userId);
	command->Parameters->AddWithValue("@u_friendId", _friendId);
	command->ExecuteReader();
	dbConnection->Close();
}

//проверки или нехнические функции
void Sobutilnik::Map::uniqUser(System::Object ^_type, const char* _error, System::Object ^_obj)
{
	dbConnection->Open();
	command = gcnew OleDbCommand("SELECT * from MyDatabase where @u_type @u_check", dbConnection);
	command->Parameters->AddWithValue("@u_type", _type);
	command->Parameters->AddWithValue("@u_check", _obj);
	reader = command->ExecuteReader();
	reader->Read();

	if (reader->HasRows) {
		dbConnection->Close();
		throw std::logic_error(_error);
	}
	dbConnection->Close();
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

void Sobutilnik::Map::initLabels()
{
	dbConnection->Open();
	command = gcnew OleDbCommand("SELECT * from MyDatabase where w_id like @u_id", dbConnection);
	command->Parameters->AddWithValue("@u_id", userId);
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
	ReadyOrNotReady = reader->GetBoolean(9);
	userDescriptionLabel->Text = reader->GetValue(10)->ToString();
	userHobbiesLabel->Text = reader->GetValue(11)->ToString();
	usersAlcoholLabel->Text = reader->GetValue(12)->ToString();
	Rating->Value = reader->GetInt32(13);
	fbLink = reader->GetValue(15)->ToString();
	instLink = reader->GetValue(16)->ToString();
	vkLink = reader->GetValue(17)->ToString();
	twitterLink = reader->GetValue(18)->ToString();
	webPageLink = reader->GetValue(19)->ToString();

	dbConnection->Close();
	RatingPersent->Text = System::Convert::ToString(Rating->Value) + "%";
	pnaelPaint();
}

//Изменения в "мой профиль"
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

	if (newSurnameField->Text->Length)
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
		try {
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

	if (instagramkLinkField->Text->Length) {
		fieldForChanges.push_back("w_instagram = @u_instagram");
		Changes.push_back(marshal->marshal_as<const char*>(instagramkLinkField->Text));
		pathFieldForChanges.push_back("@u_instagram");
	}

	if (twitterLinkField->Text->Length) {
		fieldForChanges.push_back("w_twitter = @u_twitter");
		Changes.push_back(marshal->marshal_as<const char*>(twitterLinkField->Text));
		pathFieldForChanges.push_back("@u_twitter");
	}

	if (vkLinkField->Text->Length) {
		fieldForChanges.push_back("w_vk = @u_vk");
		Changes.push_back(marshal->marshal_as<const char*>(vkLinkField->Text));
		pathFieldForChanges.push_back("@u_vk");
	}

	if (webPageLinkField->Text->Length) {
		fieldForChanges.push_back("w_personalSite = @u_personalSite");
		Changes.push_back(marshal->marshal_as<const char*>(webPageLinkField->Text));
		pathFieldForChanges.push_back("@u_personalSite");
	}

	if (facebookLinkField->Text->Length) {
		fieldForChanges.push_back("w_facebook = @u_facebook");
		Changes.push_back(marshal->marshal_as<const char*>(facebookLinkField->Text));
		pathFieldForChanges.push_back("@u_facebook");
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
		command->Connection = dbConnection;

		for (size_t i = 0; i < pathFieldForChanges.size(); i++)
			command->Parameters->AddWithValue(marshal_as<String^>(pathFieldForChanges[i]), marshal_as<String^>(Changes[i]));

		command->Parameters->AddWithValue("@u_id", userId);
		dbConnection->Open();
		command->ExecuteNonQuery();
		dbConnection->Close();

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

		dbConnection->Open();
		command = gcnew OleDbCommand("DELETE FROM MyDatabase WHERE w_id = @u_id", dbConnection);
		command->Parameters->AddWithValue("@u_id", userId);
		command->ExecuteReader();
		dbConnection->Close();
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

System::Void Sobutilnik::Map::ChangeProfileImage_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	openFileDialog1->InitialDirectory = "c:\\";
	openFileDialog1->Filter = "Image Files(*.BMP;*.JPG;*.GIF;*.PNG)|*.BMP;*.JPG;*.GIF;*.PNG";
	openFileDialog1->RestoreDirectory = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && openFileDialog1->FileName != nullptr) {
		profileImage = openFileDialog1->FileName;
		ProfileImage->Load(profileImage);
		PictureProfile->Load(profileImage);
	}
}

System::Void Sobutilnik::Map::Drunk_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	ReadyOrNotReady = !ReadyOrNotReady;
	command = gcnew OleDbCommand("UPDATE MyDatabase SET w_Ready = @u_ready WHERE w_id = @u_id", dbConnection);
	command->Parameters->AddWithValue("@u_ready", ReadyOrNotReady);
	command->Parameters->AddWithValue("@u_id", userId);
	dbConnection->Open();
	command->ExecuteReader();
	dbConnection->Close();
	pnaelPaint();
}

void Sobutilnik::Map::pnaelPaint()
{
	Sleep(50);
	if (!ReadyOrNotReady) {
		ReadyOrNot->BackColor = Color::IndianRed;
		Drunk->Text = "Готов";
	}
	else {
		ReadyOrNot->BackColor = Color::Green;
		Drunk->Text = "Не готов";
	}
}

//сообщения
System::String^ Sobutilnik::Map::getLocalIPAddress()
{
	IPHostEntry^ host;
	host = Dns::GetHostEntry(Dns::GetHostName());

	for each (IPAddress^ ipAddr in host->AddressList)
		if (ipAddr->AddressFamily == AddressFamily::InterNetwork)
			return ipAddr->ToString();

	return "127.0.0.1";
}

//void Sobutilnik::Map::MessageCallBack(IAsyncResult ^aResult)
//{
//	try
//	{
//		int messageSize = socket->EndReceiveFrom(aResult,remoteEndPoint);
//	
//		if (messageSize) {
//
//			String^ message;
//
//			message = aResult->AsyncState->ToString();
//
//			massegeListBox->Items->Add("Собеседник: "+message);
//		}
//
//		String^ buffer;
//		
//		//socket->BeginReceiveFrom(buffer,0,buffer->Length,SocketFlags::None, &remoteEndPoint,MessageCallBack(aResult),buffer);
//	}
//	catch (const std::exception& ex)
//	{
//		
//	}
//}

//обработка кнопок
System::Void Sobutilnik::Map::Settings_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SettingsPanel->Visible = true;
	SettingsPanel->Location = System::Drawing::Point(215, 15);
	//SettingsPanel->Size = System::Drawing::Size(854, 539);
	//Map::Size = System::Drawing::Size(800, 515);

	FriendsPanel->Visible = false;
	profilePanel->Visible = false;
	HistoryPanel->Visible = false;
	MessagesPanel->Visible = false;
}

System::Void Sobutilnik::Map::Messages_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MessagesPanel->Visible = true;
	MessagesPanel->Location = System::Drawing::Point(215, 15);
	//MessagesPanel->Size = System::Drawing::Size(854, 539);
	
	FriendsPanel->Visible = false;
	profilePanel->Visible = false;
	HistoryPanel->Visible = false;
	SettingsPanel->Visible = false;
}

System::Void Sobutilnik::Map::History_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	HistoryPanel->Visible = true;
	HistoryPanel->Location = System::Drawing::Point(215, 15);
	//HistoryPanel->Size = System::Drawing::Size(854, 539);

	FriendsPanel->Visible = false;
	profilePanel->Visible = false;
	SettingsPanel->Visible = false;
	MessagesPanel->Visible = false;
}

System::Void Sobutilnik::Map::Search_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	FriendsPanel->Visible = true;
	FriendsPanel->Location = System::Drawing::Point(215, 15);
	//FriendsPanel->Size = System::Drawing::Size(854, 539);
	//Map::Size = System::Drawing::Size(750, 430);

	label11->Text = "Поиск людей:";
	searchButton->Visible = true;
	searchField->Visible = true;

	resultListBox->Items->Clear();
	resultListBox->Items->Add("Введите логин чтоб начать поиск");
	profilePanel->Visible = false;
	HistoryPanel->Visible = false;
	SettingsPanel->Visible = false;
	MessagesPanel->Visible = false;
}

System::Void Sobutilnik::Map::searchButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	try
	{
		checkSearch();
	}
	catch (const std::exception & e)
	{
		MessageBox::Show(marshal_as<String^>(e.what()));
		return;
	}
}

System::Void Sobutilnik::Map::FriendsButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	checkFriends();
	FriendsPanel->Visible = true;
	FriendsPanel->Location = System::Drawing::Point(215, 15);
	//FriendsPanel->Size = System::Drawing::Size(854, 539);
	//Map::Size = System::Drawing::Size(750, 430);

	profilePanel->Visible = false;
	HistoryPanel->Visible = false;
	SettingsPanel->Visible = false;
	MessagesPanel->Visible = false;
}

System::Void Sobutilnik::Map::profileButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	profilePanel->Visible = true;
	profilePanel->Location = System::Drawing::Point(215, 15);
	//FriendsPanel->Size = System::Drawing::Size(854, 539);
	//Map::Size = System::Drawing::Size(750, 430);

	FriendsPanel->Visible = false;
	HistoryPanel->Visible = false;
	SettingsPanel->Visible = false;
	MessagesPanel->Visible = false;
}


System::Void Sobutilnik::Map::mapButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	GeolocationForm^ geolocationForm = gcnew GeolocationForm();
	geolocationForm->Visible = true;
}

System::Void Sobutilnik::Map::facebookButton_Click(System::Object^  sender, System::EventArgs^  e){
	if(fbLink->Length)
		Process::Start(fbLink);
}

System::Void Sobutilnik::Map::instagramButton_Click(System::Object^  sender, System::EventArgs^  e){
	if (instLink->Length)
		Process::Start(instLink);
}	

System::Void Sobutilnik::Map::twitterButton_Click(System::Object^  sender, System::EventArgs^  e){
	if (twitterLink->Length)
		Process::Start(twitterLink);
}

System::Void Sobutilnik::Map::vkButton_Click(System::Object^  sender, System::EventArgs^  e){
	if (vkLink->Length)
		Process::Start(vkLink);
}

System::Void Sobutilnik::Map::webPageButton_Click(System::Object^  sender, System::EventArgs^  e){
	if (webPageLink->Length)
		Process::Start(webPageLink);
}
