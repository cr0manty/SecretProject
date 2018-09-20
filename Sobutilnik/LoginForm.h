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
		LoginForm(FirstPage ^f) : mainPage(f)
		{
			InitializeComponent();
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
		FirstPage ^mainPage;
		void findAccount();
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;

#pragma region Windows Form Designer generated code
		
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(109, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Вход";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(83, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Логин:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(83, 122);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Пароль:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(93, 164);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Войти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(187, 138);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(25, 20);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseEnter += gcnew System::EventHandler(this, &LoginForm::pictureBox1_MouseEnter);
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &LoginForm::pictureBox1_MouseLeave);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(86, 99);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(86, 138);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"LoginForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LoginForm::LoginForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void pictureBox1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	textBox2->UseSystemPasswordChar = false;
}
private: System::Void pictureBox1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	textBox2->UseSystemPasswordChar = true;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	try
	{
		findAccount();
	}
	catch (const std::exception & e)
	{
		MessageBox::Show(marshal_as<String^>(e.what()));
		return;
	}
	mainPage->Visible = false;
	Map ^NewForm = gcnew Map(mainPage);
	this->Close();
	NewForm->ShowDialog();
}
private: System::Void LoginForm_Load(System::Object^  sender, System::EventArgs^  e) {
	mainPage->Enabled = false;
}
private: System::Void LoginForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	mainPage->Enabled = true;
}
};
}
