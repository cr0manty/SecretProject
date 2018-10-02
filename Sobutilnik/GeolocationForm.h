#pragma once

namespace Sobutilnik {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Device::Location;
	using namespace System::Text;


	public ref class GeolocationForm : public System::Windows::Forms::Form
	{
	public:
		GeolocationForm(void)
		{
			InitializeComponent();
		}
	protected:

		~GeolocationForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::WebBrowser^  webBrowser1;
			 GeoCoordinateWatcher^ Watcher;
			 GeoCoordinate^ coordinate;
			 StringBuilder^ userPosition;
			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

			 void InitializeComponent(void)
			 {
				 this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
				 this->SuspendLayout();
				 this->webBrowser1->Location = System::Drawing::Point(5, 0);
				 this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
				 this->webBrowser1->Name = L"webBrowser1";
				 this->webBrowser1->Size = System::Drawing::Size(972, 602);
				 this->webBrowser1->TabIndex = 0;
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(989, 614);
				 this->Controls->Add(this->webBrowser1);
				 this->Name = L"GeolocationForm";
				 this->Text = L"GeolocationForm";
				 this->Load += gcnew System::EventHandler(this, &GeolocationForm::GeolocationForm_Load);
				 this->ResumeLayout(false);

			 }
#pragma endregion
	private: System::Void GeolocationForm_Load(System::Object^  sender, System::EventArgs^  e);
	};
}
