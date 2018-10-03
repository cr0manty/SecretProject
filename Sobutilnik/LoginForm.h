#pragma once
#include "RegistrationForm.h"

namespace Sobutilnik {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(FirstPage ^ f) : mainPage(f)
		{
			InitializeComponent();
			dbConnection = gcnew OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0;Data Source = MyDatabase.mdb");
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		OleDbConnection^ dbConnection;
		FirstPage ^mainPage;
		int findAccount();
		Map ^NewForm;
		OleDbCommand ^command;
		OleDbDataReader ^reader;
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  Entry;
	private: System::Windows::Forms::PictureBox^  PassOnOff;
	private: System::Windows::Forms::TextBox^  LoginField;
	private: System::Windows::Forms::TextBox^  PassField;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Entry = (gcnew System::Windows::Forms::Button());
			this->PassOnOff = (gcnew System::Windows::Forms::PictureBox());
			this->LoginField = (gcnew System::Windows::Forms::TextBox());
			this->PassField = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PassOnOff))->BeginInit();
			this->SuspendLayout();
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 14.25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(109, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Вход";
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(83, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Логин:";
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(83, 122);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Пароль:";
			this->Entry->Location = System::Drawing::Point(95, 172);
			this->Entry->Name = L"Entry";
			this->Entry->Size = System::Drawing::Size(84, 23);
			this->Entry->TabIndex = 3;
			this->Entry->Text = L"Войти";
			this->Entry->UseVisualStyleBackColor = true;
			this->Entry->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click);
			this->PassOnOff->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PassOnOff.Image")));
			this->PassOnOff->Location = System::Drawing::Point(187, 138);
			this->PassOnOff->Name = L"PassOnOff";
			this->PassOnOff->Size = System::Drawing::Size(25, 20);
			this->PassOnOff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PassOnOff->TabIndex = 4;
			this->PassOnOff->TabStop = false;
			this->PassOnOff->MouseEnter += gcnew System::EventHandler(this, &LoginForm::pictureBox1_MouseEnter);
			this->PassOnOff->MouseLeave += gcnew System::EventHandler(this, &LoginForm::pictureBox1_MouseLeave);
			this->LoginField->Location = System::Drawing::Point(86, 99);
			this->LoginField->Name = L"LoginField";
			this->LoginField->Size = System::Drawing::Size(100, 20);
			this->LoginField->TabIndex = 1;
			this->LoginField->Text = L"admin";
			this->PassField->Location = System::Drawing::Point(86, 138);
			this->PassField->Name = L"PassField";
			this->PassField->Size = System::Drawing::Size(100, 20);
			this->PassField->TabIndex = 2;
			this->PassField->Text = L"admin";
			this->PassField->UseSystemPasswordChar = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->PassField);
			this->Controls->Add(this->LoginField);
			this->Controls->Add(this->PassOnOff);
			this->Controls->Add(this->Entry);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"LoginForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LoginForm::LoginForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PassOnOff))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void pictureBox1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	PassField->UseSystemPasswordChar = false;
}
private: System::Void pictureBox1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PassField->UseSystemPasswordChar = true;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void LoginForm_Load(System::Object^  sender, System::EventArgs^  e) {
	mainPage->Enabled = false;
}
private: System::Void LoginForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	mainPage->Enabled = true;
	this->Close();
}
};
}
