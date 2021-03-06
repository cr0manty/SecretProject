#pragma once
#include"GeolocationForm.h"

namespace Sobutilnik {
	ref class FirstPage;
	ref class Map;
	ref class RegistrationForm;
	ref class LoginForm;
	ref class GeolocationForm;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OleDb;
	using namespace System::Device::Location;

	/// <summary>
	/// ������ ��� FirstPage
	/// </summary>
	public ref class FirstPage : public System::Windows::Forms::Form
	{
	public:
		FirstPage(void)
		{
			InitializeComponent();
			dbConnection = gcnew OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0;Data Source = MyDatabase.mdb");
		}
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~FirstPage()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button2;
	private: OleDb::OleDbConnection ^dbConnection;
	protected:

	private:
		Map ^newMap;
		RegistrationForm^ newRegistr;
		LoginForm^ newLogin;
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

	private: System::Windows::Forms::Button^  button3;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			this->button2->Location = System::Drawing::Point(106, 93);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Registration";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FirstPage::button2_Click);
			this->button3->Location = System::Drawing::Point(106, 121);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Login";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FirstPage::button3_Click);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Name = L"FirstPage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FirstPage";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
};
}
