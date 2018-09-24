#pragma once
#include <msclr/marshal.h>
#include "ErrorMessages.h"
#include "Map.h"

namespace Sobutilnik {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	

	public ref class RegistrationForm : public System::Windows::Forms::Form
	{
	public:
		RegistrationForm(FirstPage ^f) : mainPage(f)
		{
			InitializeComponent();
		}

	protected:
		~RegistrationForm()
		{
			if (components)
			{
				delete components;
			}
			delete mainPage;
		}
	private:
		FirstPage ^mainPage;
		void fieldCheck();
		void uniqUser(System::Object ^, const char*, System::Object ^);
	private: System::Windows::Forms::TextBox^  nameTextBox;
	private: System::Windows::Forms::TextBox^  surnameTextBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  emailTextBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  passwordTextBox;
	private: System::Windows::Forms::TextBox^  passwordCheckTextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  loginTextBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::RadioButton^  SexMale;
	private: System::Windows::Forms::RadioButton^  SexFem;
	private: System::Windows::Forms::MonthCalendar^  monthCalendar1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  ProfilePicture;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PictureBox^  SetProfilePicture;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::CheckBox^  locationCheckBox;
	private:
		System::ComponentModel::Container ^components;



#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RegistrationForm::typeid));
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->surnameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordCheckTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->loginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SexMale = (gcnew System::Windows::Forms::RadioButton());
			this->SexFem = (gcnew System::Windows::Forms::RadioButton());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->ProfilePicture = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SetProfilePicture = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->locationCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ProfilePicture->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SetProfilePicture))->BeginInit();
			this->SuspendLayout();
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(41, 59);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(129, 20);
			this->nameTextBox->TabIndex = 0;
			// 
			// surnameTextBox
			// 
			this->surnameTextBox->Location = System::Drawing::Point(41, 98);
			this->surnameTextBox->Name = L"surnameTextBox";
			this->surnameTextBox->Size = System::Drawing::Size(129, 20);
			this->surnameTextBox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(38, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Введите имя:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(38, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Введите фамилию";
			// 
			// emailTextBox
			// 
			this->emailTextBox->Location = System::Drawing::Point(41, 137);
			this->emailTextBox->Name = L"emailTextBox";
			this->emailTextBox->Size = System::Drawing::Size(129, 20);
			this->emailTextBox->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(38, 121);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"eMail:";
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Location = System::Drawing::Point(41, 215);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->Size = System::Drawing::Size(129, 20);
			this->passwordTextBox->TabIndex = 4;
			// 
			// passwordCheckTextBox
			// 
			this->passwordCheckTextBox->Location = System::Drawing::Point(41, 254);
			this->passwordCheckTextBox->Name = L"passwordCheckTextBox";
			this->passwordCheckTextBox->Size = System::Drawing::Size(129, 20);
			this->passwordCheckTextBox->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(38, 199);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(111, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Придумайте пароль:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(38, 238);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Повторите пароль:";
			// 
			// loginTextBox
			// 
			this->loginTextBox->Location = System::Drawing::Point(41, 176);
			this->loginTextBox->Name = L"loginTextBox";
			this->loginTextBox->Size = System::Drawing::Size(129, 20);
			this->loginTextBox->TabIndex = 3;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(38, 160);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(104, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Придумайте логин:";
			// 
			// SexMale
			// 
			this->SexMale->AutoSize = true;
			this->SexMale->Location = System::Drawing::Point(110, 295);
			this->SexMale->Name = L"SexMale";
			this->SexMale->Size = System::Drawing::Size(34, 17);
			this->SexMale->TabIndex = 7;
			this->SexMale->TabStop = true;
			this->SexMale->Text = L"М";
			this->SexMale->UseVisualStyleBackColor = true;
			// 
			// SexFem
			// 
			this->SexFem->AutoSize = true;
			this->SexFem->Location = System::Drawing::Point(46, 295);
			this->SexFem->Name = L"SexFem";
			this->SexFem->Size = System::Drawing::Size(36, 17);
			this->SexFem->TabIndex = 6;
			this->SexFem->TabStop = true;
			this->SexFem->Text = L"Ж";
			this->SexFem->UseVisualStyleBackColor = true;
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Location = System::Drawing::Point(215, 59);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 8;
			this->monthCalendar1->MaxDate = this->monthCalendar1->TodayDate;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(245, 280);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 32);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Регестрация";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RegistrationForm::button1_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(43, 280);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(30, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Пол:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(212, 43);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(89, 13);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Дата рождения:";
			// 
			// ProfilePicture
			// 
			this->ProfilePicture->Controls->Add(this->label9);
			this->ProfilePicture->Controls->Add(this->button3);
			this->ProfilePicture->Controls->Add(this->button2);
			this->ProfilePicture->Controls->Add(this->SetProfilePicture);
			this->ProfilePicture->Location = System::Drawing::Point(404, 150);
			this->ProfilePicture->Name = L"ProfilePicture";
			this->ProfilePicture->Size = System::Drawing::Size(417, 335);
			this->ProfilePicture->TabIndex = 19;
			this->ProfilePicture->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(141, 34);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(145, 13);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Установите фото профиля:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(169, 280);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(91, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Продолжить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &RegistrationForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(178, 218);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Обзор...";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &RegistrationForm::button2_Click);
			// 
			// SetProfilePicture
			// 
			this->SetProfilePicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SetProfilePicture.Image")));
			this->SetProfilePicture->Location = System::Drawing::Point(121, 50);
			this->SetProfilePicture->Name = L"SetProfilePicture";
			this->SetProfilePicture->Size = System::Drawing::Size(179, 162);
			this->SetProfilePicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->SetProfilePicture->TabIndex = 0;
			this->SetProfilePicture->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// locationCheckBox
			// 
			this->locationCheckBox->AutoSize = true;
			this->locationCheckBox->Checked = true;
			this->locationCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->locationCheckBox->Location = System::Drawing::Point(215, 233);
			this->locationCheckBox->Name = L"locationCheckBox";
			this->locationCheckBox->Size = System::Drawing::Size(188, 17);
			this->locationCheckBox->TabIndex = 20;
			this->locationCheckBox->Text = L"Использовать мою геолокацию";
			this->locationCheckBox->UseVisualStyleBackColor = true;
			// 
			// RegistrationForm
			// 
			this->AutoScrollMargin = System::Drawing::Size(100, 100);
			this->ClientSize = System::Drawing::Size(466, 400);
			this->Controls->Add(this->locationCheckBox);
			this->Controls->Add(this->ProfilePicture);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->monthCalendar1);
			this->Controls->Add(this->SexFem);
			this->Controls->Add(this->SexMale);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->loginTextBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->passwordCheckTextBox);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->emailTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->surnameTextBox);
			this->Controls->Add(this->nameTextBox);
			this->Name = L"RegistrationForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L" Регистрация";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &RegistrationForm::RegistrationForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &RegistrationForm::RegistrationForm_Load);
			this->ProfilePicture->ResumeLayout(false);
			this->ProfilePicture->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SetProfilePicture))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			fieldCheck();
		}
		catch (const std::exception & e)
		{
			MessageBox::Show(marshal_as<String^>(e.what()));
			return;
		}
		locationCheckBox->Visible = false;
		this->ProfilePicture->Location = System::Drawing::Point(0, 0);
		ProfilePicture->Visible = true;
	}
private: System::Void RegistrationForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	mainPage->Enabled = true;
}
private: System::Void RegistrationForm_Load(System::Object^  sender, System::EventArgs^  e) {
	this->ClientSize = System::Drawing::Size(414, 334);
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	mainPage->Visible = false;
	Map ^NewForm = gcnew Map(mainPage);
	this->Close();
	NewForm->ShowDialog();
	mainPage->dbConnection->Open();
	OleDbCommand ^command = gcnew OleDbCommand();
	command->CommandType = CommandType::Text;
	command->CommandText = "INSERT INTO MyDatabase (w_name,w_surname,w_password,w_login,w_email,w_sex,w_birthday,w_geolocation) \
		VALUES (@u_name,@u_surname,@u_password,@u_login,@u_email, @u_sex,@u_birthday,@u_geolocation)";
	command->Connection = mainPage->dbConnection;
	command->Parameters->AddWithValue("@u_name", nameTextBox->Text);
	command->Parameters->AddWithValue("@u_surname", surnameTextBox->Text);
	command->Parameters->AddWithValue("@u_password", passwordTextBox->Text);
	command->Parameters->AddWithValue("@u_login", loginTextBox->Text);
	command->Parameters->AddWithValue("@u_email", emailTextBox->Text);
	
	if(SexFem->Checked)
		command->Parameters->AddWithValue("@u_sex", "F");
	else
		command->Parameters->AddWithValue("@u_sex", "M");

	command->Parameters->AddWithValue("@u_birthday",monthCalendar1->SelectionRange->Start.ToShortDateString());
	command->Parameters->AddWithValue("@u_geolocation", locationCheckBox->Checked);
	command->ExecuteNonQuery();
	mainPage->dbConnection->Close();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	
	String ^imageProfile;
	openFileDialog1->InitialDirectory = "c:\\";
	openFileDialog1->Filter = "Image Files(*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF";
	openFileDialog1->RestoreDirectory = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && openFileDialog1->FileName != nullptr) {
		imageProfile = openFileDialog1->FileName;
		SetProfilePicture->Load(imageProfile);
		SetProfilePicture->Load(imageProfile);
		//Внесение в бд картинки
	}
}
};
}
