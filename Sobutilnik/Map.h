#pragma once
#include "FirstPage.h"
#include <msclr/marshal.h>

namespace Sobutilnik {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace OleDb;

	/// <summary>
	/// Сводка для Map
	/// </summary>
	public ref class Map : public System::Windows::Forms::Form
	{
	public:
		Map(FirstPage ^f) : mainPage(f), userId(1)
		{
			InitializeComponent();
			profileImage = nullptr;
		}
		Map(FirstPage ^f, int _id) : mainPage(f), userId(_id)
		{
			InitializeComponent();
			profileImage = nullptr;
			initLabels();
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Map()
		{
			if (components)
			{
				delete components;
			}
			delete mainPage;
			delete profileImage;
		}
	private: System::Windows::Forms::Label^  userSex;
	private: System::Windows::Forms::Label^  UserBirth;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label8;

	protected:

	private:
		FirstPage ^mainPage;
		void initLabels();
	private: System::Windows::Forms::Label^  userSurname;

	private: System::Windows::Forms::Label^  userFirstName;

	private: System::Windows::Forms::Label^  userLogin;

	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  userAgeStatic;



			 String^ profileImage;
		void checkSearch();
		int userId;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  RatingPersent;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Button^  mapButton;
	private: System::Windows::Forms::Button^  profileButton;
	private: System::Windows::Forms::Panel^  profilePanel;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  usersAlcoholLabel;
	private: System::Windows::Forms::Label^  Drinks;

	private: System::Windows::Forms::Label^  userHobbiesLabel;
	private: System::Windows::Forms::Label^  Hobbies;
	private: System::Windows::Forms::Label^  userDescriptionLabel;
	private: System::Windows::Forms::Label^  aboutYourself;

	private: System::Windows::Forms::TextBox^  userDrinksChangeField;
	private: System::Windows::Forms::TextBox^  userHobbyChangeField;
	private: System::Windows::Forms::TextBox^  userDescriptionChangeField;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;



	private: System::Windows::Forms::Button^  Messages;
	private: System::Windows::Forms::Button^  History;
	private: System::Windows::Forms::Button^  Friends;
	private: System::Windows::Forms::Button^  Drunk;
	private: System::Windows::Forms::Button^  Settings;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ProgressBar^  Rating;
	private: System::Windows::Forms::PictureBox^  PictureProfile;
	private: System::Windows::Forms::Panel^  Buttons;
	private: System::Windows::Forms::Panel^  FriendsPanel;
	private: System::Windows::Forms::Panel^  HistoryPanel;
	private: System::Windows::Forms::Panel^  MessagesPanel;
	private: System::Windows::Forms::Panel^  SettingsPanel;
	private: System::Windows::Forms::Label^  userMail;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  newEmail;

	private: System::Windows::Forms::Button^  saveChanges;



	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  newNameField;
	private: System::Windows::Forms::TextBox^  newSurnameField;

	private: System::Windows::Forms::CheckBox^  GeoPosition;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  newPasswordField;

	private: System::Windows::Forms::TextBox^  currentPasswordField;


	private: System::Windows::Forms::Button^  ChangeProfileImage;
	private: System::Windows::Forms::PictureBox^  ProfileImage;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  UserName;

	private: System::Windows::Forms::Button^  searchButton;
	private: System::Windows::Forms::TextBox^  searchField;
	private: System::Windows::Forms::ListBox^  resultListBox;


			 /// <summary>
			 /// Обязательная переменная конструктора.
			 /// </summary>
			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Map::typeid));
				 this->PictureProfile = (gcnew System::Windows::Forms::PictureBox());
				 this->Drunk = (gcnew System::Windows::Forms::Button());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->Rating = (gcnew System::Windows::Forms::ProgressBar());
				 this->FriendsPanel = (gcnew System::Windows::Forms::Panel());
				 this->label11 = (gcnew System::Windows::Forms::Label());
				 this->resultListBox = (gcnew System::Windows::Forms::ListBox());
				 this->searchButton = (gcnew System::Windows::Forms::Button());
				 this->searchField = (gcnew System::Windows::Forms::TextBox());
				 this->HistoryPanel = (gcnew System::Windows::Forms::Panel());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->label12 = (gcnew System::Windows::Forms::Label());
				 this->MessagesPanel = (gcnew System::Windows::Forms::Panel());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->profilePanel = (gcnew System::Windows::Forms::Panel());
				 this->label15 = (gcnew System::Windows::Forms::Label());
				 this->usersAlcoholLabel = (gcnew System::Windows::Forms::Label());
				 this->Drinks = (gcnew System::Windows::Forms::Label());
				 this->userHobbiesLabel = (gcnew System::Windows::Forms::Label());
				 this->Hobbies = (gcnew System::Windows::Forms::Label());
				 this->userDescriptionLabel = (gcnew System::Windows::Forms::Label());
				 this->aboutYourself = (gcnew System::Windows::Forms::Label());
				 this->RatingPersent = (gcnew System::Windows::Forms::Label());
				 this->UserName = (gcnew System::Windows::Forms::Label());
				 this->Settings = (gcnew System::Windows::Forms::Button());
				 this->Friends = (gcnew System::Windows::Forms::Button());
				 this->History = (gcnew System::Windows::Forms::Button());
				 this->Messages = (gcnew System::Windows::Forms::Button());
				 this->Buttons = (gcnew System::Windows::Forms::Panel());
				 this->mapButton = (gcnew System::Windows::Forms::Button());
				 this->profileButton = (gcnew System::Windows::Forms::Button());
				 this->SettingsPanel = (gcnew System::Windows::Forms::Panel());
				 this->label14 = (gcnew System::Windows::Forms::Label());
				 this->label13 = (gcnew System::Windows::Forms::Label());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->UserBirth = (gcnew System::Windows::Forms::Label());
				 this->userSex = (gcnew System::Windows::Forms::Label());
				 this->userAgeStatic = (gcnew System::Windows::Forms::Label());
				 this->userSurname = (gcnew System::Windows::Forms::Label());
				 this->userFirstName = (gcnew System::Windows::Forms::Label());
				 this->userLogin = (gcnew System::Windows::Forms::Label());
				 this->label19 = (gcnew System::Windows::Forms::Label());
				 this->userDrinksChangeField = (gcnew System::Windows::Forms::TextBox());
				 this->userHobbyChangeField = (gcnew System::Windows::Forms::TextBox());
				 this->userDescriptionChangeField = (gcnew System::Windows::Forms::TextBox());
				 this->label18 = (gcnew System::Windows::Forms::Label());
				 this->label17 = (gcnew System::Windows::Forms::Label());
				 this->label16 = (gcnew System::Windows::Forms::Label());
				 this->userMail = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->newEmail = (gcnew System::Windows::Forms::TextBox());
				 this->saveChanges = (gcnew System::Windows::Forms::Button());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->newNameField = (gcnew System::Windows::Forms::TextBox());
				 this->newSurnameField = (gcnew System::Windows::Forms::TextBox());
				 this->GeoPosition = (gcnew System::Windows::Forms::CheckBox());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->newPasswordField = (gcnew System::Windows::Forms::TextBox());
				 this->currentPasswordField = (gcnew System::Windows::Forms::TextBox());
				 this->ChangeProfileImage = (gcnew System::Windows::Forms::Button());
				 this->ProfileImage = (gcnew System::Windows::Forms::PictureBox());
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureProfile))->BeginInit();
				 this->FriendsPanel->SuspendLayout();
				 this->HistoryPanel->SuspendLayout();
				 this->MessagesPanel->SuspendLayout();
				 this->profilePanel->SuspendLayout();
				 this->Buttons->SuspendLayout();
				 this->SettingsPanel->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProfileImage))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // PictureProfile
				 // 
				 this->PictureProfile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureProfile.Image")));
				 this->PictureProfile->Location = System::Drawing::Point(22, 11);
				 this->PictureProfile->Name = L"PictureProfile";
				 this->PictureProfile->Size = System::Drawing::Size(140, 137);
				 this->PictureProfile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->PictureProfile->TabIndex = 0;
				 this->PictureProfile->TabStop = false;
				 // 
				 // Drunk
				 // 
				 this->Drunk->Location = System::Drawing::Point(242, 356);
				 this->Drunk->Name = L"Drunk";
				 this->Drunk->Size = System::Drawing::Size(115, 38);
				 this->Drunk->TabIndex = 6;
				 this->Drunk->Text = L"Хочу бухать!";
				 this->Drunk->UseVisualStyleBackColor = true;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(32, 206);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(41, 13);
				 this->label1->TabIndex = 4;
				 this->label1->Text = L"Rating:";
				 // 
				 // Rating
				 // 
				 this->Rating->Location = System::Drawing::Point(34, 244);
				 this->Rating->Maximum = 50;
				 this->Rating->Name = L"Rating";
				 this->Rating->Size = System::Drawing::Size(100, 23);
				 this->Rating->TabIndex = 3;
				 // 
				 // FriendsPanel
				 // 
				 this->FriendsPanel->Controls->Add(this->label11);
				 this->FriendsPanel->Controls->Add(this->resultListBox);
				 this->FriendsPanel->Controls->Add(this->searchButton);
				 this->FriendsPanel->Controls->Add(this->searchField);
				 this->FriendsPanel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
				 this->FriendsPanel->Location = System::Drawing::Point(40, 105);
				 this->FriendsPanel->Name = L"FriendsPanel";
				 this->FriendsPanel->Size = System::Drawing::Size(854, 539);
				 this->FriendsPanel->TabIndex = 12;
				 this->FriendsPanel->Visible = false;
				 // 
				 // label11
				 // 
				 this->label11->AutoSize = true;
				 this->label11->Location = System::Drawing::Point(181, 32);
				 this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label11->Name = L"label11";
				 this->label11->Size = System::Drawing::Size(45, 13);
				 this->label11->TabIndex = 17;
				 this->label11->Text = L"Друзья";
				 // 
				 // resultListBox
				 // 
				 this->resultListBox->FormattingEnabled = true;
				 this->resultListBox->Location = System::Drawing::Point(28, 158);
				 this->resultListBox->Margin = System::Windows::Forms::Padding(2);
				 this->resultListBox->Name = L"resultListBox";
				 this->resultListBox->Size = System::Drawing::Size(243, 238);
				 this->resultListBox->TabIndex = 16;
				 // 
				 // searchButton
				 // 
				 this->searchButton->Location = System::Drawing::Point(298, 111);
				 this->searchButton->Margin = System::Windows::Forms::Padding(2);
				 this->searchButton->Name = L"searchButton";
				 this->searchButton->Size = System::Drawing::Size(56, 19);
				 this->searchButton->TabIndex = 15;
				 this->searchButton->Text = L"Поиск";
				 this->searchButton->UseVisualStyleBackColor = true;
				 this->searchButton->Click += gcnew System::EventHandler(this, &Map::searchButton_Click);
				 // 
				 // searchField
				 // 
				 this->searchField->Location = System::Drawing::Point(28, 112);
				 this->searchField->Margin = System::Windows::Forms::Padding(2);
				 this->searchField->Name = L"searchField";
				 this->searchField->Size = System::Drawing::Size(243, 20);
				 this->searchField->TabIndex = 14;
				 // 
				 // HistoryPanel
				 // 
				 this->HistoryPanel->Controls->Add(this->label9);
				 this->HistoryPanel->Location = System::Drawing::Point(623, 6);
				 this->HistoryPanel->Name = L"HistoryPanel";
				 this->HistoryPanel->Size = System::Drawing::Size(854, 539);
				 this->HistoryPanel->TabIndex = 12;
				 this->HistoryPanel->Visible = false;
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Location = System::Drawing::Point(435, 16);
				 this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(50, 13);
				 this->label9->TabIndex = 14;
				 this->label9->Text = L"История";
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Location = System::Drawing::Point(167, 20);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(64, 17);
				 this->label12->TabIndex = 15;
				 this->label12->Text = L"История";
				 // 
				 // MessagesPanel
				 // 
				 this->MessagesPanel->Controls->Add(this->label10);
				 this->MessagesPanel->Location = System::Drawing::Point(463, 18);
				 this->MessagesPanel->Name = L"MessagesPanel";
				 this->MessagesPanel->Size = System::Drawing::Size(854, 539);
				 this->MessagesPanel->TabIndex = 12;
				 this->MessagesPanel->Visible = false;
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Location = System::Drawing::Point(140, 33);
				 this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(65, 13);
				 this->label10->TabIndex = 14;
				 this->label10->Text = L"Сообщения";
				 // 
				 // profilePanel
				 // 
				 this->profilePanel->Controls->Add(this->label15);
				 this->profilePanel->Controls->Add(this->usersAlcoholLabel);
				 this->profilePanel->Controls->Add(this->Drinks);
				 this->profilePanel->Controls->Add(this->userHobbiesLabel);
				 this->profilePanel->Controls->Add(this->Hobbies);
				 this->profilePanel->Controls->Add(this->userDescriptionLabel);
				 this->profilePanel->Controls->Add(this->aboutYourself);
				 this->profilePanel->Controls->Add(this->PictureProfile);
				 this->profilePanel->Controls->Add(this->Drunk);
				 this->profilePanel->Controls->Add(this->RatingPersent);
				 this->profilePanel->Controls->Add(this->Rating);
				 this->profilePanel->Controls->Add(this->UserName);
				 this->profilePanel->Controls->Add(this->label1);
				 this->profilePanel->Location = System::Drawing::Point(338, 15);
				 this->profilePanel->Margin = System::Windows::Forms::Padding(2);
				 this->profilePanel->Name = L"profilePanel";
				 this->profilePanel->Size = System::Drawing::Size(862, 540);
				 this->profilePanel->TabIndex = 13;
				 // 
				 // label15
				 // 
				 this->label15->AutoSize = true;
				 this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(204)));
				 this->label15->Location = System::Drawing::Point(437, 356);
				 this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label15->Name = L"label15";
				 this->label15->Size = System::Drawing::Size(298, 17);
				 this->label15->TabIndex = 18;
				 this->label15->Text = L"придумать еще полей для заполнения";
				 // 
				 // usersAlcoholLabel
				 // 
				 this->usersAlcoholLabel->AutoSize = true;
				 this->usersAlcoholLabel->Location = System::Drawing::Point(475, 259);
				 this->usersAlcoholLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->usersAlcoholLabel->Name = L"usersAlcoholLabel";
				 this->usersAlcoholLabel->Size = System::Drawing::Size(109, 13);
				 this->usersAlcoholLabel->TabIndex = 17;
				 this->usersAlcoholLabel->Text = L"user\'s favourite drinks";
				 // 
				 // Drinks
				 // 
				 this->Drinks->AutoSize = true;
				 this->Drinks->Location = System::Drawing::Point(475, 234);
				 this->Drinks->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->Drinks->Name = L"Drinks";
				 this->Drinks->Size = System::Drawing::Size(104, 13);
				 this->Drinks->TabIndex = 16;
				 this->Drinks->Text = L"Любимые напитки:";
				 // 
				 // userHobbiesLabel
				 // 
				 this->userHobbiesLabel->AutoSize = true;
				 this->userHobbiesLabel->Location = System::Drawing::Point(475, 146);
				 this->userHobbiesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->userHobbiesLabel->Name = L"userHobbiesLabel";
				 this->userHobbiesLabel->Size = System::Drawing::Size(120, 13);
				 this->userHobbiesLabel->TabIndex = 15;
				 this->userHobbiesLabel->Text = L"user\'s hobby description";
				 // 
				 // Hobbies
				 // 
				 this->Hobbies->AutoSize = true;
				 this->Hobbies->Location = System::Drawing::Point(475, 123);
				 this->Hobbies->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->Hobbies->Name = L"Hobbies";
				 this->Hobbies->Size = System::Drawing::Size(125, 13);
				 this->Hobbies->TabIndex = 14;
				 this->Hobbies->Text = L"Интересы и увлечения:";
				 // 
				 // userDescriptionLabel
				 // 
				 this->userDescriptionLabel->AutoSize = true;
				 this->userDescriptionLabel->Location = System::Drawing::Point(475, 38);
				 this->userDescriptionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->userDescriptionLabel->Name = L"userDescriptionLabel";
				 this->userDescriptionLabel->Size = System::Drawing::Size(118, 13);
				 this->userDescriptionLabel->TabIndex = 13;
				 this->userDescriptionLabel->Text = L"Some words about user";
				 // 
				 // aboutYourself
				 // 
				 this->aboutYourself->AutoSize = true;
				 this->aboutYourself->Location = System::Drawing::Point(475, 17);
				 this->aboutYourself->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->aboutYourself->Name = L"aboutYourself";
				 this->aboutYourself->Size = System::Drawing::Size(45, 13);
				 this->aboutYourself->TabIndex = 12;
				 this->aboutYourself->Text = L"О себе:";
				 // 
				 // RatingPersent
				 // 
				 this->RatingPersent->AutoSize = true;
				 this->RatingPersent->Location = System::Drawing::Point(108, 205);
				 this->RatingPersent->Name = L"RatingPersent";
				 this->RatingPersent->Size = System::Drawing::Size(27, 13);
				 this->RatingPersent->TabIndex = 11;
				 this->RatingPersent->Text = L"60%";
				 this->RatingPersent->TextAlign = System::Drawing::ContentAlignment::TopRight;
				 // 
				 // UserName
				 // 
				 this->UserName->AutoSize = true;
				 this->UserName->Location = System::Drawing::Point(35, 163);
				 this->UserName->Name = L"UserName";
				 this->UserName->Size = System::Drawing::Size(27, 13);
				 this->UserName->TabIndex = 10;
				 this->UserName->Text = L"Ник";
				 // 
				 // Settings
				 // 
				 this->Settings->Location = System::Drawing::Point(11, 159);
				 this->Settings->Name = L"Settings";
				 this->Settings->Size = System::Drawing::Size(125, 25);
				 this->Settings->TabIndex = 5;
				 this->Settings->Text = L"Настройки";
				 this->Settings->UseVisualStyleBackColor = true;
				 this->Settings->Click += gcnew System::EventHandler(this, &Map::Settings_Click);
				 // 
				 // Friends
				 // 
				 this->Friends->Location = System::Drawing::Point(11, 39);
				 this->Friends->Name = L"Friends";
				 this->Friends->Size = System::Drawing::Size(125, 25);
				 this->Friends->TabIndex = 7;
				 this->Friends->Text = L"Друзья";
				 this->Friends->UseVisualStyleBackColor = true;
				 this->Friends->Click += gcnew System::EventHandler(this, &Map::Friends_Click);
				 // 
				 // History
				 // 
				 this->History->Location = System::Drawing::Point(11, 129);
				 this->History->Name = L"History";
				 this->History->Size = System::Drawing::Size(125, 25);
				 this->History->TabIndex = 8;
				 this->History->Text = L"История";
				 this->History->UseVisualStyleBackColor = true;
				 this->History->Click += gcnew System::EventHandler(this, &Map::History_Click);
				 // 
				 // Messages
				 // 
				 this->Messages->Location = System::Drawing::Point(11, 69);
				 this->Messages->Name = L"Messages";
				 this->Messages->Size = System::Drawing::Size(125, 25);
				 this->Messages->TabIndex = 9;
				 this->Messages->Text = L"Сообщения";
				 this->Messages->UseVisualStyleBackColor = true;
				 this->Messages->Click += gcnew System::EventHandler(this, &Map::Messages_Click);
				 // 
				 // Buttons
				 // 
				 this->Buttons->Controls->Add(this->mapButton);
				 this->Buttons->Controls->Add(this->profileButton);
				 this->Buttons->Controls->Add(this->Friends);
				 this->Buttons->Controls->Add(this->Messages);
				 this->Buttons->Controls->Add(this->Settings);
				 this->Buttons->Controls->Add(this->History);
				 this->Buttons->Location = System::Drawing::Point(10, 6);
				 this->Buttons->Name = L"Buttons";
				 this->Buttons->Size = System::Drawing::Size(144, 530);
				 this->Buttons->TabIndex = 10;
				 // 
				 // mapButton
				 // 
				 this->mapButton->Location = System::Drawing::Point(11, 99);
				 this->mapButton->Margin = System::Windows::Forms::Padding(2);
				 this->mapButton->Name = L"mapButton";
				 this->mapButton->Size = System::Drawing::Size(125, 25);
				 this->mapButton->TabIndex = 13;
				 this->mapButton->Text = L"Карта";
				 this->mapButton->UseVisualStyleBackColor = true;
				 // 
				 // profileButton
				 // 
				 this->profileButton->Location = System::Drawing::Point(11, 9);
				 this->profileButton->Margin = System::Windows::Forms::Padding(2);
				 this->profileButton->Name = L"profileButton";
				 this->profileButton->Size = System::Drawing::Size(125, 25);
				 this->profileButton->TabIndex = 12;
				 this->profileButton->Text = L"Мой профиль";
				 this->profileButton->UseVisualStyleBackColor = true;
				 this->profileButton->Click += gcnew System::EventHandler(this, &Map::profileButton_Click);
				 // 
				 // SettingsPanel
				 // 
				 this->SettingsPanel->Controls->Add(this->label14);
				 this->SettingsPanel->Controls->Add(this->label13);
				 this->SettingsPanel->Controls->Add(this->label8);
				 this->SettingsPanel->Controls->Add(this->UserBirth);
				 this->SettingsPanel->Controls->Add(this->userSex);
				 this->SettingsPanel->Controls->Add(this->userAgeStatic);
				 this->SettingsPanel->Controls->Add(this->userSurname);
				 this->SettingsPanel->Controls->Add(this->userFirstName);
				 this->SettingsPanel->Controls->Add(this->userLogin);
				 this->SettingsPanel->Controls->Add(this->label19);
				 this->SettingsPanel->Controls->Add(this->userDrinksChangeField);
				 this->SettingsPanel->Controls->Add(this->userHobbyChangeField);
				 this->SettingsPanel->Controls->Add(this->userDescriptionChangeField);
				 this->SettingsPanel->Controls->Add(this->label18);
				 this->SettingsPanel->Controls->Add(this->label17);
				 this->SettingsPanel->Controls->Add(this->label16);
				 this->SettingsPanel->Controls->Add(this->userMail);
				 this->SettingsPanel->Controls->Add(this->label6);
				 this->SettingsPanel->Controls->Add(this->label7);
				 this->SettingsPanel->Controls->Add(this->newEmail);
				 this->SettingsPanel->Controls->Add(this->saveChanges);
				 this->SettingsPanel->Controls->Add(this->label4);
				 this->SettingsPanel->Controls->Add(this->label5);
				 this->SettingsPanel->Controls->Add(this->newNameField);
				 this->SettingsPanel->Controls->Add(this->newSurnameField);
				 this->SettingsPanel->Controls->Add(this->GeoPosition);
				 this->SettingsPanel->Controls->Add(this->label3);
				 this->SettingsPanel->Controls->Add(this->label2);
				 this->SettingsPanel->Controls->Add(this->newPasswordField);
				 this->SettingsPanel->Controls->Add(this->currentPasswordField);
				 this->SettingsPanel->Controls->Add(this->ChangeProfileImage);
				 this->SettingsPanel->Controls->Add(this->ProfileImage);
				 this->SettingsPanel->Location = System::Drawing::Point(160, 9);
				 this->SettingsPanel->Name = L"SettingsPanel";
				 this->SettingsPanel->Size = System::Drawing::Size(854, 539);
				 this->SettingsPanel->TabIndex = 12;
				 this->SettingsPanel->Visible = false;
				 // 
				 // label14
				 // 
				 this->label14->AutoSize = true;
				 this->label14->Location = System::Drawing::Point(20, 80);
				 this->label14->Name = L"label14";
				 this->label14->Size = System::Drawing::Size(59, 13);
				 this->label14->TabIndex = 51;
				 this->label14->Text = L"Фамилия:";
				 // 
				 // label13
				 // 
				 this->label13->AutoSize = true;
				 this->label13->Location = System::Drawing::Point(20, 44);
				 this->label13->Name = L"label13";
				 this->label13->Size = System::Drawing::Size(32, 13);
				 this->label13->TabIndex = 50;
				 this->label13->Text = L"Имя:";
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Location = System::Drawing::Point(20, 9);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(41, 13);
				 this->label8->TabIndex = 49;
				 this->label8->Text = L"Логин:";
				 // 
				 // UserBirth
				 // 
				 this->UserBirth->AutoSize = true;
				 this->UserBirth->Location = System::Drawing::Point(20, 134);
				 this->UserBirth->Name = L"UserBirth";
				 this->UserBirth->Size = System::Drawing::Size(65, 13);
				 this->UserBirth->TabIndex = 48;
				 this->UserBirth->Text = L"02/03/2018";
				 // 
				 // userSex
				 // 
				 this->userSex->AutoSize = true;
				 this->userSex->Location = System::Drawing::Point(20, 155);
				 this->userSex->Name = L"userSex";
				 this->userSex->Size = System::Drawing::Size(42, 13);
				 this->userSex->TabIndex = 47;
				 this->userSex->Text = L"Пол: М";
				 // 
				 // userAgeStatic
				 // 
				 this->userAgeStatic->AutoSize = true;
				 this->userAgeStatic->Location = System::Drawing::Point(20, 115);
				 this->userAgeStatic->Name = L"userAgeStatic";
				 this->userAgeStatic->Size = System::Drawing::Size(89, 13);
				 this->userAgeStatic->TabIndex = 46;
				 this->userAgeStatic->Text = L"Дата рождения:\r\n";
				 // 
				 // userSurname
				 // 
				 this->userSurname->AutoSize = true;
				 this->userSurname->Location = System::Drawing::Point(20, 93);
				 this->userSurname->Name = L"userSurname";
				 this->userSurname->Size = System::Drawing::Size(44, 13);
				 this->userSurname->TabIndex = 45;
				 this->userSurname->Text = L"Пупкин";
				 this->userSurname->Click += gcnew System::EventHandler(this, &Map::label22_Click);
				 // 
				 // userFirstName
				 // 
				 this->userFirstName->AutoSize = true;
				 this->userFirstName->Location = System::Drawing::Point(20, 57);
				 this->userFirstName->Name = L"userFirstName";
				 this->userFirstName->Size = System::Drawing::Size(50, 13);
				 this->userFirstName->TabIndex = 44;
				 this->userFirstName->Text = L"Василий";
				 // 
				 // userLogin
				 // 
				 this->userLogin->AutoSize = true;
				 this->userLogin->Location = System::Drawing::Point(20, 23);
				 this->userLogin->Name = L"userLogin";
				 this->userLogin->Size = System::Drawing::Size(69, 13);
				 this->userLogin->TabIndex = 43;
				 this->userLogin->Text = L"nagibator228";
				 // 
				 // label19
				 // 
				 this->label19->AutoSize = true;
				 this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(204)));
				 this->label19->Location = System::Drawing::Point(28, 199);
				 this->label19->Name = L"label19";
				 this->label19->Size = System::Drawing::Size(116, 13);
				 this->label19->TabIndex = 42;
				 this->label19->Text = L"Изменить пароль:";
				 // 
				 // userDrinksChangeField
				 // 
				 this->userDrinksChangeField->Location = System::Drawing::Point(521, 406);
				 this->userDrinksChangeField->Margin = System::Windows::Forms::Padding(2);
				 this->userDrinksChangeField->Multiline = true;
				 this->userDrinksChangeField->Name = L"userDrinksChangeField";
				 this->userDrinksChangeField->Size = System::Drawing::Size(180, 102);
				 this->userDrinksChangeField->TabIndex = 38;
				 // 
				 // userHobbyChangeField
				 // 
				 this->userHobbyChangeField->Location = System::Drawing::Point(521, 224);
				 this->userHobbyChangeField->Margin = System::Windows::Forms::Padding(2);
				 this->userHobbyChangeField->Multiline = true;
				 this->userHobbyChangeField->Name = L"userHobbyChangeField";
				 this->userHobbyChangeField->Size = System::Drawing::Size(180, 101);
				 this->userHobbyChangeField->TabIndex = 37;
				 // 
				 // userDescriptionChangeField
				 // 
				 this->userDescriptionChangeField->Location = System::Drawing::Point(521, 37);
				 this->userDescriptionChangeField->Margin = System::Windows::Forms::Padding(2);
				 this->userDescriptionChangeField->Multiline = true;
				 this->userDescriptionChangeField->Name = L"userDescriptionChangeField";
				 this->userDescriptionChangeField->Size = System::Drawing::Size(180, 102);
				 this->userDescriptionChangeField->TabIndex = 36;
				 // 
				 // label18
				 // 
				 this->label18->AutoSize = true;
				 this->label18->Location = System::Drawing::Point(518, 388);
				 this->label18->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label18->Name = L"label18";
				 this->label18->Size = System::Drawing::Size(104, 13);
				 this->label18->TabIndex = 35;
				 this->label18->Text = L"Любимые напитки:";
				 // 
				 // label17
				 // 
				 this->label17->AutoSize = true;
				 this->label17->Location = System::Drawing::Point(518, 208);
				 this->label17->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label17->Name = L"label17";
				 this->label17->Size = System::Drawing::Size(125, 13);
				 this->label17->TabIndex = 34;
				 this->label17->Text = L"Интересы и увлечения:";
				 // 
				 // label16
				 // 
				 this->label16->AutoSize = true;
				 this->label16->Location = System::Drawing::Point(518, 19);
				 this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label16->Name = L"label16";
				 this->label16->Size = System::Drawing::Size(45, 13);
				 this->label16->TabIndex = 33;
				 this->label16->Text = L"О себе:";
				 // 
				 // userMail
				 // 
				 this->userMail->AutoSize = true;
				 this->userMail->Location = System::Drawing::Point(107, 333);
				 this->userMail->Name = L"userMail";
				 this->userMail->Size = System::Drawing::Size(118, 13);
				 this->userMail->TabIndex = 32;
				 this->userMail->Text = L"exmple@sobutilnik.com";
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(107, 353);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(91, 13);
				 this->label6->TabIndex = 31;
				 this->label6->Text = L"Изменить почту:";
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(107, 320);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(86, 13);
				 this->label7->TabIndex = 30;
				 this->label7->Text = L"Текущая почта:";
				 // 
				 // newEmail
				 // 
				 this->newEmail->Location = System::Drawing::Point(110, 369);
				 this->newEmail->Name = L"newEmail";
				 this->newEmail->Size = System::Drawing::Size(100, 20);
				 this->newEmail->TabIndex = 28;
				 // 
				 // saveChanges
				 // 
				 this->saveChanges->Location = System::Drawing::Point(114, 503);
				 this->saveChanges->Name = L"saveChanges";
				 this->saveChanges->Size = System::Drawing::Size(135, 23);
				 this->saveChanges->TabIndex = 27;
				 this->saveChanges->Text = L"Сохранить изменения";
				 this->saveChanges->UseVisualStyleBackColor = true;
				 this->saveChanges->Click += gcnew System::EventHandler(this, &Map::saveChanges_Click);
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(189, 223);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(91, 13);
				 this->label4->TabIndex = 26;
				 this->label4->Text = L"Новая фамилия:";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(189, 262);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(65, 13);
				 this->label5->TabIndex = 25;
				 this->label5->Text = L"Новое имя:";
				 // 
				 // newNameField
				 // 
				 this->newNameField->Location = System::Drawing::Point(192, 278);
				 this->newNameField->Name = L"newNameField";
				 this->newNameField->Size = System::Drawing::Size(100, 20);
				 this->newNameField->TabIndex = 24;
				 // 
				 // newSurnameField
				 // 
				 this->newSurnameField->Location = System::Drawing::Point(192, 239);
				 this->newSurnameField->Name = L"newSurnameField";
				 this->newSurnameField->Size = System::Drawing::Size(100, 20);
				 this->newSurnameField->TabIndex = 23;
				 // 
				 // GeoPosition
				 // 
				 this->GeoPosition->AutoSize = true;
				 this->GeoPosition->Checked = true;
				 this->GeoPosition->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->GeoPosition->Location = System::Drawing::Point(48, 395);
				 this->GeoPosition->Name = L"GeoPosition";
				 this->GeoPosition->Size = System::Drawing::Size(232, 17);
				 this->GeoPosition->TabIndex = 21;
				 this->GeoPosition->Text = L"Согласен на использования геолокации";
				 this->GeoPosition->UseVisualStyleBackColor = true;
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(28, 223);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(94, 13);
				 this->label3->TabIndex = 20;
				 this->label3->Text = L"Текущий пароль:";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(28, 262);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(83, 13);
				 this->label2->TabIndex = 19;
				 this->label2->Text = L"Новый пароль:";
				 // 
				 // newPasswordField
				 // 
				 this->newPasswordField->Location = System::Drawing::Point(31, 278);
				 this->newPasswordField->Name = L"newPasswordField";
				 this->newPasswordField->Size = System::Drawing::Size(100, 20);
				 this->newPasswordField->TabIndex = 18;
				 // 
				 // currentPasswordField
				 // 
				 this->currentPasswordField->Location = System::Drawing::Point(31, 239);
				 this->currentPasswordField->Name = L"currentPasswordField";
				 this->currentPasswordField->Size = System::Drawing::Size(100, 20);
				 this->currentPasswordField->TabIndex = 17;
				 // 
				 // ChangeProfileImage
				 // 
				 this->ChangeProfileImage->Location = System::Drawing::Point(152, 151);
				 this->ChangeProfileImage->Name = L"ChangeProfileImage";
				 this->ChangeProfileImage->Size = System::Drawing::Size(140, 23);
				 this->ChangeProfileImage->TabIndex = 15;
				 this->ChangeProfileImage->Text = L"Изменить";
				 this->ChangeProfileImage->UseVisualStyleBackColor = true;
				 this->ChangeProfileImage->Click += gcnew System::EventHandler(this, &Map::ChangeProfileImage_Click);
				 // 
				 // ProfileImage
				 // 
				 this->ProfileImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ProfileImage.Image")));
				 this->ProfileImage->Location = System::Drawing::Point(152, 7);
				 this->ProfileImage->Name = L"ProfileImage";
				 this->ProfileImage->Size = System::Drawing::Size(140, 137);
				 this->ProfileImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->ProfileImage->TabIndex = 14;
				 this->ProfileImage->TabStop = false;
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 // 
				 // Map
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1022, 547);
				 this->Controls->Add(this->SettingsPanel);
				 this->Controls->Add(this->profilePanel);
				 this->Controls->Add(this->Buttons);
				 this->Controls->Add(this->HistoryPanel);
				 this->Controls->Add(this->FriendsPanel);
				 this->Controls->Add(this->MessagesPanel);
				 this->Name = L"Map";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Map";
				 this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Map::Map_FormClosed);
				 this->Load += gcnew System::EventHandler(this, &Map::Map_Load);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureProfile))->EndInit();
				 this->FriendsPanel->ResumeLayout(false);
				 this->FriendsPanel->PerformLayout();
				 this->HistoryPanel->ResumeLayout(false);
				 this->HistoryPanel->PerformLayout();
				 this->MessagesPanel->ResumeLayout(false);
				 this->MessagesPanel->PerformLayout();
				 this->profilePanel->ResumeLayout(false);
				 this->profilePanel->PerformLayout();
				 this->Buttons->ResumeLayout(false);
				 this->SettingsPanel->ResumeLayout(false);
				 this->SettingsPanel->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProfileImage))->EndInit();
				 this->ResumeLayout(false);

			 }
#pragma endregion
	private: System::Void Map_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		mainPage->Close();
	}
	private: System::Void Settings_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Messages_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void History_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Friends_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ChangeProfileImage_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void Map_Load(System::Object^  sender, System::EventArgs^  e) {
	RatingPersent->Text = System::Convert::ToString(Rating->Value * 2) + "%";
}
private: System::Void searchButton_Click(System::Object^  sender, System::EventArgs^  e) {
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

private: System::Void profileButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void saveChanges_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void label22_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
