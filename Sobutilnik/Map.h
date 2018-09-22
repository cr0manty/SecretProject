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
		Map(FirstPage ^f) : mainPage(f)
		{
			InitializeComponent();
			profileImage = nullptr;
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

	private:
		FirstPage ^mainPage;
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
	private: System::Windows::Forms::Label^  Label14;
	private: System::Windows::Forms::Label^  userHobbiesLabel;
	private: System::Windows::Forms::Label^  Hobbies;
	private: System::Windows::Forms::Label^  userDescriptionLabel;
	private: System::Windows::Forms::Label^  Label13;
	private: System::Windows::Forms::TextBox^  userDrinksChangeField;
	private: System::Windows::Forms::TextBox^  userHobbyChangeField;
	private: System::Windows::Forms::TextBox^  userDescriptionChangeField;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  descriptionChangeButton;


			 String^ profileImage;
		void checkSearch();

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




	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  saveEmailChanges;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  newNameField;

	private: System::Windows::Forms::TextBox^  newSurnameField;



	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::CheckBox^  GeoPosition;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  newPasswordField;

	private: System::Windows::Forms::TextBox^  currentPasswordField;

	private: System::Windows::Forms::Button^  ChangePass;
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
				 this->profilePanel = (gcnew System::Windows::Forms::Panel());
				 this->label15 = (gcnew System::Windows::Forms::Label());
				 this->usersAlcoholLabel = (gcnew System::Windows::Forms::Label());
				 this->Label14 = (gcnew System::Windows::Forms::Label());
				 this->userHobbiesLabel = (gcnew System::Windows::Forms::Label());
				 this->Hobbies = (gcnew System::Windows::Forms::Label());
				 this->userDescriptionLabel = (gcnew System::Windows::Forms::Label());
				 this->Label13 = (gcnew System::Windows::Forms::Label());
				 this->RatingPersent = (gcnew System::Windows::Forms::Label());
				 this->UserName = (gcnew System::Windows::Forms::Label());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->Settings = (gcnew System::Windows::Forms::Button());
				 this->Friends = (gcnew System::Windows::Forms::Button());
				 this->History = (gcnew System::Windows::Forms::Button());
				 this->Messages = (gcnew System::Windows::Forms::Button());
				 this->Buttons = (gcnew System::Windows::Forms::Panel());
				 this->mapButton = (gcnew System::Windows::Forms::Button());
				 this->profileButton = (gcnew System::Windows::Forms::Button());
				 this->SettingsPanel = (gcnew System::Windows::Forms::Panel());
				 this->userDrinksChangeField = (gcnew System::Windows::Forms::TextBox());
				 this->userHobbyChangeField = (gcnew System::Windows::Forms::TextBox());
				 this->userDescriptionChangeField = (gcnew System::Windows::Forms::TextBox());
				 this->label18 = (gcnew System::Windows::Forms::Label());
				 this->label17 = (gcnew System::Windows::Forms::Label());
				 this->label16 = (gcnew System::Windows::Forms::Label());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->textBox6 = (gcnew System::Windows::Forms::TextBox());
				 this->saveEmailChanges = (gcnew System::Windows::Forms::Button());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->newNameField = (gcnew System::Windows::Forms::TextBox());
				 this->newSurnameField = (gcnew System::Windows::Forms::TextBox());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->GeoPosition = (gcnew System::Windows::Forms::CheckBox());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->newPasswordField = (gcnew System::Windows::Forms::TextBox());
				 this->currentPasswordField = (gcnew System::Windows::Forms::TextBox());
				 this->ChangePass = (gcnew System::Windows::Forms::Button());
				 this->ChangeProfileImage = (gcnew System::Windows::Forms::Button());
				 this->ProfileImage = (gcnew System::Windows::Forms::PictureBox());
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->descriptionChangeButton = (gcnew System::Windows::Forms::Button());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->button4 = (gcnew System::Windows::Forms::Button());
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
				 this->PictureProfile->Location = System::Drawing::Point(29, 14);
				 this->PictureProfile->Margin = System::Windows::Forms::Padding(4);
				 this->PictureProfile->Name = L"PictureProfile";
				 this->PictureProfile->Size = System::Drawing::Size(187, 169);
				 this->PictureProfile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->PictureProfile->TabIndex = 0;
				 this->PictureProfile->TabStop = false;
				 // 
				 // Drunk
				 // 
				 this->Drunk->Location = System::Drawing::Point(322, 438);
				 this->Drunk->Margin = System::Windows::Forms::Padding(4);
				 this->Drunk->Name = L"Drunk";
				 this->Drunk->Size = System::Drawing::Size(153, 47);
				 this->Drunk->TabIndex = 6;
				 this->Drunk->Text = L"Хочу бухать!";
				 this->Drunk->UseVisualStyleBackColor = true;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(43, 253);
				 this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(53, 17);
				 this->label1->TabIndex = 4;
				 this->label1->Text = L"Rating:";
				 // 
				 // Rating
				 // 
				 this->Rating->Location = System::Drawing::Point(46, 300);
				 this->Rating->Margin = System::Windows::Forms::Padding(4);
				 this->Rating->Maximum = 50;
				 this->Rating->Name = L"Rating";
				 this->Rating->Size = System::Drawing::Size(133, 28);
				 this->Rating->TabIndex = 3;
				 // 
				 // FriendsPanel
				 // 
				 this->FriendsPanel->Controls->Add(this->label11);
				 this->FriendsPanel->Controls->Add(this->resultListBox);
				 this->FriendsPanel->Controls->Add(this->searchButton);
				 this->FriendsPanel->Controls->Add(this->searchField);
				 this->FriendsPanel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
				 this->FriendsPanel->Location = System::Drawing::Point(54, 129);
				 this->FriendsPanel->Margin = System::Windows::Forms::Padding(4);
				 this->FriendsPanel->Name = L"FriendsPanel";
				 this->FriendsPanel->Size = System::Drawing::Size(1139, 663);
				 this->FriendsPanel->TabIndex = 12;
				 this->FriendsPanel->Visible = false;
				 // 
				 // label11
				 // 
				 this->label11->AutoSize = true;
				 this->label11->Location = System::Drawing::Point(241, 39);
				 this->label11->Name = L"label11";
				 this->label11->Size = System::Drawing::Size(56, 17);
				 this->label11->TabIndex = 17;
				 this->label11->Text = L"Друзья";
				 // 
				 // resultListBox
				 // 
				 this->resultListBox->FormattingEnabled = true;
				 this->resultListBox->ItemHeight = 16;
				 this->resultListBox->Location = System::Drawing::Point(37, 194);
				 this->resultListBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->resultListBox->Name = L"resultListBox";
				 this->resultListBox->Size = System::Drawing::Size(323, 292);
				 this->resultListBox->TabIndex = 16;
				 // 
				 // searchButton
				 // 
				 this->searchButton->Location = System::Drawing::Point(398, 137);
				 this->searchButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->searchButton->Name = L"searchButton";
				 this->searchButton->Size = System::Drawing::Size(75, 23);
				 this->searchButton->TabIndex = 15;
				 this->searchButton->Text = L"Поиск";
				 this->searchButton->UseVisualStyleBackColor = true;
				 this->searchButton->Click += gcnew System::EventHandler(this, &Map::searchButton_Click);
				 // 
				 // searchField
				 // 
				 this->searchField->Location = System::Drawing::Point(37, 138);
				 this->searchField->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->searchField->Name = L"searchField";
				 this->searchField->Size = System::Drawing::Size(323, 22);
				 this->searchField->TabIndex = 14;
				 // 
				 // HistoryPanel
				 // 
				 this->HistoryPanel->Controls->Add(this->label9);
				 this->HistoryPanel->Location = System::Drawing::Point(831, 8);
				 this->HistoryPanel->Margin = System::Windows::Forms::Padding(4);
				 this->HistoryPanel->Name = L"HistoryPanel";
				 this->HistoryPanel->Size = System::Drawing::Size(1139, 663);
				 this->HistoryPanel->TabIndex = 12;
				 this->HistoryPanel->Visible = false;
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Location = System::Drawing::Point(580, 20);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(64, 17);
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
				 this->MessagesPanel->Controls->Add(this->profilePanel);
				 this->MessagesPanel->Controls->Add(this->label10);
				 this->MessagesPanel->Location = System::Drawing::Point(617, 22);
				 this->MessagesPanel->Margin = System::Windows::Forms::Padding(4);
				 this->MessagesPanel->Name = L"MessagesPanel";
				 this->MessagesPanel->Size = System::Drawing::Size(1139, 663);
				 this->MessagesPanel->TabIndex = 12;
				 this->MessagesPanel->Visible = false;
				 // 
				 // profilePanel
				 // 
				 this->profilePanel->Controls->Add(this->label15);
				 this->profilePanel->Controls->Add(this->usersAlcoholLabel);
				 this->profilePanel->Controls->Add(this->Label14);
				 this->profilePanel->Controls->Add(this->userHobbiesLabel);
				 this->profilePanel->Controls->Add(this->Hobbies);
				 this->profilePanel->Controls->Add(this->userDescriptionLabel);
				 this->profilePanel->Controls->Add(this->Label13);
				 this->profilePanel->Controls->Add(this->PictureProfile);
				 this->profilePanel->Controls->Add(this->Drunk);
				 this->profilePanel->Controls->Add(this->RatingPersent);
				 this->profilePanel->Controls->Add(this->Rating);
				 this->profilePanel->Controls->Add(this->UserName);
				 this->profilePanel->Controls->Add(this->label1);
				 this->profilePanel->Location = System::Drawing::Point(54, 66);
				 this->profilePanel->Name = L"profilePanel";
				 this->profilePanel->Size = System::Drawing::Size(1139, 663);
				 this->profilePanel->TabIndex = 13;
				 // 
				 // label15
				 // 
				 this->label15->AutoSize = true;
				 this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(204)));
				 this->label15->Location = System::Drawing::Point(691, 438);
				 this->label15->Name = L"label15";
				 this->label15->Size = System::Drawing::Size(370, 20);
				 this->label15->TabIndex = 18;
				 this->label15->Text = L"придумать еще полей для заполнения";
				 // 
				 // usersAlcoholLabel
				 // 
				 this->usersAlcoholLabel->AutoSize = true;
				 this->usersAlcoholLabel->Location = System::Drawing::Point(788, 312);
				 this->usersAlcoholLabel->Name = L"usersAlcoholLabel";
				 this->usersAlcoholLabel->Size = System::Drawing::Size(147, 17);
				 this->usersAlcoholLabel->TabIndex = 17;
				 this->usersAlcoholLabel->Text = L"user\'s favourite drinks";
				 // 
				 // Label14
				 // 
				 this->Label14->AutoSize = true;
				 this->Label14->Location = System::Drawing::Point(841, 280);
				 this->Label14->Name = L"Label14";
				 this->Label14->Size = System::Drawing::Size(129, 17);
				 this->Label14->TabIndex = 16;
				 this->Label14->Text = L"Любимые напитки";
				 // 
				 // userHobbiesLabel
				 // 
				 this->userHobbiesLabel->AutoSize = true;
				 this->userHobbiesLabel->Location = System::Drawing::Point(788, 173);
				 this->userHobbiesLabel->Name = L"userHobbiesLabel";
				 this->userHobbiesLabel->Size = System::Drawing::Size(162, 17);
				 this->userHobbiesLabel->TabIndex = 15;
				 this->userHobbiesLabel->Text = L"user\'s hobby description";
				 // 
				 // Hobbies
				 // 
				 this->Hobbies->AutoSize = true;
				 this->Hobbies->Location = System::Drawing::Point(853, 148);
				 this->Hobbies->Name = L"Hobbies";
				 this->Hobbies->Size = System::Drawing::Size(160, 17);
				 this->Hobbies->TabIndex = 14;
				 this->Hobbies->Text = L"Интересы и увлечения";
				 // 
				 // userDescriptionLabel
				 // 
				 this->userDescriptionLabel->AutoSize = true;
				 this->userDescriptionLabel->Location = System::Drawing::Point(788, 41);
				 this->userDescriptionLabel->Name = L"userDescriptionLabel";
				 this->userDescriptionLabel->Size = System::Drawing::Size(157, 17);
				 this->userDescriptionLabel->TabIndex = 13;
				 this->userDescriptionLabel->Text = L"Some words about user";
				 // 
				 // Label13
				 // 
				 this->Label13->AutoSize = true;
				 this->Label13->Location = System::Drawing::Point(853, 14);
				 this->Label13->Name = L"Label13";
				 this->Label13->Size = System::Drawing::Size(54, 17);
				 this->Label13->TabIndex = 12;
				 this->Label13->Text = L"О себе";
				 // 
				 // RatingPersent
				 // 
				 this->RatingPersent->AutoSize = true;
				 this->RatingPersent->Location = System::Drawing::Point(144, 252);
				 this->RatingPersent->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->RatingPersent->Name = L"RatingPersent";
				 this->RatingPersent->Size = System::Drawing::Size(36, 17);
				 this->RatingPersent->TabIndex = 11;
				 this->RatingPersent->Text = L"60%";
				 this->RatingPersent->TextAlign = System::Drawing::ContentAlignment::TopRight;
				 // 
				 // UserName
				 // 
				 this->UserName->AutoSize = true;
				 this->UserName->Location = System::Drawing::Point(47, 201);
				 this->UserName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->UserName->Name = L"UserName";
				 this->UserName->Size = System::Drawing::Size(33, 17);
				 this->UserName->TabIndex = 10;
				 this->UserName->Text = L"Ник";
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Location = System::Drawing::Point(187, 41);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(84, 17);
				 this->label10->TabIndex = 14;
				 this->label10->Text = L"Сообщения";
				 // 
				 // Settings
				 // 
				 this->Settings->Location = System::Drawing::Point(13, 181);
				 this->Settings->Margin = System::Windows::Forms::Padding(4);
				 this->Settings->Name = L"Settings";
				 this->Settings->Size = System::Drawing::Size(167, 30);
				 this->Settings->TabIndex = 5;
				 this->Settings->Text = L"Настройки";
				 this->Settings->UseVisualStyleBackColor = true;
				 this->Settings->Click += gcnew System::EventHandler(this, &Map::Settings_Click);
				 // 
				 // Friends
				 // 
				 this->Friends->Location = System::Drawing::Point(13, 44);
				 this->Friends->Margin = System::Windows::Forms::Padding(4);
				 this->Friends->Name = L"Friends";
				 this->Friends->Size = System::Drawing::Size(167, 28);
				 this->Friends->TabIndex = 7;
				 this->Friends->Text = L"Друзья";
				 this->Friends->UseVisualStyleBackColor = true;
				 this->Friends->Click += gcnew System::EventHandler(this, &Map::Friends_Click);
				 // 
				 // History
				 // 
				 this->History->Location = System::Drawing::Point(13, 145);
				 this->History->Margin = System::Windows::Forms::Padding(4);
				 this->History->Name = L"History";
				 this->History->Size = System::Drawing::Size(167, 28);
				 this->History->TabIndex = 8;
				 this->History->Text = L"История";
				 this->History->UseVisualStyleBackColor = true;
				 this->History->Click += gcnew System::EventHandler(this, &Map::History_Click);
				 // 
				 // Messages
				 // 
				 this->Messages->Location = System::Drawing::Point(13, 80);
				 this->Messages->Margin = System::Windows::Forms::Padding(4);
				 this->Messages->Name = L"Messages";
				 this->Messages->Size = System::Drawing::Size(167, 28);
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
				 this->Buttons->Location = System::Drawing::Point(13, 8);
				 this->Buttons->Margin = System::Windows::Forms::Padding(4);
				 this->Buttons->Name = L"Buttons";
				 this->Buttons->Size = System::Drawing::Size(192, 652);
				 this->Buttons->TabIndex = 10;
				 // 
				 // mapButton
				 // 
				 this->mapButton->Location = System::Drawing::Point(13, 115);
				 this->mapButton->Name = L"mapButton";
				 this->mapButton->Size = System::Drawing::Size(167, 23);
				 this->mapButton->TabIndex = 13;
				 this->mapButton->Text = L"Карта";
				 this->mapButton->UseVisualStyleBackColor = true;
				 // 
				 // profileButton
				 // 
				 this->profileButton->Location = System::Drawing::Point(13, 14);
				 this->profileButton->Name = L"profileButton";
				 this->profileButton->Size = System::Drawing::Size(167, 23);
				 this->profileButton->TabIndex = 12;
				 this->profileButton->Text = L"Мой профиль";
				 this->profileButton->UseVisualStyleBackColor = true;
				 this->profileButton->Click += gcnew System::EventHandler(this, &Map::profileButton_Click);
				 // 
				 // SettingsPanel
				 // 
				 this->SettingsPanel->Controls->Add(this->button4);
				 this->SettingsPanel->Controls->Add(this->button3);
				 this->SettingsPanel->Controls->Add(this->descriptionChangeButton);
				 this->SettingsPanel->Controls->Add(this->userDrinksChangeField);
				 this->SettingsPanel->Controls->Add(this->userHobbyChangeField);
				 this->SettingsPanel->Controls->Add(this->userDescriptionChangeField);
				 this->SettingsPanel->Controls->Add(this->label18);
				 this->SettingsPanel->Controls->Add(this->label17);
				 this->SettingsPanel->Controls->Add(this->label16);
				 this->SettingsPanel->Controls->Add(this->label8);
				 this->SettingsPanel->Controls->Add(this->label6);
				 this->SettingsPanel->Controls->Add(this->label7);
				 this->SettingsPanel->Controls->Add(this->textBox6);
				 this->SettingsPanel->Controls->Add(this->saveEmailChanges);
				 this->SettingsPanel->Controls->Add(this->label4);
				 this->SettingsPanel->Controls->Add(this->label5);
				 this->SettingsPanel->Controls->Add(this->newNameField);
				 this->SettingsPanel->Controls->Add(this->newSurnameField);
				 this->SettingsPanel->Controls->Add(this->button1);
				 this->SettingsPanel->Controls->Add(this->GeoPosition);
				 this->SettingsPanel->Controls->Add(this->label3);
				 this->SettingsPanel->Controls->Add(this->label2);
				 this->SettingsPanel->Controls->Add(this->newPasswordField);
				 this->SettingsPanel->Controls->Add(this->currentPasswordField);
				 this->SettingsPanel->Controls->Add(this->ChangePass);
				 this->SettingsPanel->Controls->Add(this->ChangeProfileImage);
				 this->SettingsPanel->Controls->Add(this->ProfileImage);
				 this->SettingsPanel->Location = System::Drawing::Point(216, 12);
				 this->SettingsPanel->Margin = System::Windows::Forms::Padding(4);
				 this->SettingsPanel->Name = L"SettingsPanel";
				 this->SettingsPanel->Size = System::Drawing::Size(1139, 663);
				 this->SettingsPanel->TabIndex = 12;
				 this->SettingsPanel->Visible = false;
				 // 
				 // userDrinksChangeField
				 // 
				 this->userDrinksChangeField->Location = System::Drawing::Point(777, 523);
				 this->userDrinksChangeField->Multiline = true;
				 this->userDrinksChangeField->Name = L"userDrinksChangeField";
				 this->userDrinksChangeField->Size = System::Drawing::Size(239, 125);
				 this->userDrinksChangeField->TabIndex = 38;
				 // 
				 // userHobbyChangeField
				 // 
				 this->userHobbyChangeField->Location = System::Drawing::Point(777, 282);
				 this->userHobbyChangeField->Multiline = true;
				 this->userHobbyChangeField->Name = L"userHobbyChangeField";
				 this->userHobbyChangeField->Size = System::Drawing::Size(239, 123);
				 this->userHobbyChangeField->TabIndex = 37;
				 // 
				 // userDescriptionChangeField
				 // 
				 this->userDescriptionChangeField->Location = System::Drawing::Point(777, 51);
				 this->userDescriptionChangeField->Multiline = true;
				 this->userDescriptionChangeField->Name = L"userDescriptionChangeField";
				 this->userDescriptionChangeField->Size = System::Drawing::Size(239, 125);
				 this->userDescriptionChangeField->TabIndex = 36;
				 // 
				 // label18
				 // 
				 this->label18->AutoSize = true;
				 this->label18->Location = System::Drawing::Point(806, 484);
				 this->label18->Name = L"label18";
				 this->label18->Size = System::Drawing::Size(136, 17);
				 this->label18->TabIndex = 35;
				 this->label18->Text = L"Любимые напитвки";
				 // 
				 // label17
				 // 
				 this->label17->AutoSize = true;
				 this->label17->Location = System::Drawing::Point(806, 250);
				 this->label17->Name = L"label17";
				 this->label17->Size = System::Drawing::Size(160, 17);
				 this->label17->TabIndex = 34;
				 this->label17->Text = L"Интересы и увлечения";
				 // 
				 // label16
				 // 
				 this->label16->AutoSize = true;
				 this->label16->Location = System::Drawing::Point(806, 17);
				 this->label16->Name = L"label16";
				 this->label16->Size = System::Drawing::Size(54, 17);
				 this->label16->TabIndex = 33;
				 this->label16->Text = L"О себе";
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Location = System::Drawing::Point(336, 102);
				 this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(155, 17);
				 this->label8->TabIndex = 32;
				 this->label8->Text = L"exmple@sobutilnik.com";
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(143, 480);
				 this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(118, 17);
				 this->label6->TabIndex = 31;
				 this->label6->Text = L"Изменить почту:";
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(336, 86);
				 this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(53, 17);
				 this->label7->TabIndex = 30;
				 this->label7->Text = L"Почта:";
				 // 
				 // textBox6
				 // 
				 this->textBox6->Location = System::Drawing::Point(147, 500);
				 this->textBox6->Margin = System::Windows::Forms::Padding(4);
				 this->textBox6->Name = L"textBox6";
				 this->textBox6->Size = System::Drawing::Size(132, 22);
				 this->textBox6->TabIndex = 28;
				 // 
				 // saveEmailChanges
				 // 
				 this->saveEmailChanges->Location = System::Drawing::Point(146, 575);
				 this->saveEmailChanges->Margin = System::Windows::Forms::Padding(4);
				 this->saveEmailChanges->Name = L"saveEmailChanges";
				 this->saveEmailChanges->Size = System::Drawing::Size(100, 28);
				 this->saveEmailChanges->TabIndex = 27;
				 this->saveEmailChanges->Text = L"Изменить";
				 this->saveEmailChanges->UseVisualStyleBackColor = true;
				 this->saveEmailChanges->Click += gcnew System::EventHandler(this, &Map::saveChanges_Click);
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(252, 256);
				 this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(117, 17);
				 this->label4->TabIndex = 26;
				 this->label4->Text = L"Новая фамилия:";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(252, 304);
				 this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(82, 17);
				 this->label5->TabIndex = 25;
				 this->label5->Text = L"Новое имя:";
				 // 
				 // newNameField
				 // 
				 this->newNameField->Location = System::Drawing::Point(256, 324);
				 this->newNameField->Margin = System::Windows::Forms::Padding(4);
				 this->newNameField->Name = L"newNameField";
				 this->newNameField->Size = System::Drawing::Size(132, 22);
				 this->newNameField->TabIndex = 24;
				 // 
				 // newSurnameField
				 // 
				 this->newSurnameField->Location = System::Drawing::Point(256, 276);
				 this->newSurnameField->Margin = System::Windows::Forms::Padding(4);
				 this->newSurnameField->Name = L"newSurnameField";
				 this->newSurnameField->Size = System::Drawing::Size(132, 22);
				 this->newSurnameField->TabIndex = 23;
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(256, 356);
				 this->button1->Margin = System::Windows::Forms::Padding(4);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(100, 28);
				 this->button1->TabIndex = 22;
				 this->button1->Text = L"Изменить";
				 this->button1->UseVisualStyleBackColor = true;
				 // 
				 // GeoPosition
				 // 
				 this->GeoPosition->AutoSize = true;
				 this->GeoPosition->Checked = true;
				 this->GeoPosition->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->GeoPosition->Location = System::Drawing::Point(41, 415);
				 this->GeoPosition->Margin = System::Windows::Forms::Padding(4);
				 this->GeoPosition->Name = L"GeoPosition";
				 this->GeoPosition->Size = System::Drawing::Size(295, 21);
				 this->GeoPosition->TabIndex = 21;
				 this->GeoPosition->Text = L"Согласен на использования геолокации";
				 this->GeoPosition->UseVisualStyleBackColor = true;
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(35, 256);
				 this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(117, 17);
				 this->label3->TabIndex = 20;
				 this->label3->Text = L"Текущий пароль";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(35, 304);
				 this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(102, 17);
				 this->label2->TabIndex = 19;
				 this->label2->Text = L"Новый пароль";
				 // 
				 // newPasswordField
				 // 
				 this->newPasswordField->Location = System::Drawing::Point(39, 324);
				 this->newPasswordField->Margin = System::Windows::Forms::Padding(4);
				 this->newPasswordField->Name = L"newPasswordField";
				 this->newPasswordField->Size = System::Drawing::Size(132, 22);
				 this->newPasswordField->TabIndex = 18;
				 // 
				 // currentPasswordField
				 // 
				 this->currentPasswordField->Location = System::Drawing::Point(39, 276);
				 this->currentPasswordField->Margin = System::Windows::Forms::Padding(4);
				 this->currentPasswordField->Name = L"currentPasswordField";
				 this->currentPasswordField->Size = System::Drawing::Size(132, 22);
				 this->currentPasswordField->TabIndex = 17;
				 // 
				 // ChangePass
				 // 
				 this->ChangePass->Location = System::Drawing::Point(39, 356);
				 this->ChangePass->Margin = System::Windows::Forms::Padding(4);
				 this->ChangePass->Name = L"ChangePass";
				 this->ChangePass->Size = System::Drawing::Size(100, 28);
				 this->ChangePass->TabIndex = 16;
				 this->ChangePass->Text = L"Изменить";
				 this->ChangePass->UseVisualStyleBackColor = true;
				 // 
				 // ChangeProfileImage
				 // 
				 this->ChangeProfileImage->Location = System::Drawing::Point(141, 193);
				 this->ChangeProfileImage->Margin = System::Windows::Forms::Padding(4);
				 this->ChangeProfileImage->Name = L"ChangeProfileImage";
				 this->ChangeProfileImage->Size = System::Drawing::Size(187, 28);
				 this->ChangeProfileImage->TabIndex = 15;
				 this->ChangeProfileImage->Text = L"Изменить";
				 this->ChangeProfileImage->UseVisualStyleBackColor = true;
				 this->ChangeProfileImage->Click += gcnew System::EventHandler(this, &Map::ChangeProfileImage_Click);
				 // 
				 // ProfileImage
				 // 
				 this->ProfileImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ProfileImage.Image")));
				 this->ProfileImage->Location = System::Drawing::Point(141, 17);
				 this->ProfileImage->Margin = System::Windows::Forms::Padding(4);
				 this->ProfileImage->Name = L"ProfileImage";
				 this->ProfileImage->Size = System::Drawing::Size(187, 169);
				 this->ProfileImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->ProfileImage->TabIndex = 14;
				 this->ProfileImage->TabStop = false;
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 // 
				 // descriptionChangeButton
				 // 
				 this->descriptionChangeButton->Location = System::Drawing::Point(1034, 150);
				 this->descriptionChangeButton->Name = L"descriptionChangeButton";
				 this->descriptionChangeButton->Size = System::Drawing::Size(86, 23);
				 this->descriptionChangeButton->TabIndex = 39;
				 this->descriptionChangeButton->Text = L"Изменить";
				 this->descriptionChangeButton->UseVisualStyleBackColor = true;
				 this->descriptionChangeButton->Click += gcnew System::EventHandler(this, &Map::descriptionChangeButton_Click);
				 // 
				 // button3
				 // 
				 this->button3->Location = System::Drawing::Point(1034, 381);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(86, 23);
				 this->button3->TabIndex = 40;
				 this->button3->Text = L"Изменить";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &Map::button3_Click);
				 // 
				 // button4
				 // 
				 this->button4->Location = System::Drawing::Point(1034, 625);
				 this->button4->Name = L"button4";
				 this->button4->Size = System::Drawing::Size(86, 23);
				 this->button4->TabIndex = 41;
				 this->button4->Text = L"Изменить";
				 this->button4->UseVisualStyleBackColor = true;
				 this->button4->Click += gcnew System::EventHandler(this, &Map::button4_Click);
				 // 
				 // Map
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1363, 673);
				 this->Controls->Add(this->SettingsPanel);
				 this->Controls->Add(this->Buttons);
				 this->Controls->Add(this->HistoryPanel);
				 this->Controls->Add(this->FriendsPanel);
				 this->Controls->Add(this->MessagesPanel);
				 this->Margin = System::Windows::Forms::Padding(4);
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
private: System::Void descriptionChangeButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
};
}
