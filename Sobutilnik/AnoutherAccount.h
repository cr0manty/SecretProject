#pragma once
#include "Map.h"
namespace Sobutilnik {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AnoutherAccount
	/// </summary>
	public ref class AnoutherAccount : public System::Windows::Forms::Form
	{
	public:
		AnoutherAccount(int friendID,int _myID, OleDbConnection^ db, bool _isFriend) :
			friendID(friendID), dbConnection(db), isFriend(_isFriend), myId(_myID)
		{
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AnoutherAccount()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		int friendID, myId;
		bool isFriend;
		OleDbConnection^ dbConnection;
		OleDbDataReader ^reader;
		OleDbCommand ^command;

	private: System::Windows::Forms::Label^  UserBirth;
	private: System::Windows::Forms::Label^  userSex;
	private: System::Windows::Forms::Label^  userAgeStatic;
	private: System::Windows::Forms::Label^  userSurname;
	private: System::Windows::Forms::Label^  userFirstName;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  usersAlcoholLabel;
	private: System::Windows::Forms::Label^  Drinks;
	private: System::Windows::Forms::Label^  userHobbiesLabel;
	private: System::Windows::Forms::Label^  Hobbies;
	private: System::Windows::Forms::Label^  userDescriptionLabel;
	private: System::Windows::Forms::Label^  aboutYourself;
	private: System::Windows::Forms::Button^  AddDeleteFriend;



	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ProgressBar^  Rating;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  RatingPersent;


	private: System::Windows::Forms::Label^  userLogin;
	private: System::Windows::Forms::Label^  label5;
			 /// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AnoutherAccount::typeid));
			this->UserBirth = (gcnew System::Windows::Forms::Label());
			this->userSex = (gcnew System::Windows::Forms::Label());
			this->userAgeStatic = (gcnew System::Windows::Forms::Label());
			this->userSurname = (gcnew System::Windows::Forms::Label());
			this->userFirstName = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->usersAlcoholLabel = (gcnew System::Windows::Forms::Label());
			this->Drinks = (gcnew System::Windows::Forms::Label());
			this->userHobbiesLabel = (gcnew System::Windows::Forms::Label());
			this->Hobbies = (gcnew System::Windows::Forms::Label());
			this->userDescriptionLabel = (gcnew System::Windows::Forms::Label());
			this->aboutYourself = (gcnew System::Windows::Forms::Label());
			this->AddDeleteFriend = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->Rating = (gcnew System::Windows::Forms::ProgressBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->RatingPersent = (gcnew System::Windows::Forms::Label());
			this->userLogin = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// UserBirth
			// 
			this->UserBirth->AutoSize = true;
			this->UserBirth->Location = System::Drawing::Point(198, 104);
			this->UserBirth->Name = L"UserBirth";
			this->UserBirth->Size = System::Drawing::Size(65, 13);
			this->UserBirth->TabIndex = 56;
			this->UserBirth->Text = L"02/03/2018";
			// 
			// userSex
			// 
			this->userSex->AutoSize = true;
			this->userSex->Location = System::Drawing::Point(198, 125);
			this->userSex->Name = L"userSex";
			this->userSex->Size = System::Drawing::Size(42, 13);
			this->userSex->TabIndex = 55;
			this->userSex->Text = L"Пол: М";
			// 
			// userAgeStatic
			// 
			this->userAgeStatic->AutoSize = true;
			this->userAgeStatic->Location = System::Drawing::Point(198, 85);
			this->userAgeStatic->Name = L"userAgeStatic";
			this->userAgeStatic->Size = System::Drawing::Size(89, 13);
			this->userAgeStatic->TabIndex = 54;
			this->userAgeStatic->Text = L"Дата рождения:\r\n";
			// 
			// userSurname
			// 
			this->userSurname->AutoSize = true;
			this->userSurname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->userSurname->Location = System::Drawing::Point(11, 28);
			this->userSurname->Name = L"userSurname";
			this->userSurname->Size = System::Drawing::Size(69, 20);
			this->userSurname->TabIndex = 53;
			this->userSurname->Text = L"Пупкин";
			// 
			// userFirstName
			// 
			this->userFirstName->AutoSize = true;
			this->userFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->userFirstName->Location = System::Drawing::Point(12, 7);
			this->userFirstName->Name = L"userFirstName";
			this->userFirstName->Size = System::Drawing::Size(81, 20);
			this->userFirstName->TabIndex = 52;
			this->userFirstName->Text = L"Василий";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 53);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(180, 174);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 59;
			this->pictureBox1->TabStop = false;
			// 
			// usersAlcoholLabel
			// 
			this->usersAlcoholLabel->AutoEllipsis = true;
			this->usersAlcoholLabel->Location = System::Drawing::Point(345, 217);
			this->usersAlcoholLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->usersAlcoholLabel->Name = L"usersAlcoholLabel";
			this->usersAlcoholLabel->Size = System::Drawing::Size(202, 75);
			this->usersAlcoholLabel->TabIndex = 65;
			this->usersAlcoholLabel->Text = L"user\'s favourite drinks";
			// 
			// Drinks
			// 
			this->Drinks->AutoSize = true;
			this->Drinks->Location = System::Drawing::Point(345, 204);
			this->Drinks->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Drinks->Name = L"Drinks";
			this->Drinks->Size = System::Drawing::Size(104, 13);
			this->Drinks->TabIndex = 64;
			this->Drinks->Text = L"Любимые напитки:";
			// 
			// userHobbiesLabel
			// 
			this->userHobbiesLabel->AutoEllipsis = true;
			this->userHobbiesLabel->Location = System::Drawing::Point(345, 121);
			this->userHobbiesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->userHobbiesLabel->Name = L"userHobbiesLabel";
			this->userHobbiesLabel->Size = System::Drawing::Size(202, 75);
			this->userHobbiesLabel->TabIndex = 63;
			this->userHobbiesLabel->Text = L"user\'s hobby description";
			// 
			// Hobbies
			// 
			this->Hobbies->AutoSize = true;
			this->Hobbies->Location = System::Drawing::Point(345, 108);
			this->Hobbies->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Hobbies->Name = L"Hobbies";
			this->Hobbies->Size = System::Drawing::Size(125, 13);
			this->Hobbies->TabIndex = 62;
			this->Hobbies->Text = L"Интересы и увлечения:";
			// 
			// userDescriptionLabel
			// 
			this->userDescriptionLabel->AutoEllipsis = true;
			this->userDescriptionLabel->Location = System::Drawing::Point(345, 25);
			this->userDescriptionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->userDescriptionLabel->Name = L"userDescriptionLabel";
			this->userDescriptionLabel->Size = System::Drawing::Size(202, 75);
			this->userDescriptionLabel->TabIndex = 61;
			this->userDescriptionLabel->Text = L"Some words about user";
			// 
			// aboutYourself
			// 
			this->aboutYourself->AutoSize = true;
			this->aboutYourself->Location = System::Drawing::Point(345, 12);
			this->aboutYourself->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->aboutYourself->Name = L"aboutYourself";
			this->aboutYourself->Size = System::Drawing::Size(45, 13);
			this->aboutYourself->TabIndex = 60;
			this->aboutYourself->Text = L"О себе:";
			// 
			// AddDeleteFriend
			// 
			this->AddDeleteFriend->Location = System::Drawing::Point(33, 269);
			this->AddDeleteFriend->Name = L"AddDeleteFriend";
			this->AddDeleteFriend->Size = System::Drawing::Size(126, 23);
			this->AddDeleteFriend->TabIndex = 66;
			this->AddDeleteFriend->Text = L"Добавить в друзья";
			this->AddDeleteFriend->UseVisualStyleBackColor = true;
			this->AddDeleteFriend->Click += gcnew System::EventHandler(this, &AnoutherAccount::AddDeleteFriend_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(497, 298);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 68;
			this->button2->Text = L"Закрыть";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AnoutherAccount::button2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(33, 233);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(126, 23);
			this->button3->TabIndex = 69;
			this->button3->Text = L"Начать диалог";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// Rating
			// 
			this->Rating->Location = System::Drawing::Point(201, 181);
			this->Rating->Name = L"Rating";
			this->Rating->Size = System::Drawing::Size(100, 23);
			this->Rating->TabIndex = 70;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(198, 165);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 71;
			this->label2->Text = L"Рейтинг:";
			// 
			// RatingPersent
			// 
			this->RatingPersent->AutoSize = true;
			this->RatingPersent->Location = System::Drawing::Point(280, 165);
			this->RatingPersent->Name = L"RatingPersent";
			this->RatingPersent->Size = System::Drawing::Size(21, 13);
			this->RatingPersent->TabIndex = 72;
			this->RatingPersent->Text = L"0%";
			this->RatingPersent->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// userLogin
			// 
			this->userLogin->AutoSize = true;
			this->userLogin->Location = System::Drawing::Point(198, 66);
			this->userLogin->Name = L"userLogin";
			this->userLogin->Size = System::Drawing::Size(69, 13);
			this->userLogin->TabIndex = 73;
			this->userLogin->Text = L"nagibator228";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(198, 53);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 13);
			this->label5->TabIndex = 74;
			this->label5->Text = L"Логин:";
			// 
			// AnoutherAccount
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(584, 333);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->userLogin);
			this->Controls->Add(this->RatingPersent);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Rating);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->AddDeleteFriend);
			this->Controls->Add(this->usersAlcoholLabel);
			this->Controls->Add(this->Drinks);
			this->Controls->Add(this->userHobbiesLabel);
			this->Controls->Add(this->Hobbies);
			this->Controls->Add(this->userDescriptionLabel);
			this->Controls->Add(this->aboutYourself);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->UserBirth);
			this->Controls->Add(this->userSex);
			this->Controls->Add(this->userAgeStatic);
			this->Controls->Add(this->userSurname);
			this->Controls->Add(this->userFirstName);
			this->Name = L"AnoutherAccount";
			this->Text = L"AnoutherAccount";
			this->Load += gcnew System::EventHandler(this, &AnoutherAccount::AnoutherAccount_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AnoutherAccount_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void AddDeleteFriend_Click(System::Object^  sender, System::EventArgs^  e);
};
}
