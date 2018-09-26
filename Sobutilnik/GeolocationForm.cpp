#include "GeolocationForm.h"


System::Void Sobutilnik::GeolocationForm::GeolocationForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	Watcher = gcnew GeoCoordinateWatcher();

	Watcher->TryStart(false,TimeSpan::FromMilliseconds(1000));

	coordinate = Watcher->Position->Location;

	userPosition = gcnew StringBuilder("https://www.google.com.ua/maps/@");
	userPosition->Append("@" + coordinate->Longitude.ToString()+","+coordinate->Latitude.ToString()+"1000m");

	webBrowser1->Navigate(userPosition->ToString());

}

