#include "BlueDevice.h"
#include "defines.h"

BlueDevice::BlueDevice(wxWindow *parent)
	: wxPanel(parent)
{
	mainSizer = new wxBoxSizer(wxHORIZONTAL);
	infoSizer = new wxGridSizer(2, 2, 1, 1);

	//deviceBitmap = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT(IMG_PHONE), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );

	deviceName=wxT("my device rox. hah.");

	nameLabelText = new wxStaticText(this, wxID_ANY, wxT(STR_DEVICE_NAME));
	nameText = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NONE, &deviceName));

	numberLabelText = new wxStaticText(this, wxID_ANY, wxT(STR_DEVICE_NUM));
	numberText = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC, &deviceNumber));

	//mainSizer->Add(deviceBitmap);
	infoSizer->Add(nameLabelText);
	infoSizer->Add(nameText);
	infoSizer->Add(numberLabelText);
	infoSizer->Add(numberText);
	mainSizer->Add(infoSizer);

	SetSizerAndFit(mainSizer);
}

void BlueDevice::setName(wxString name)
{
	deviceName=name;
}

void BlueDevice::setNumber(wxString number)
{
	deviceNumber=number;
}