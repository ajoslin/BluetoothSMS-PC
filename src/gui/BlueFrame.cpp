#include <gui/BlueFrame.h>
#include <gui/BlueDevice.h>
#include <appstrings.h>

BlueFrame::BlueFrame(const wxString title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize)
{
 	mainSizer = new wxBoxSizer(wxVERTICAL);
 	deviceSizer = new wxBoxSizer(wxVERTICAL);

 	devicesLabel = new wxStaticText(this, wxID_ANY, wxT(STR_DEVICES));
 	devicesBook = new wxListbook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_LEFT);
 	newDeviceButton = new wxButton(this, wxID_ANY, wxT(STR_ADD_DEVICE));

 	BlueDevice *device = new BlueDevice(devicesBook);
	device->setName(wxT("New Device"));
	device->setNumber(wxT("000"));
 	devicesBook->AddPage(device, wxT("New Device"));

 	deviceSizer->Add(devicesLabel);
 	deviceSizer->Add(devicesBook, 1, wxEXPAND);
 	deviceSizer->Add(newDeviceButton);
 	deviceSizer->SetMinSize(wxSize(GetSize().GetWidth(), 150));

 	mainSizer->Add(deviceSizer);

 	Connect(newDeviceButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(BlueFrame::onNewDeviceButtonPressed));

 	SetSizerAndFit(mainSizer);
}

void BlueFrame::onNewDeviceButtonPressed(wxCommandEvent &e)
{
	addDevice(wxT(STR_DEVICE_NAME_DEF), wxT(STR_DEVICE_NUM_DEF));
}

void BlueFrame::addDevice(wxString name, wxString number)
{
	BlueDevice *device = new BlueDevice(devicesBook);
	device->setName(name);
	device->setNumber(number);
	devicesBook->AddPage(device, name);
}