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
			 String^ profileImage;
		void checkSearch();
	private: GMap::NET::WindowsForms::GMapControl^  gMapControl1;
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
	private: System::Windows::Forms::Button^  FriendsCloseButton;
	private: System::Windows::Forms::Button^  HistoryCloseButton;
	private: System::Windows::Forms::Button^  MessagesCloseButton;
	private: System::Windows::Forms::Button^  SettingsCloseButton;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::CheckBox^  GeoPosition;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
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
				 this->gMapControl1 = (gcnew GMap::NET::WindowsForms::GMapControl());
				 this->PictureProfile = (gcnew System::Windows::Forms::PictureBox());
				 this->Drunk = (gcnew System::Windows::Forms::Button());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->Rating = (gcnew System::Windows::Forms::ProgressBar());
				 this->FriendsPanel = (gcnew System::Windows::Forms::Panel());
				 this->label11 = (gcnew System::Windows::Forms::Label());
				 this->resultListBox = (gcnew System::Windows::Forms::ListBox());
				 this->searchButton = (gcnew System::Windows::Forms::Button());
				 this->searchField = (gcnew System::Windows::Forms::TextBox());
				 this->FriendsCloseButton = (gcnew System::Windows::Forms::Button());
				 this->HistoryPanel = (gcnew System::Windows::Forms::Panel());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->HistoryCloseButton = (gcnew System::Windows::Forms::Button());
				 this->MessagesPanel = (gcnew System::Windows::Forms::Panel());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->MessagesCloseButton = (gcnew System::Windows::Forms::Button());
				 this->Settings = (gcnew System::Windows::Forms::Button());
				 this->Friends = (gcnew System::Windows::Forms::Button());
				 this->History = (gcnew System::Windows::Forms::Button());
				 this->Messages = (gcnew System::Windows::Forms::Button());
				 this->Buttons = (gcnew System::Windows::Forms::Panel());
				 this->UserName = (gcnew System::Windows::Forms::Label());
				 this->SettingsPanel = (gcnew System::Windows::Forms::Panel());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->textBox6 = (gcnew System::Windows::Forms::TextBox());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->textBox3 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox4 = (gcnew System::Windows::Forms::TextBox());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->GeoPosition = (gcnew System::Windows::Forms::CheckBox());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->textBox2 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->ChangePass = (gcnew System::Windows::Forms::Button());
				 this->ChangeProfileImage = (gcnew System::Windows::Forms::Button());
				 this->ProfileImage = (gcnew System::Windows::Forms::PictureBox());
				 this->SettingsCloseButton = (gcnew System::Windows::Forms::Button());
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->RatingPersent = (gcnew System::Windows::Forms::Label());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureProfile))->BeginInit();
				 this->FriendsPanel->SuspendLayout();
				 this->HistoryPanel->SuspendLayout();
				 this->MessagesPanel->SuspendLayout();
				 this->Buttons->SuspendLayout();
				 this->SettingsPanel->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProfileImage))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // gMapControl1
				 // 
				 this->gMapControl1->Bearing = 0;
				 this->gMapControl1->CanDragMap = true;
				 this->gMapControl1->GrayScaleMode = false;
				 this->gMapControl1->LevelsKeepInMemmory = 5;
				 this->gMapControl1->Location = System::Drawing::Point(12, 12);
				 this->gMapControl1->MarkersEnabled = true;
				 this->gMapControl1->MaxZoom = 2;
				 this->gMapControl1->MinZoom = 2;
				 this->gMapControl1->MouseWheelZoomType = GMap::NET::MouseWheelZoomType::MousePositionAndCenter;
				 this->gMapControl1->Name = L"gMapControl1";
				 this->gMapControl1->NegativeMode = false;
				 this->gMapControl1->PolygonsEnabled = true;
				 this->gMapControl1->RetryLoadTile = 0;
				 this->gMapControl1->RoutesEnabled = true;
				 this->gMapControl1->ShowTileGridLines = false;
				 this->gMapControl1->Size = System::Drawing::Size(602, 506);
				 this->gMapControl1->TabIndex = 0;
				 this->gMapControl1->Zoom = 0;
				 // 
				 // PictureProfile
				 // 
				 this->PictureProfile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureProfile.Image")));
				 this->PictureProfile->Location = System::Drawing::Point(53, 14);
				 this->PictureProfile->Name = L"PictureProfile";
				 this->PictureProfile->Size = System::Drawing::Size(140, 137);
				 this->PictureProfile->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->PictureProfile->TabIndex = 0;
				 this->PictureProfile->TabStop = false;
				 // 
				 // Drunk
				 // 
				 this->Drunk->Location = System::Drawing::Point(53, 263);
				 this->Drunk->Name = L"Drunk";
				 this->Drunk->Size = System::Drawing::Size(115, 38);
				 this->Drunk->TabIndex = 6;
				 this->Drunk->Text = L"Хочу бухать!";
				 this->Drunk->UseVisualStyleBackColor = true;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(50, 208);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(41, 13);
				 this->label1->TabIndex = 4;
				 this->label1->Text = L"Rating:";
				 // 
				 // Rating
				 // 
				 this->Rating->Location = System::Drawing::Point(53, 224);
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
				 this->FriendsPanel->Controls->Add(this->FriendsCloseButton);
				 this->FriendsPanel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
				 this->FriendsPanel->Location = System::Drawing::Point(30, 260);
				 this->FriendsPanel->Name = L"FriendsPanel";
				 this->FriendsPanel->Size = System::Drawing::Size(391, 539);
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
				 this->resultListBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
				 this->resultListBox->Name = L"resultListBox";
				 this->resultListBox->Size = System::Drawing::Size(243, 238);
				 this->resultListBox->TabIndex = 16;
				 // 
				 // searchButton
				 // 
				 this->searchButton->Location = System::Drawing::Point(305, 89);
				 this->searchButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
				 this->searchButton->Name = L"searchButton";
				 this->searchButton->Size = System::Drawing::Size(56, 19);
				 this->searchButton->TabIndex = 15;
				 this->searchButton->Text = L"Поиск";
				 this->searchButton->UseVisualStyleBackColor = true;
				 this->searchButton->Click += gcnew System::EventHandler(this, &Map::searchButton_Click);
				 // 
				 // searchField
				 // 
				 this->searchField->Location = System::Drawing::Point(28, 89);
				 this->searchField->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
				 this->searchField->Name = L"searchField";
				 this->searchField->Size = System::Drawing::Size(243, 20);
				 this->searchField->TabIndex = 14;
				 // 
				 // FriendsCloseButton
				 // 
				 this->FriendsCloseButton->Location = System::Drawing::Point(18, 19);
				 this->FriendsCloseButton->Name = L"FriendsCloseButton";
				 this->FriendsCloseButton->Size = System::Drawing::Size(75, 23);
				 this->FriendsCloseButton->TabIndex = 13;
				 this->FriendsCloseButton->Text = L"Close";
				 this->FriendsCloseButton->UseVisualStyleBackColor = true;
				 this->FriendsCloseButton->Click += gcnew System::EventHandler(this, &Map::FriendsCloseButton_Click);
				 // 
				 // HistoryPanel
				 // 
				 this->HistoryPanel->Controls->Add(this->label9);
				 this->HistoryPanel->Controls->Add(this->HistoryCloseButton);
				 this->HistoryPanel->Location = System::Drawing::Point(48, 114);
				 this->HistoryPanel->Name = L"HistoryPanel";
				 this->HistoryPanel->Size = System::Drawing::Size(391, 539);
				 this->HistoryPanel->TabIndex = 12;
				 this->HistoryPanel->Visible = false;
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Location = System::Drawing::Point(160, 27);
				 this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(50, 13);
				 this->label9->TabIndex = 14;
				 this->label9->Text = L"История";
				 // 
				 // HistoryCloseButton
				 // 
				 this->HistoryCloseButton->Location = System::Drawing::Point(17, 18);
				 this->HistoryCloseButton->Name = L"HistoryCloseButton";
				 this->HistoryCloseButton->Size = System::Drawing::Size(75, 23);
				 this->HistoryCloseButton->TabIndex = 13;
				 this->HistoryCloseButton->Text = L"Close";
				 this->HistoryCloseButton->UseVisualStyleBackColor = true;
				 this->HistoryCloseButton->Click += gcnew System::EventHandler(this, &Map::HistoryCloseButton_Click);
				 // 
				 // MessagesPanel
				 // 
				 this->MessagesPanel->Controls->Add(this->label10);
				 this->MessagesPanel->Controls->Add(this->MessagesCloseButton);
				 this->MessagesPanel->Location = System::Drawing::Point(75, 3);
				 this->MessagesPanel->Name = L"MessagesPanel";
				 this->MessagesPanel->Size = System::Drawing::Size(391, 539);
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
				 // MessagesCloseButton
				 // 
				 this->MessagesCloseButton->Location = System::Drawing::Point(24, 33);
				 this->MessagesCloseButton->Name = L"MessagesCloseButton";
				 this->MessagesCloseButton->Size = System::Drawing::Size(75, 23);
				 this->MessagesCloseButton->TabIndex = 13;
				 this->MessagesCloseButton->Text = L"Close";
				 this->MessagesCloseButton->UseVisualStyleBackColor = true;
				 this->MessagesCloseButton->Click += gcnew System::EventHandler(this, &Map::MessagesCloseButton_Click);
				 // 
				 // Settings
				 // 
				 this->Settings->Location = System::Drawing::Point(240, 103);
				 this->Settings->Name = L"Settings";
				 this->Settings->Size = System::Drawing::Size(125, 24);
				 this->Settings->TabIndex = 5;
				 this->Settings->Text = L"Настройки";
				 this->Settings->UseVisualStyleBackColor = true;
				 this->Settings->Click += gcnew System::EventHandler(this, &Map::Settings_Click);
				 // 
				 // Friends
				 // 
				 this->Friends->Location = System::Drawing::Point(240, 14);
				 this->Friends->Name = L"Friends";
				 this->Friends->Size = System::Drawing::Size(125, 23);
				 this->Friends->TabIndex = 7;
				 this->Friends->Text = L"Друзья";
				 this->Friends->UseVisualStyleBackColor = true;
				 this->Friends->Click += gcnew System::EventHandler(this, &Map::Friends_Click);
				 // 
				 // History
				 // 
				 this->History->Location = System::Drawing::Point(240, 43);
				 this->History->Name = L"History";
				 this->History->Size = System::Drawing::Size(125, 23);
				 this->History->TabIndex = 8;
				 this->History->Text = L"История";
				 this->History->UseVisualStyleBackColor = true;
				 this->History->Click += gcnew System::EventHandler(this, &Map::History_Click);
				 // 
				 // Messages
				 // 
				 this->Messages->Location = System::Drawing::Point(240, 74);
				 this->Messages->Name = L"Messages";
				 this->Messages->Size = System::Drawing::Size(125, 23);
				 this->Messages->TabIndex = 9;
				 this->Messages->Text = L"Сообщения";
				 this->Messages->UseVisualStyleBackColor = true;
				 this->Messages->Click += gcnew System::EventHandler(this, &Map::Messages_Click);
				 // 
				 // Buttons
				 // 
				 this->Buttons->Controls->Add(this->RatingPersent);
				 this->Buttons->Controls->Add(this->UserName);
				 this->Buttons->Controls->Add(this->Drunk);
				 this->Buttons->Controls->Add(this->PictureProfile);
				 this->Buttons->Controls->Add(this->Friends);
				 this->Buttons->Controls->Add(this->label1);
				 this->Buttons->Controls->Add(this->Rating);
				 this->Buttons->Controls->Add(this->Messages);
				 this->Buttons->Controls->Add(this->Settings);
				 this->Buttons->Controls->Add(this->History);
				 this->Buttons->Location = System::Drawing::Point(640, 12);
				 this->Buttons->Name = L"Buttons";
				 this->Buttons->Size = System::Drawing::Size(382, 530);
				 this->Buttons->TabIndex = 10;
				 // 
				 // UserName
				 // 
				 this->UserName->AutoSize = true;
				 this->UserName->Location = System::Drawing::Point(53, 166);
				 this->UserName->Name = L"UserName";
				 this->UserName->Size = System::Drawing::Size(27, 13);
				 this->UserName->TabIndex = 10;
				 this->UserName->Text = L"Ник";
				 // 
				 // SettingsPanel
				 // 
				 this->SettingsPanel->Controls->Add(this->label8);
				 this->SettingsPanel->Controls->Add(this->label6);
				 this->SettingsPanel->Controls->Add(this->label7);
				 this->SettingsPanel->Controls->Add(this->textBox6);
				 this->SettingsPanel->Controls->Add(this->button2);
				 this->SettingsPanel->Controls->Add(this->label4);
				 this->SettingsPanel->Controls->Add(this->label5);
				 this->SettingsPanel->Controls->Add(this->textBox3);
				 this->SettingsPanel->Controls->Add(this->textBox4);
				 this->SettingsPanel->Controls->Add(this->button1);
				 this->SettingsPanel->Controls->Add(this->GeoPosition);
				 this->SettingsPanel->Controls->Add(this->label3);
				 this->SettingsPanel->Controls->Add(this->label2);
				 this->SettingsPanel->Controls->Add(this->textBox2);
				 this->SettingsPanel->Controls->Add(this->textBox1);
				 this->SettingsPanel->Controls->Add(this->ChangePass);
				 this->SettingsPanel->Controls->Add(this->ChangeProfileImage);
				 this->SettingsPanel->Controls->Add(this->ProfileImage);
				 this->SettingsPanel->Controls->Add(this->SettingsCloseButton);
				 this->SettingsPanel->Location = System::Drawing::Point(492, 9);
				 this->SettingsPanel->Name = L"SettingsPanel";
				 this->SettingsPanel->Size = System::Drawing::Size(382, 530);
				 this->SettingsPanel->TabIndex = 12;
				 this->SettingsPanel->Visible = false;
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
				 this->label6->Text = L"Изменить почту:";
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(252, 70);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(40, 13);
				 this->label7->TabIndex = 30;
				 this->label7->Text = L"Почта:";
				 // 
				 // textBox6
				 // 
				 this->textBox6->Location = System::Drawing::Point(110, 406);
				 this->textBox6->Name = L"textBox6";
				 this->textBox6->Size = System::Drawing::Size(100, 20);
				 this->textBox6->TabIndex = 28;
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(110, 432);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(75, 23);
				 this->button2->TabIndex = 27;
				 this->button2->Text = L"Изменить";
				 this->button2->UseVisualStyleBackColor = true;
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(189, 208);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(91, 13);
				 this->label4->TabIndex = 26;
				 this->label4->Text = L"Новая фамилия:";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(189, 247);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(65, 13);
				 this->label5->TabIndex = 25;
				 this->label5->Text = L"Новое имя:";
				 // 
				 // textBox3
				 // 
				 this->textBox3->Location = System::Drawing::Point(192, 263);
				 this->textBox3->Name = L"textBox3";
				 this->textBox3->Size = System::Drawing::Size(100, 20);
				 this->textBox3->TabIndex = 24;
				 // 
				 // textBox4
				 // 
				 this->textBox4->Location = System::Drawing::Point(192, 224);
				 this->textBox4->Name = L"textBox4";
				 this->textBox4->Size = System::Drawing::Size(100, 20);
				 this->textBox4->TabIndex = 23;
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(192, 289);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(75, 23);
				 this->button1->TabIndex = 22;
				 this->button1->Text = L"Изменить";
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
				 this->GeoPosition->Text = L"Согласен на использования геолокации";
				 this->GeoPosition->UseVisualStyleBackColor = true;
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(26, 208);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(91, 13);
				 this->label3->TabIndex = 20;
				 this->label3->Text = L"Текущий пароль";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(26, 247);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(80, 13);
				 this->label2->TabIndex = 19;
				 this->label2->Text = L"Новый пароль";
				 // 
				 // textBox2
				 // 
				 this->textBox2->Location = System::Drawing::Point(29, 263);
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->Size = System::Drawing::Size(100, 20);
				 this->textBox2->TabIndex = 18;
				 // 
				 // textBox1
				 // 
				 this->textBox1->Location = System::Drawing::Point(29, 224);
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(100, 20);
				 this->textBox1->TabIndex = 17;
				 // 
				 // ChangePass
				 // 
				 this->ChangePass->Location = System::Drawing::Point(29, 289);
				 this->ChangePass->Name = L"ChangePass";
				 this->ChangePass->Size = System::Drawing::Size(75, 23);
				 this->ChangePass->TabIndex = 16;
				 this->ChangePass->Text = L"Изменить";
				 this->ChangePass->UseVisualStyleBackColor = true;
				 // 
				 // ChangeProfileImage
				 // 
				 this->ChangeProfileImage->Location = System::Drawing::Point(106, 157);
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
				 this->ProfileImage->Location = System::Drawing::Point(106, 14);
				 this->ProfileImage->Name = L"ProfileImage";
				 this->ProfileImage->Size = System::Drawing::Size(140, 137);
				 this->ProfileImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->ProfileImage->TabIndex = 14;
				 this->ProfileImage->TabStop = false;
				 // 
				 // SettingsCloseButton
				 // 
				 this->SettingsCloseButton->Location = System::Drawing::Point(18, 14);
				 this->SettingsCloseButton->Name = L"SettingsCloseButton";
				 this->SettingsCloseButton->Size = System::Drawing::Size(75, 23);
				 this->SettingsCloseButton->TabIndex = 13;
				 this->SettingsCloseButton->Text = L"Close";
				 this->SettingsCloseButton->UseVisualStyleBackColor = true;
				 this->SettingsCloseButton->Click += gcnew System::EventHandler(this, &Map::SettingsCloseButton_Click);
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 // 
				 // RatingPersent
				 // 
				 this->RatingPersent->AutoSize = true;
				 this->RatingPersent->Location = System::Drawing::Point(126, 207);
				 this->RatingPersent->Name = L"RatingPersent";
				 this->RatingPersent->Size = System::Drawing::Size(27, 13);
				 this->RatingPersent->TabIndex = 11;
				 this->RatingPersent->Text = L"60%";
				 this->RatingPersent->TextAlign = System::Drawing::ContentAlignment::TopRight;
				 // 
				 // Map
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1022, 547);
				 this->Controls->Add(this->FriendsPanel);
				 this->Controls->Add(this->SettingsPanel);
				 this->Controls->Add(this->HistoryPanel);
				 this->Controls->Add(this->MessagesPanel);
				 this->Controls->Add(this->Buttons);
				 this->Controls->Add(this->gMapControl1);
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
				 this->Buttons->ResumeLayout(false);
				 this->Buttons->PerformLayout();
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
	private: System::Void SettingsCloseButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MessagesCloseButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void HistoryCloseButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void FriendsCloseButton_Click(System::Object^  sender, System::EventArgs^  e);
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
};
}
