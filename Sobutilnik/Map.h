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
	/// ������ ��� Map
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
		/// ���������� ��� ������������ �������.
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
<<<<<<< HEAD
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

=======
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  profileCloseButton;
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14

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
			 /// ������������ ���������� ������������.
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
				 this->PictureProfile->Location = System::Drawing::Point(22, 11);
				 this->PictureProfile->Name = L"PictureProfile";
				 this->PictureProfile->Size = System::Drawing::Size(140, 137);
				 this->PictureProfile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->PictureProfile->TabIndex = 0;
				 this->PictureProfile->TabStop = false;
				 // 
				 // Drunk
				 // 
<<<<<<< HEAD
				 this->Drunk->Location = System::Drawing::Point(322, 438);
				 this->Drunk->Margin = System::Windows::Forms::Padding(4);
=======
				 this->Drunk->Location = System::Drawing::Point(101, 332);
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
				 this->Drunk->Name = L"Drunk";
				 this->Drunk->Size = System::Drawing::Size(115, 38);
				 this->Drunk->TabIndex = 6;
				 this->Drunk->Text = L"���� ������!";
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
<<<<<<< HEAD
				 this->FriendsPanel->Size = System::Drawing::Size(1139, 663);
=======
				 this->FriendsPanel->Size = System::Drawing::Size(391, 539);
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
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
				 this->label11->Text = L"������";
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
				 this->searchButton->Text = L"�����";
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
<<<<<<< HEAD
=======
				 // FriendsCloseButton
				 // 
				 this->FriendsCloseButton->Location = System::Drawing::Point(313, 13);
				 this->FriendsCloseButton->Name = L"FriendsCloseButton";
				 this->FriendsCloseButton->Size = System::Drawing::Size(75, 23);
				 this->FriendsCloseButton->TabIndex = 13;
				 this->FriendsCloseButton->Text = L"Close";
				 this->FriendsCloseButton->UseVisualStyleBackColor = true;
				 this->FriendsCloseButton->Click += gcnew System::EventHandler(this, &Map::FriendsCloseButton_Click);
				 // 
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
				 // HistoryPanel
				 // 
				 this->HistoryPanel->Controls->Add(this->label9);
<<<<<<< HEAD
				 this->HistoryPanel->Location = System::Drawing::Point(831, 8);
				 this->HistoryPanel->Margin = System::Windows::Forms::Padding(4);
				 this->HistoryPanel->Name = L"HistoryPanel";
				 this->HistoryPanel->Size = System::Drawing::Size(1139, 663);
				 this->HistoryPanel->TabIndex = 12;
				 this->HistoryPanel->Visible = false;
				 // 
=======
				 this->HistoryPanel->Controls->Add(this->HistoryCloseButton);
				 this->HistoryPanel->Controls->Add(this->FriendsPanel);
				 this->HistoryPanel->Location = System::Drawing::Point(623, 6);
				 this->HistoryPanel->Name = L"HistoryPanel";
				 this->HistoryPanel->Size = System::Drawing::Size(389, 539);
				 this->HistoryPanel->TabIndex = 12;
				 this->HistoryPanel->Visible = false;
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Location = System::Drawing::Point(125, 16);
				 this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(50, 13);
				 this->label12->TabIndex = 15;
				 this->label12->Text = L"�������";
				 // 
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Location = System::Drawing::Point(435, 16);
				 this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(50, 13);
				 this->label9->TabIndex = 14;
				 this->label9->Text = L"�������";
				 // 
				 // label12
				 // 
<<<<<<< HEAD
				 this->label12->AutoSize = true;
				 this->label12->Location = System::Drawing::Point(167, 20);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(64, 17);
				 this->label12->TabIndex = 15;
				 this->label12->Text = L"�������";
=======
				 this->HistoryCloseButton->Location = System::Drawing::Point(305, 11);
				 this->HistoryCloseButton->Name = L"HistoryCloseButton";
				 this->HistoryCloseButton->Size = System::Drawing::Size(75, 23);
				 this->HistoryCloseButton->TabIndex = 13;
				 this->HistoryCloseButton->Text = L"Close";
				 this->HistoryCloseButton->UseVisualStyleBackColor = true;
				 this->HistoryCloseButton->Click += gcnew System::EventHandler(this, &Map::HistoryCloseButton_Click);
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
				 // 
				 // MessagesPanel
				 // 
				 this->MessagesPanel->Controls->Add(this->profilePanel);
				 this->MessagesPanel->Controls->Add(this->label10);
<<<<<<< HEAD
				 this->MessagesPanel->Location = System::Drawing::Point(617, 22);
				 this->MessagesPanel->Margin = System::Windows::Forms::Padding(4);
				 this->MessagesPanel->Name = L"MessagesPanel";
				 this->MessagesPanel->Size = System::Drawing::Size(1139, 663);
=======
				 this->MessagesPanel->Controls->Add(this->MessagesCloseButton);
				 this->MessagesPanel->Location = System::Drawing::Point(547, 18);
				 this->MessagesPanel->Name = L"MessagesPanel";
				 this->MessagesPanel->Size = System::Drawing::Size(391, 539);
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
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
				 this->label15->Text = L"��������� ��� ����� ��� ����������";
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
				 this->Label14->Text = L"������� �������";
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
				 this->Hobbies->Text = L"�������� � ���������";
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
				 this->Label13->Text = L"� ����";
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
				 this->UserName->Text = L"���";
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Location = System::Drawing::Point(140, 33);
				 this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(65, 13);
				 this->label10->TabIndex = 14;
				 this->label10->Text = L"���������";
				 // 
<<<<<<< HEAD
=======
				 // MessagesCloseButton
				 // 
				 this->MessagesCloseButton->Location = System::Drawing::Point(286, 28);
				 this->MessagesCloseButton->Name = L"MessagesCloseButton";
				 this->MessagesCloseButton->Size = System::Drawing::Size(75, 23);
				 this->MessagesCloseButton->TabIndex = 13;
				 this->MessagesCloseButton->Text = L"Close";
				 this->MessagesCloseButton->UseVisualStyleBackColor = true;
				 this->MessagesCloseButton->Click += gcnew System::EventHandler(this, &Map::MessagesCloseButton_Click);
				 // 
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
				 // Settings
				 // 
				 this->Settings->Location = System::Drawing::Point(10, 147);
				 this->Settings->Name = L"Settings";
				 this->Settings->Size = System::Drawing::Size(125, 24);
				 this->Settings->TabIndex = 5;
				 this->Settings->Text = L"���������";
				 this->Settings->UseVisualStyleBackColor = true;
				 this->Settings->Click += gcnew System::EventHandler(this, &Map::Settings_Click);
				 // 
				 // Friends
				 // 
				 this->Friends->Location = System::Drawing::Point(10, 36);
				 this->Friends->Name = L"Friends";
				 this->Friends->Size = System::Drawing::Size(125, 23);
				 this->Friends->TabIndex = 7;
				 this->Friends->Text = L"������";
				 this->Friends->UseVisualStyleBackColor = true;
				 this->Friends->Click += gcnew System::EventHandler(this, &Map::Friends_Click);
				 // 
				 // History
				 // 
				 this->History->Location = System::Drawing::Point(10, 118);
				 this->History->Name = L"History";
				 this->History->Size = System::Drawing::Size(125, 23);
				 this->History->TabIndex = 8;
				 this->History->Text = L"�������";
				 this->History->UseVisualStyleBackColor = true;
				 this->History->Click += gcnew System::EventHandler(this, &Map::History_Click);
				 // 
				 // Messages
				 // 
				 this->Messages->Location = System::Drawing::Point(10, 65);
				 this->Messages->Name = L"Messages";
				 this->Messages->Size = System::Drawing::Size(125, 23);
				 this->Messages->TabIndex = 9;
				 this->Messages->Text = L"���������";
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
				 this->mapButton->Location = System::Drawing::Point(10, 93);
				 this->mapButton->Margin = System::Windows::Forms::Padding(2);
				 this->mapButton->Name = L"mapButton";
				 this->mapButton->Size = System::Drawing::Size(125, 19);
				 this->mapButton->TabIndex = 13;
				 this->mapButton->Text = L"�����";
				 this->mapButton->UseVisualStyleBackColor = true;
				 // 
				 // profileButton
				 // 
				 this->profileButton->Location = System::Drawing::Point(10, 11);
				 this->profileButton->Margin = System::Windows::Forms::Padding(2);
				 this->profileButton->Name = L"profileButton";
				 this->profileButton->Size = System::Drawing::Size(125, 19);
				 this->profileButton->TabIndex = 12;
				 this->profileButton->Text = L"��� �������";
				 this->profileButton->UseVisualStyleBackColor = true;
<<<<<<< HEAD
				 this->profileButton->Click += gcnew System::EventHandler(this, &Map::profileButton_Click);
=======
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
				 this->UserName->Text = L"���";
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
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
<<<<<<< HEAD
				 this->SettingsPanel->Location = System::Drawing::Point(216, 12);
				 this->SettingsPanel->Margin = System::Windows::Forms::Padding(4);
				 this->SettingsPanel->Name = L"SettingsPanel";
				 this->SettingsPanel->Size = System::Drawing::Size(1139, 663);
=======
				 this->SettingsPanel->Controls->Add(this->SettingsCloseButton);
				 this->SettingsPanel->Location = System::Drawing::Point(570, 9);
				 this->SettingsPanel->Name = L"SettingsPanel";
				 this->SettingsPanel->Size = System::Drawing::Size(368, 538);
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
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
				 this->label18->Text = L"������� ��������";
				 // 
				 // label17
				 // 
				 this->label17->AutoSize = true;
				 this->label17->Location = System::Drawing::Point(806, 250);
				 this->label17->Name = L"label17";
				 this->label17->Size = System::Drawing::Size(160, 17);
				 this->label17->TabIndex = 34;
				 this->label17->Text = L"�������� � ���������";
				 // 
				 // label16
				 // 
				 this->label16->AutoSize = true;
				 this->label16->Location = System::Drawing::Point(806, 17);
				 this->label16->Name = L"label16";
				 this->label16->Size = System::Drawing::Size(54, 17);
				 this->label16->TabIndex = 33;
				 this->label16->Text = L"� ����";
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Location = System::Drawing::Point(252, 83);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(118, 13);
				 this->label8->TabIndex = 32;
				 this->label8->Text = L"exmple@sobutilnik.com";
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(107, 390);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(91, 13);
				 this->label6->TabIndex = 31;
				 this->label6->Text = L"�������� �����:";
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(252, 70);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(40, 13);
				 this->label7->TabIndex = 30;
				 this->label7->Text = L"�����:";
				 // 
				 // textBox6
				 // 
				 this->textBox6->Location = System::Drawing::Point(110, 406);
				 this->textBox6->Name = L"textBox6";
				 this->textBox6->Size = System::Drawing::Size(100, 20);
				 this->textBox6->TabIndex = 28;
				 // 
				 // saveEmailChanges
				 // 
<<<<<<< HEAD
				 this->saveEmailChanges->Location = System::Drawing::Point(146, 575);
				 this->saveEmailChanges->Margin = System::Windows::Forms::Padding(4);
				 this->saveEmailChanges->Name = L"saveEmailChanges";
				 this->saveEmailChanges->Size = System::Drawing::Size(100, 28);
				 this->saveEmailChanges->TabIndex = 27;
				 this->saveEmailChanges->Text = L"��������";
				 this->saveEmailChanges->UseVisualStyleBackColor = true;
				 this->saveEmailChanges->Click += gcnew System::EventHandler(this, &Map::saveChanges_Click);
=======
				 this->button2->Location = System::Drawing::Point(110, 432);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(75, 23);
				 this->button2->TabIndex = 27;
				 this->button2->Text = L"��������";
				 this->button2->UseVisualStyleBackColor = true;
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(189, 208);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(91, 13);
				 this->label4->TabIndex = 26;
				 this->label4->Text = L"����� �������:";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(189, 247);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(65, 13);
				 this->label5->TabIndex = 25;
				 this->label5->Text = L"����� ���:";
				 // 
				 // newNameField
				 // 
<<<<<<< HEAD
				 this->newNameField->Location = System::Drawing::Point(256, 324);
				 this->newNameField->Margin = System::Windows::Forms::Padding(4);
				 this->newNameField->Name = L"newNameField";
				 this->newNameField->Size = System::Drawing::Size(132, 22);
				 this->newNameField->TabIndex = 24;
=======
				 this->textBox3->Location = System::Drawing::Point(192, 263);
				 this->textBox3->Name = L"textBox3";
				 this->textBox3->Size = System::Drawing::Size(100, 20);
				 this->textBox3->TabIndex = 24;
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
				 // 
				 // newSurnameField
				 // 
<<<<<<< HEAD
				 this->newSurnameField->Location = System::Drawing::Point(256, 276);
				 this->newSurnameField->Margin = System::Windows::Forms::Padding(4);
				 this->newSurnameField->Name = L"newSurnameField";
				 this->newSurnameField->Size = System::Drawing::Size(132, 22);
				 this->newSurnameField->TabIndex = 23;
=======
				 this->textBox4->Location = System::Drawing::Point(192, 224);
				 this->textBox4->Name = L"textBox4";
				 this->textBox4->Size = System::Drawing::Size(100, 20);
				 this->textBox4->TabIndex = 23;
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(192, 289);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(75, 23);
				 this->button1->TabIndex = 22;
				 this->button1->Text = L"��������";
				 this->button1->UseVisualStyleBackColor = true;
				 // 
				 // GeoPosition
				 // 
				 this->GeoPosition->AutoSize = true;
				 this->GeoPosition->Checked = true;
				 this->GeoPosition->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->GeoPosition->Location = System::Drawing::Point(31, 337);
				 this->GeoPosition->Name = L"GeoPosition";
				 this->GeoPosition->Size = System::Drawing::Size(232, 17);
				 this->GeoPosition->TabIndex = 21;
				 this->GeoPosition->Text = L"�������� �� ������������� ����������";
				 this->GeoPosition->UseVisualStyleBackColor = true;
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(26, 208);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(91, 13);
				 this->label3->TabIndex = 20;
				 this->label3->Text = L"������� ������";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(26, 247);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(80, 13);
				 this->label2->TabIndex = 19;
				 this->label2->Text = L"����� ������";
				 // 
				 // newPasswordField
				 // 
<<<<<<< HEAD
				 this->newPasswordField->Location = System::Drawing::Point(39, 324);
				 this->newPasswordField->Margin = System::Windows::Forms::Padding(4);
				 this->newPasswordField->Name = L"newPasswordField";
				 this->newPasswordField->Size = System::Drawing::Size(132, 22);
				 this->newPasswordField->TabIndex = 18;
=======
				 this->textBox2->Location = System::Drawing::Point(29, 263);
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->Size = System::Drawing::Size(100, 20);
				 this->textBox2->TabIndex = 18;
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
				 // 
				 // currentPasswordField
				 // 
<<<<<<< HEAD
				 this->currentPasswordField->Location = System::Drawing::Point(39, 276);
				 this->currentPasswordField->Margin = System::Windows::Forms::Padding(4);
				 this->currentPasswordField->Name = L"currentPasswordField";
				 this->currentPasswordField->Size = System::Drawing::Size(132, 22);
				 this->currentPasswordField->TabIndex = 17;
=======
				 this->textBox1->Location = System::Drawing::Point(29, 224);
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(100, 20);
				 this->textBox1->TabIndex = 17;
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
				 // 
				 // ChangePass
				 // 
				 this->ChangePass->Location = System::Drawing::Point(29, 289);
				 this->ChangePass->Name = L"ChangePass";
				 this->ChangePass->Size = System::Drawing::Size(75, 23);
				 this->ChangePass->TabIndex = 16;
				 this->ChangePass->Text = L"��������";
				 this->ChangePass->UseVisualStyleBackColor = true;
				 // 
				 // ChangeProfileImage
				 // 
				 this->ChangeProfileImage->Location = System::Drawing::Point(106, 157);
				 this->ChangeProfileImage->Name = L"ChangeProfileImage";
				 this->ChangeProfileImage->Size = System::Drawing::Size(140, 23);
				 this->ChangeProfileImage->TabIndex = 15;
				 this->ChangeProfileImage->Text = L"��������";
				 this->ChangeProfileImage->UseVisualStyleBackColor = true;
				 this->ChangeProfileImage->Click += gcnew System::EventHandler(this, &Map::ChangeProfileImage_Click);
				 // 
				 // ProfileImage
				 // 
				 this->ProfileImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ProfileImage.Image")));
				 this->ProfileImage->Location = System::Drawing::Point(106, 14);
				 this->ProfileImage->Name = L"ProfileImage";
				 this->ProfileImage->Size = System::Drawing::Size(140, 137);
				 this->ProfileImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->ProfileImage->TabIndex = 14;
				 this->ProfileImage->TabStop = false;
				 // 
<<<<<<< HEAD
=======
				 // SettingsCloseButton
				 // 
				 this->SettingsCloseButton->Location = System::Drawing::Point(18, 14);
				 this->SettingsCloseButton->Name = L"SettingsCloseButton";
				 this->SettingsCloseButton->Size = System::Drawing::Size(75, 24);
				 this->SettingsCloseButton->TabIndex = 13;
				 this->SettingsCloseButton->Text = L"Close";
				 this->SettingsCloseButton->UseVisualStyleBackColor = true;
				 this->SettingsCloseButton->Click += gcnew System::EventHandler(this, &Map::SettingsCloseButton_Click);
				 // 
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 // 
<<<<<<< HEAD
				 // descriptionChangeButton
				 // 
				 this->descriptionChangeButton->Location = System::Drawing::Point(1034, 150);
				 this->descriptionChangeButton->Name = L"descriptionChangeButton";
				 this->descriptionChangeButton->Size = System::Drawing::Size(86, 23);
				 this->descriptionChangeButton->TabIndex = 39;
				 this->descriptionChangeButton->Text = L"��������";
				 this->descriptionChangeButton->UseVisualStyleBackColor = true;
				 this->descriptionChangeButton->Click += gcnew System::EventHandler(this, &Map::descriptionChangeButton_Click);
				 // 
				 // button3
				 // 
				 this->button3->Location = System::Drawing::Point(1034, 381);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(86, 23);
				 this->button3->TabIndex = 40;
				 this->button3->Text = L"��������";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &Map::button3_Click);
				 // 
				 // button4
				 // 
				 this->button4->Location = System::Drawing::Point(1034, 625);
				 this->button4->Name = L"button4";
				 this->button4->Size = System::Drawing::Size(86, 23);
				 this->button4->TabIndex = 41;
				 this->button4->Text = L"��������";
				 this->button4->UseVisualStyleBackColor = true;
				 this->button4->Click += gcnew System::EventHandler(this, &Map::button4_Click);
=======
				 // panel1
				 // 
				 this->panel1->Controls->Add(this->profileCloseButton);
				 this->panel1->Controls->Add(this->PictureProfile);
				 this->panel1->Controls->Add(this->Drunk);
				 this->panel1->Controls->Add(this->RatingPersent);
				 this->panel1->Controls->Add(this->Rating);
				 this->panel1->Controls->Add(this->UserName);
				 this->panel1->Controls->Add(this->label1);
				 this->panel1->Location = System::Drawing::Point(159, 6);
				 this->panel1->Margin = System::Windows::Forms::Padding(2);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(389, 539);
				 this->panel1->TabIndex = 13;
				 // 
				 // profileCloseButton
				 // 
				 this->profileCloseButton->Location = System::Drawing::Point(314, 15);
				 this->profileCloseButton->Margin = System::Windows::Forms::Padding(2);
				 this->profileCloseButton->Name = L"profileCloseButton";
				 this->profileCloseButton->Size = System::Drawing::Size(56, 19);
				 this->profileCloseButton->TabIndex = 12;
				 this->profileCloseButton->Text = L"button3";
				 this->profileCloseButton->UseVisualStyleBackColor = true;
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
				 // 
				 // Map
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
<<<<<<< HEAD
				 this->ClientSize = System::Drawing::Size(1363, 673);
=======
				 this->ClientSize = System::Drawing::Size(1022, 547);
				 this->Controls->Add(this->panel1);
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
				 this->Controls->Add(this->SettingsPanel);
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
<<<<<<< HEAD

private: System::Void profileButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void saveChanges_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void descriptionChangeButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
=======
>>>>>>> 5354824e9d827916bdde6861d16bbdd76d292c14
};
}
