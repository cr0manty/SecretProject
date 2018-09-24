#pragma once
#include<unordered_map>
#include<map>
#include "FirstPage.h"
#include <msclr/marshal.h>
#include <msclr\auto_gcroot.h>

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
		Map(FirstPage ^f) : mainPage(f), userId(5), isExitButton(0)
		{
			InitializeComponent();
			profileImage = nullptr;
		}
		Map(FirstPage ^f, int _id) : mainPage(f), userId(_id), isExitButton(0)
		{
			InitializeComponent();
			profileImage = nullptr;
			initLabels();
		}
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Map()
		{
			if (components)
			{
				delete searchResult;

				delete components;
			}
			delete mainPage;
			delete profileImage;
		}
	private: System::Windows::Forms::Button^  DeleteAcc;
	protected:
	private: System::Windows::Forms::Button^  ExitAccount;
	private:
		FirstPage ^mainPage;
		OleDbCommand ^command;
		OleDbDataReader ^reader;
		marshal_context^ marshal;
		bool isExitButton;
		void initLabels();
		String^ profileImage;
		void checkSearch();
		int userId;
		std::map<int,int> *searchResult = new std::map<int, int>;
		void uniqUser(System::Object^, const char*, System::Object^);
		void exitAcc();
	private: System::Windows::Forms::Label^  userSex;
	private: System::Windows::Forms::Label^  UserBirth;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  MainBirth;
	private: System::Windows::Forms::Label^  MainSex;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  MainSurname;
	private: System::Windows::Forms::Label^  MainName;
	private: System::Windows::Forms::Label^  MainLogin;
	private: System::Windows::Forms::TextBox^  newLogin;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  userSurname;
	private: System::Windows::Forms::Label^  userFirstName;
	private: System::Windows::Forms::Label^  userLogin;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  userAgeStatic;
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
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->profilePanel = (gcnew System::Windows::Forms::Panel());
				 this->label20 = (gcnew System::Windows::Forms::Label());
				 this->label21 = (gcnew System::Windows::Forms::Label());
				 this->label22 = (gcnew System::Windows::Forms::Label());
				 this->MainBirth = (gcnew System::Windows::Forms::Label());
				 this->MainSex = (gcnew System::Windows::Forms::Label());
				 this->label25 = (gcnew System::Windows::Forms::Label());
				 this->MainSurname = (gcnew System::Windows::Forms::Label());
				 this->MainName = (gcnew System::Windows::Forms::Label());
				 this->MainLogin = (gcnew System::Windows::Forms::Label());
				 this->label15 = (gcnew System::Windows::Forms::Label());
				 this->usersAlcoholLabel = (gcnew System::Windows::Forms::Label());
				 this->Drinks = (gcnew System::Windows::Forms::Label());
				 this->userHobbiesLabel = (gcnew System::Windows::Forms::Label());
				 this->Hobbies = (gcnew System::Windows::Forms::Label());
				 this->userDescriptionLabel = (gcnew System::Windows::Forms::Label());
				 this->aboutYourself = (gcnew System::Windows::Forms::Label());
				 this->RatingPersent = (gcnew System::Windows::Forms::Label());
				 this->SettingsPanel = (gcnew System::Windows::Forms::Panel());
				 this->DeleteAcc = (gcnew System::Windows::Forms::Button());
				 this->newLogin = (gcnew System::Windows::Forms::TextBox());
				 this->label23 = (gcnew System::Windows::Forms::Label());
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
				 this->ExitAccount = (gcnew System::Windows::Forms::Button());
				 this->Settings = (gcnew System::Windows::Forms::Button());
				 this->Friends = (gcnew System::Windows::Forms::Button());
				 this->History = (gcnew System::Windows::Forms::Button());
				 this->Messages = (gcnew System::Windows::Forms::Button());
				 this->Buttons = (gcnew System::Windows::Forms::Panel());
				 this->mapButton = (gcnew System::Windows::Forms::Button());
				 this->profileButton = (gcnew System::Windows::Forms::Button());
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureProfile))->BeginInit();
				 this->FriendsPanel->SuspendLayout();
				 this->HistoryPanel->SuspendLayout();
				 this->MessagesPanel->SuspendLayout();
				 this->profilePanel->SuspendLayout();
				 this->SettingsPanel->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProfileImage))->BeginInit();
				 this->Buttons->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // PictureProfile
				 // 
				 this->PictureProfile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureProfile.Image")));
				 this->PictureProfile->Location = System::Drawing::Point(29, 14);
				 this->PictureProfile->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->PictureProfile->Name = L"PictureProfile";
				 this->PictureProfile->Size = System::Drawing::Size(187, 169);
				 this->PictureProfile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->PictureProfile->TabIndex = 0;
				 this->PictureProfile->TabStop = false;
				 // 
				 // Drunk
				 // 
				 this->Drunk->Location = System::Drawing::Point(29, 261);
				 this->Drunk->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->Drunk->Name = L"Drunk";
				 this->Drunk->Size = System::Drawing::Size(187, 47);
				 this->Drunk->TabIndex = 6;
				 this->Drunk->Text = L"���� ������!";
				 this->Drunk->UseVisualStyleBackColor = true;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(25, 193);
				 this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(53, 17);
				 this->label1->TabIndex = 4;
				 this->label1->Text = L"Rating:";
				 // 
				 // Rating
				 // 
				 this->Rating->Location = System::Drawing::Point(29, 222);
				 this->Rating->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->Rating->Name = L"Rating";
				 this->Rating->Size = System::Drawing::Size(187, 28);
				 this->Rating->TabIndex = 3;
				 // 
				 // FriendsPanel
				 // 
				 this->FriendsPanel->Controls->Add(this->label11);
				 this->FriendsPanel->Controls->Add(this->resultListBox);
				 this->FriendsPanel->Controls->Add(this->searchButton);
				 this->FriendsPanel->Controls->Add(this->searchField);
				 this->FriendsPanel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
				 this->FriendsPanel->Location = System::Drawing::Point(213, 55);
				 this->FriendsPanel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->FriendsPanel->Name = L"FriendsPanel";
				 this->FriendsPanel->Size = System::Drawing::Size(485, 250);
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
				 this->label11->Text = L"������";
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
				 this->resultListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Map::resultListBox_SelectedIndexChanged);
				 // 
				 // searchButton
				 // 
				 this->searchButton->Location = System::Drawing::Point(397, 137);
				 this->searchButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->searchButton->Name = L"searchButton";
				 this->searchButton->Size = System::Drawing::Size(75, 23);
				 this->searchButton->TabIndex = 15;
				 this->searchButton->Text = L"�����";
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
				 this->HistoryPanel->Location = System::Drawing::Point(213, 497);
				 this->HistoryPanel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->HistoryPanel->Name = L"HistoryPanel";
				 this->HistoryPanel->Size = System::Drawing::Size(192, 162);
				 this->HistoryPanel->TabIndex = 12;
				 this->HistoryPanel->Visible = false;
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Location = System::Drawing::Point(21, 31);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(64, 17);
				 this->label9->TabIndex = 14;
				 this->label9->Text = L"�������";
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Location = System::Drawing::Point(167, 20);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(64, 17);
				 this->label12->TabIndex = 15;
				 this->label12->Text = L"�������";
				 // 
				 // MessagesPanel
				 // 
				 this->MessagesPanel->Controls->Add(this->label10);
				 this->MessagesPanel->Location = System::Drawing::Point(213, 313);
				 this->MessagesPanel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->MessagesPanel->Name = L"MessagesPanel";
				 this->MessagesPanel->Size = System::Drawing::Size(192, 177);
				 this->MessagesPanel->TabIndex = 12;
				 this->MessagesPanel->Visible = false;
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Location = System::Drawing::Point(44, 27);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(84, 17);
				 this->label10->TabIndex = 14;
				 this->label10->Text = L"���������";
				 // 
				 // profilePanel
				 // 
				 this->profilePanel->Controls->Add(this->label20);
				 this->profilePanel->Controls->Add(this->label21);
				 this->profilePanel->Controls->Add(this->label22);
				 this->profilePanel->Controls->Add(this->MainBirth);
				 this->profilePanel->Controls->Add(this->MainSex);
				 this->profilePanel->Controls->Add(this->label25);
				 this->profilePanel->Controls->Add(this->MainSurname);
				 this->profilePanel->Controls->Add(this->MainName);
				 this->profilePanel->Controls->Add(this->MainLogin);
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
				 this->profilePanel->Controls->Add(this->label1);
				 this->profilePanel->Location = System::Drawing::Point(213, 713);
				 this->profilePanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->profilePanel->Name = L"profilePanel";
				 this->profilePanel->Size = System::Drawing::Size(1149, 665);
				 this->profilePanel->TabIndex = 13;
				 // 
				 // label20
				 // 
				 this->label20->AutoSize = true;
				 this->label20->Location = System::Drawing::Point(236, 101);
				 this->label20->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label20->Name = L"label20";
				 this->label20->Size = System::Drawing::Size(74, 17);
				 this->label20->TabIndex = 60;
				 this->label20->Text = L"�������:";
				 // 
				 // label21
				 // 
				 this->label21->AutoSize = true;
				 this->label21->Location = System::Drawing::Point(236, 57);
				 this->label21->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label21->Name = L"label21";
				 this->label21->Size = System::Drawing::Size(39, 17);
				 this->label21->TabIndex = 59;
				 this->label21->Text = L"���:";
				 // 
				 // label22
				 // 
				 this->label22->AutoSize = true;
				 this->label22->Location = System::Drawing::Point(236, 14);
				 this->label22->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label22->Name = L"label22";
				 this->label22->Size = System::Drawing::Size(51, 17);
				 this->label22->TabIndex = 58;
				 this->label22->Text = L"�����:";
				 // 
				 // MainBirth
				 // 
				 this->MainBirth->AutoSize = true;
				 this->MainBirth->Location = System::Drawing::Point(236, 167);
				 this->MainBirth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->MainBirth->Name = L"MainBirth";
				 this->MainBirth->Size = System::Drawing::Size(80, 17);
				 this->MainBirth->TabIndex = 57;
				 this->MainBirth->Text = L"02/03/2018";
				 // 
				 // MainSex
				 // 
				 this->MainSex->AutoSize = true;
				 this->MainSex->Location = System::Drawing::Point(236, 193);
				 this->MainSex->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->MainSex->Name = L"MainSex";
				 this->MainSex->Size = System::Drawing::Size(53, 17);
				 this->MainSex->TabIndex = 56;
				 this->MainSex->Text = L"���: �";
				 // 
				 // label25
				 // 
				 this->label25->AutoSize = true;
				 this->label25->Location = System::Drawing::Point(236, 144);
				 this->label25->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label25->Name = L"label25";
				 this->label25->Size = System::Drawing::Size(115, 17);
				 this->label25->TabIndex = 55;
				 this->label25->Text = L"���� ��������:\r\n";
				 // 
				 // MainSurname
				 // 
				 this->MainSurname->AutoSize = true;
				 this->MainSurname->Location = System::Drawing::Point(236, 117);
				 this->MainSurname->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->MainSurname->Name = L"MainSurname";
				 this->MainSurname->Size = System::Drawing::Size(56, 17);
				 this->MainSurname->TabIndex = 54;
				 this->MainSurname->Text = L"������";
				 // 
				 // MainName
				 // 
				 this->MainName->AutoSize = true;
				 this->MainName->Location = System::Drawing::Point(236, 73);
				 this->MainName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->MainName->Name = L"MainName";
				 this->MainName->Size = System::Drawing::Size(64, 17);
				 this->MainName->TabIndex = 53;
				 this->MainName->Text = L"�������";
				 // 
				 // MainLogin
				 // 
				 this->MainLogin->AutoSize = true;
				 this->MainLogin->Location = System::Drawing::Point(236, 31);
				 this->MainLogin->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->MainLogin->Name = L"MainLogin";
				 this->MainLogin->Size = System::Drawing::Size(92, 17);
				 this->MainLogin->TabIndex = 52;
				 this->MainLogin->Text = L"nagibator228";
				 // 
				 // label15
				 // 
				 this->label15->AutoSize = true;
				 this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(204)));
				 this->label15->Location = System::Drawing::Point(25, 457);
				 this->label15->Name = L"label15";
				 this->label15->Size = System::Drawing::Size(370, 20);
				 this->label15->TabIndex = 18;
				 this->label15->Text = L"��������� ��� ����� ��� ����������";
				 // 
				 // usersAlcoholLabel
				 // 
				 this->usersAlcoholLabel->AutoSize = true;
				 this->usersAlcoholLabel->Location = System::Drawing::Point(529, 313);
				 this->usersAlcoholLabel->Name = L"usersAlcoholLabel";
				 this->usersAlcoholLabel->Size = System::Drawing::Size(147, 17);
				 this->usersAlcoholLabel->TabIndex = 17;
				 this->usersAlcoholLabel->Text = L"user\'s favourite drinks";
				 // 
				 // Drinks
				 // 
				 this->Drinks->AutoSize = true;
				 this->Drinks->Location = System::Drawing::Point(529, 282);
				 this->Drinks->Name = L"Drinks";
				 this->Drinks->Size = System::Drawing::Size(133, 17);
				 this->Drinks->TabIndex = 16;
				 this->Drinks->Text = L"������� �������:";
				 // 
				 // userHobbiesLabel
				 // 
				 this->userHobbiesLabel->AutoSize = true;
				 this->userHobbiesLabel->Location = System::Drawing::Point(529, 174);
				 this->userHobbiesLabel->Name = L"userHobbiesLabel";
				 this->userHobbiesLabel->Size = System::Drawing::Size(162, 17);
				 this->userHobbiesLabel->TabIndex = 15;
				 this->userHobbiesLabel->Text = L"user\'s hobby description";
				 // 
				 // Hobbies
				 // 
				 this->Hobbies->AutoSize = true;
				 this->Hobbies->Location = System::Drawing::Point(529, 145);
				 this->Hobbies->Name = L"Hobbies";
				 this->Hobbies->Size = System::Drawing::Size(164, 17);
				 this->Hobbies->TabIndex = 14;
				 this->Hobbies->Text = L"�������� � ���������:";
				 // 
				 // userDescriptionLabel
				 // 
				 this->userDescriptionLabel->AutoSize = true;
				 this->userDescriptionLabel->Location = System::Drawing::Point(529, 41);
				 this->userDescriptionLabel->Name = L"userDescriptionLabel";
				 this->userDescriptionLabel->Size = System::Drawing::Size(157, 17);
				 this->userDescriptionLabel->TabIndex = 13;
				 this->userDescriptionLabel->Text = L"Some words about user";
				 // 
				 // aboutYourself
				 // 
				 this->aboutYourself->AutoSize = true;
				 this->aboutYourself->Location = System::Drawing::Point(529, 15);
				 this->aboutYourself->Name = L"aboutYourself";
				 this->aboutYourself->Size = System::Drawing::Size(58, 17);
				 this->aboutYourself->TabIndex = 12;
				 this->aboutYourself->Text = L"� ����:";
				 // 
				 // RatingPersent
				 // 
				 this->RatingPersent->AutoSize = true;
				 this->RatingPersent->Location = System::Drawing::Point(180, 199);
				 this->RatingPersent->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->RatingPersent->Name = L"RatingPersent";
				 this->RatingPersent->Size = System::Drawing::Size(28, 17);
				 this->RatingPersent->TabIndex = 11;
				 this->RatingPersent->Text = L"0%";
				 this->RatingPersent->TextAlign = System::Drawing::ContentAlignment::TopRight;
				 // 
				 // SettingsPanel
				 // 
				 this->SettingsPanel->Controls->Add(this->DeleteAcc);
				 this->SettingsPanel->Controls->Add(this->newLogin);
				 this->SettingsPanel->Controls->Add(this->label23);
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
				 this->SettingsPanel->Location = System::Drawing::Point(707, 7);
				 this->SettingsPanel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->SettingsPanel->Name = L"SettingsPanel";
				 this->SettingsPanel->Size = System::Drawing::Size(1139, 663);
				 this->SettingsPanel->TabIndex = 12;
				 this->SettingsPanel->Visible = false;
				 // 
				 // DeleteAcc
				 // 
				 this->DeleteAcc->Location = System::Drawing::Point(21, 508);
				 this->DeleteAcc->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->DeleteAcc->Name = L"DeleteAcc";
				 this->DeleteAcc->Size = System::Drawing::Size(100, 28);
				 this->DeleteAcc->TabIndex = 54;
				 this->DeleteAcc->Text = L"�������";
				 this->DeleteAcc->UseVisualStyleBackColor = true;
				 this->DeleteAcc->Click += gcnew System::EventHandler(this, &Map::DeleteAcc_Click);
				 // 
				 // newLogin
				 // 
				 this->newLogin->Location = System::Drawing::Point(236, 463);
				 this->newLogin->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->newLogin->Name = L"newLogin";
				 this->newLogin->Size = System::Drawing::Size(132, 22);
				 this->newLogin->TabIndex = 53;
				 // 
				 // label23
				 // 
				 this->label23->AutoSize = true;
				 this->label23->Location = System::Drawing::Point(232, 443);
				 this->label23->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label23->Name = L"label23";
				 this->label23->Size = System::Drawing::Size(96, 17);
				 this->label23->TabIndex = 52;
				 this->label23->Text = L"����� �����:";
				 // 
				 // label14
				 // 
				 this->label14->AutoSize = true;
				 this->label14->Location = System::Drawing::Point(17, 59);
				 this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label14->Name = L"label14";
				 this->label14->Size = System::Drawing::Size(74, 17);
				 this->label14->TabIndex = 51;
				 this->label14->Text = L"�������:";
				 // 
				 // label13
				 // 
				 this->label13->AutoSize = true;
				 this->label13->Location = System::Drawing::Point(17, 15);
				 this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label13->Name = L"label13";
				 this->label13->Size = System::Drawing::Size(39, 17);
				 this->label13->TabIndex = 50;
				 this->label13->Text = L"���:";
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Location = System::Drawing::Point(232, 402);
				 this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(111, 17);
				 this->label8->TabIndex = 49;
				 this->label8->Text = L"������� �����:";
				 // 
				 // UserBirth
				 // 
				 this->UserBirth->AutoSize = true;
				 this->UserBirth->Location = System::Drawing::Point(17, 126);
				 this->UserBirth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->UserBirth->Name = L"UserBirth";
				 this->UserBirth->Size = System::Drawing::Size(80, 17);
				 this->UserBirth->TabIndex = 48;
				 this->UserBirth->Text = L"02/03/2018";
				 // 
				 // userSex
				 // 
				 this->userSex->AutoSize = true;
				 this->userSex->Location = System::Drawing::Point(17, 151);
				 this->userSex->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->userSex->Name = L"userSex";
				 this->userSex->Size = System::Drawing::Size(53, 17);
				 this->userSex->TabIndex = 47;
				 this->userSex->Text = L"���: �";
				 // 
				 // userAgeStatic
				 // 
				 this->userAgeStatic->AutoSize = true;
				 this->userAgeStatic->Location = System::Drawing::Point(17, 102);
				 this->userAgeStatic->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->userAgeStatic->Name = L"userAgeStatic";
				 this->userAgeStatic->Size = System::Drawing::Size(115, 17);
				 this->userAgeStatic->TabIndex = 46;
				 this->userAgeStatic->Text = L"���� ��������:\r\n";
				 // 
				 // userSurname
				 // 
				 this->userSurname->AutoSize = true;
				 this->userSurname->Location = System::Drawing::Point(17, 75);
				 this->userSurname->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->userSurname->Name = L"userSurname";
				 this->userSurname->Size = System::Drawing::Size(56, 17);
				 this->userSurname->TabIndex = 45;
				 this->userSurname->Text = L"������";
				 // 
				 // userFirstName
				 // 
				 this->userFirstName->AutoSize = true;
				 this->userFirstName->Location = System::Drawing::Point(17, 31);
				 this->userFirstName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->userFirstName->Name = L"userFirstName";
				 this->userFirstName->Size = System::Drawing::Size(64, 17);
				 this->userFirstName->TabIndex = 44;
				 this->userFirstName->Text = L"�������";
				 // 
				 // userLogin
				 // 
				 this->userLogin->AutoSize = true;
				 this->userLogin->Location = System::Drawing::Point(232, 420);
				 this->userLogin->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->userLogin->Name = L"userLogin";
				 this->userLogin->Size = System::Drawing::Size(92, 17);
				 this->userLogin->TabIndex = 43;
				 this->userLogin->Text = L"nagibator228";
				 // 
				 // label19
				 // 
				 this->label19->AutoSize = true;
				 this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(204)));
				 this->label19->Location = System::Drawing::Point(17, 246);
				 this->label19->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label19->Name = L"label19";
				 this->label19->Size = System::Drawing::Size(219, 17);
				 this->label19->TabIndex = 42;
				 this->label19->Text = L"�������� ������ ��������:";
				 // 
				 // userDrinksChangeField
				 // 
				 this->userDrinksChangeField->Location = System::Drawing::Point(448, 373);
				 this->userDrinksChangeField->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->userDrinksChangeField->Multiline = true;
				 this->userDrinksChangeField->Name = L"userDrinksChangeField";
				 this->userDrinksChangeField->Size = System::Drawing::Size(239, 125);
				 this->userDrinksChangeField->TabIndex = 38;
				 // 
				 // userHobbyChangeField
				 // 
				 this->userHobbyChangeField->Location = System::Drawing::Point(448, 209);
				 this->userHobbyChangeField->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->userHobbyChangeField->Multiline = true;
				 this->userHobbyChangeField->Name = L"userHobbyChangeField";
				 this->userHobbyChangeField->Size = System::Drawing::Size(239, 123);
				 this->userHobbyChangeField->TabIndex = 37;
				 // 
				 // userDescriptionChangeField
				 // 
				 this->userDescriptionChangeField->Location = System::Drawing::Point(448, 41);
				 this->userDescriptionChangeField->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->userDescriptionChangeField->Multiline = true;
				 this->userDescriptionChangeField->Name = L"userDescriptionChangeField";
				 this->userDescriptionChangeField->Size = System::Drawing::Size(239, 125);
				 this->userDescriptionChangeField->TabIndex = 36;
				 // 
				 // label18
				 // 
				 this->label18->AutoSize = true;
				 this->label18->Location = System::Drawing::Point(444, 351);
				 this->label18->Name = L"label18";
				 this->label18->Size = System::Drawing::Size(133, 17);
				 this->label18->TabIndex = 35;
				 this->label18->Text = L"������� �������:";
				 // 
				 // label17
				 // 
				 this->label17->AutoSize = true;
				 this->label17->Location = System::Drawing::Point(444, 190);
				 this->label17->Name = L"label17";
				 this->label17->Size = System::Drawing::Size(164, 17);
				 this->label17->TabIndex = 34;
				 this->label17->Text = L"�������� � ���������:";
				 // 
				 // label16
				 // 
				 this->label16->AutoSize = true;
				 this->label16->Location = System::Drawing::Point(444, 18);
				 this->label16->Name = L"label16";
				 this->label16->Size = System::Drawing::Size(58, 17);
				 this->label16->TabIndex = 33;
				 this->label16->Text = L"� ����:";
				 // 
				 // userMail
				 // 
				 this->userMail->AutoSize = true;
				 this->userMail->Location = System::Drawing::Point(20, 418);
				 this->userMail->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->userMail->Name = L"userMail";
				 this->userMail->Size = System::Drawing::Size(155, 17);
				 this->userMail->TabIndex = 32;
				 this->userMail->Text = L"exmple@sobutilnik.com";
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(20, 443);
				 this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(96, 17);
				 this->label6->TabIndex = 31;
				 this->label6->Text = L"����� �����:";
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(20, 402);
				 this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(113, 17);
				 this->label7->TabIndex = 30;
				 this->label7->Text = L"������� �����:";
				 // 
				 // newEmail
				 // 
				 this->newEmail->Location = System::Drawing::Point(24, 463);
				 this->newEmail->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->newEmail->Name = L"newEmail";
				 this->newEmail->Size = System::Drawing::Size(132, 22);
				 this->newEmail->TabIndex = 28;
				 // 
				 // saveChanges
				 // 
				 this->saveChanges->Location = System::Drawing::Point(508, 508);
				 this->saveChanges->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->saveChanges->Name = L"saveChanges";
				 this->saveChanges->Size = System::Drawing::Size(180, 28);
				 this->saveChanges->TabIndex = 27;
				 this->saveChanges->Text = L"��������� ���������";
				 this->saveChanges->UseVisualStyleBackColor = true;
				 this->saveChanges->Click += gcnew System::EventHandler(this, &Map::saveChanges_Click);
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(232, 276);
				 this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(117, 17);
				 this->label4->TabIndex = 26;
				 this->label4->Text = L"����� �������:";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(232, 324);
				 this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(82, 17);
				 this->label5->TabIndex = 25;
				 this->label5->Text = L"����� ���:";
				 // 
				 // newNameField
				 // 
				 this->newNameField->Location = System::Drawing::Point(236, 343);
				 this->newNameField->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->newNameField->Name = L"newNameField";
				 this->newNameField->Size = System::Drawing::Size(132, 22);
				 this->newNameField->TabIndex = 24;
				 // 
				 // newSurnameField
				 // 
				 this->newSurnameField->Location = System::Drawing::Point(236, 295);
				 this->newSurnameField->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->newSurnameField->Name = L"newSurnameField";
				 this->newSurnameField->Size = System::Drawing::Size(132, 22);
				 this->newSurnameField->TabIndex = 23;
				 // 
				 // GeoPosition
				 // 
				 this->GeoPosition->AutoSize = true;
				 this->GeoPosition->Checked = true;
				 this->GeoPosition->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->GeoPosition->Location = System::Drawing::Point(21, 174);
				 this->GeoPosition->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->GeoPosition->Name = L"GeoPosition";
				 this->GeoPosition->Size = System::Drawing::Size(134, 55);
				 this->GeoPosition->TabIndex = 21;
				 this->GeoPosition->Text = L"�������� ��\r\n������������� \r\n����������";
				 this->GeoPosition->UseVisualStyleBackColor = true;
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(17, 276);
				 this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(121, 17);
				 this->label3->TabIndex = 20;
				 this->label3->Text = L"������� ������:";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(17, 324);
				 this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(106, 17);
				 this->label2->TabIndex = 19;
				 this->label2->Text = L"����� ������:";
				 // 
				 // newPasswordField
				 // 
				 this->newPasswordField->Location = System::Drawing::Point(21, 343);
				 this->newPasswordField->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->newPasswordField->Name = L"newPasswordField";
				 this->newPasswordField->Size = System::Drawing::Size(132, 22);
				 this->newPasswordField->TabIndex = 18;
				 // 
				 // currentPasswordField
				 // 
				 this->currentPasswordField->Location = System::Drawing::Point(21, 295);
				 this->currentPasswordField->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->currentPasswordField->Name = L"currentPasswordField";
				 this->currentPasswordField->Size = System::Drawing::Size(132, 22);
				 this->currentPasswordField->TabIndex = 17;
				 // 
				 // ChangeProfileImage
				 // 
				 this->ChangeProfileImage->Location = System::Drawing::Point(183, 187);
				 this->ChangeProfileImage->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->ChangeProfileImage->Name = L"ChangeProfileImage";
				 this->ChangeProfileImage->Size = System::Drawing::Size(187, 28);
				 this->ChangeProfileImage->TabIndex = 15;
				 this->ChangeProfileImage->Text = L"��������";
				 this->ChangeProfileImage->UseVisualStyleBackColor = true;
				 this->ChangeProfileImage->Click += gcnew System::EventHandler(this, &Map::ChangeProfileImage_Click);
				 // 
				 // ProfileImage
				 // 
				 this->ProfileImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ProfileImage.Image")));
				 this->ProfileImage->Location = System::Drawing::Point(183, 10);
				 this->ProfileImage->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->ProfileImage->Name = L"ProfileImage";
				 this->ProfileImage->Size = System::Drawing::Size(187, 169);
				 this->ProfileImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->ProfileImage->TabIndex = 14;
				 this->ProfileImage->TabStop = false;
				 // 
				 // ExitAccount
				 // 
<<<<<<< HEAD
				 this->ExitAccount->Location = System::Drawing::Point(49, 508);
				 this->ExitAccount->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->ExitAccount->Name = L"ExitAccount";
				 this->ExitAccount->Size = System::Drawing::Size(100, 28);
=======
				 this->ExitAccount->Location = System::Drawing::Point(11, 439);
				 this->ExitAccount->Name = L"ExitAccount";
				 this->ExitAccount->Size = System::Drawing::Size(75, 23);
>>>>>>> bf0cd9815c8bfd3eb76ad684f64b60523b817333
				 this->ExitAccount->TabIndex = 14;
				 this->ExitAccount->Text = L"�����";
				 this->ExitAccount->UseVisualStyleBackColor = true;
				 this->ExitAccount->Click += gcnew System::EventHandler(this, &Map::ExitAccount_Click);
				 // 
				 // Settings
				 // 
				 this->Settings->Location = System::Drawing::Point(15, 196);
				 this->Settings->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->Settings->Name = L"Settings";
				 this->Settings->Size = System::Drawing::Size(167, 31);
				 this->Settings->TabIndex = 5;
				 this->Settings->Text = L"���������";
				 this->Settings->UseVisualStyleBackColor = true;
				 this->Settings->Click += gcnew System::EventHandler(this, &Map::Settings_Click);
				 // 
				 // Friends
				 // 
				 this->Friends->Location = System::Drawing::Point(15, 48);
				 this->Friends->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->Friends->Name = L"Friends";
				 this->Friends->Size = System::Drawing::Size(167, 31);
				 this->Friends->TabIndex = 7;
				 this->Friends->Text = L"������";
				 this->Friends->UseVisualStyleBackColor = true;
				 this->Friends->Click += gcnew System::EventHandler(this, &Map::Friends_Click);
				 // 
				 // History
				 // 
				 this->History->Location = System::Drawing::Point(15, 159);
				 this->History->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->History->Name = L"History";
				 this->History->Size = System::Drawing::Size(167, 31);
				 this->History->TabIndex = 8;
				 this->History->Text = L"�������";
				 this->History->UseVisualStyleBackColor = true;
				 this->History->Click += gcnew System::EventHandler(this, &Map::History_Click);
				 // 
				 // Messages
				 // 
				 this->Messages->Location = System::Drawing::Point(15, 85);
				 this->Messages->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->Messages->Name = L"Messages";
				 this->Messages->Size = System::Drawing::Size(167, 31);
				 this->Messages->TabIndex = 9;
				 this->Messages->Text = L"���������";
				 this->Messages->UseVisualStyleBackColor = true;
				 this->Messages->Click += gcnew System::EventHandler(this, &Map::Messages_Click);
				 // 
				 // Buttons
				 // 
				 this->Buttons->Controls->Add(this->mapButton);
				 this->Buttons->Controls->Add(this->ExitAccount);
				 this->Buttons->Controls->Add(this->profileButton);
				 this->Buttons->Controls->Add(this->Friends);
				 this->Buttons->Controls->Add(this->Messages);
				 this->Buttons->Controls->Add(this->Settings);
				 this->Buttons->Controls->Add(this->History);
				 this->Buttons->Location = System::Drawing::Point(13, 7);
				 this->Buttons->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->Buttons->Name = L"Buttons";
				 this->Buttons->Size = System::Drawing::Size(192, 652);
				 this->Buttons->TabIndex = 10;
				 // 
				 // mapButton
				 // 
				 this->mapButton->Location = System::Drawing::Point(15, 122);
				 this->mapButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->mapButton->Name = L"mapButton";
				 this->mapButton->Size = System::Drawing::Size(167, 31);
				 this->mapButton->TabIndex = 13;
				 this->mapButton->Text = L"�����";
				 this->mapButton->UseVisualStyleBackColor = true;
				 // 
				 // profileButton
				 // 
				 this->profileButton->Location = System::Drawing::Point(15, 11);
				 this->profileButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->profileButton->Name = L"profileButton";
				 this->profileButton->Size = System::Drawing::Size(167, 31);
				 this->profileButton->TabIndex = 12;
				 this->profileButton->Text = L"��� �������";
				 this->profileButton->UseVisualStyleBackColor = true;
				 this->profileButton->Click += gcnew System::EventHandler(this, &Map::profileButton_Click);
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 // 
				 // Map
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1912, 1029);
				 this->Controls->Add(this->profilePanel);
				 this->Controls->Add(this->Buttons);
				 this->Controls->Add(this->HistoryPanel);
				 this->Controls->Add(this->FriendsPanel);
				 this->Controls->Add(this->MessagesPanel);
				 this->Controls->Add(this->SettingsPanel);
				 this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->Name = L"Map";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
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
				 this->SettingsPanel->ResumeLayout(false);
				 this->SettingsPanel->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProfileImage))->EndInit();
				 this->Buttons->ResumeLayout(false);
				 this->ResumeLayout(false);

			 }
#pragma endregion
	private: System::Void Map_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		if(!isExitButton)
			mainPage->Close();
	}
	private: System::Void Settings_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Messages_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void History_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Friends_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ChangeProfileImage_Click(System::Object^  sender, System::EventArgs^  e);

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
private: System::Void Map_Load(System::Object^  sender, System::EventArgs^  e) {
	profilePanel->Location = System::Drawing::Point(215, 15);
	Map::Size = System::Drawing::Size(800, 530);
}
private: System::Void DeleteAcc_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ExitAccount_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void resultListBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
};
}
