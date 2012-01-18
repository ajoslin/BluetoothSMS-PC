#include <gui/BlueDevice.h>
#include <appstrings.h>

BlueDevice::BlueDevice(wxWindow *parent)
	: wxPanel(parent)
{
	mainSizer = new wxBoxSizer(wxHORIZONTAL);
	infoSizer = new wxBoxSizer(wxVERTICAL);

	nameLabelText = new wxStaticText(this, wxID_ANY, wxT(STR_DEVICE_NAME));
	nameText = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NONE, &deviceName));

	numberLabelText = new wxStaticText(this, wxID_ANY, wxT(STR_DEVICE_NUM));
	numberText = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NUMERIC, &deviceNumber));

	mainSizer->AddSpacer(10);
	infoSizer->Add(nameLabelText);
	infoSizer->Add(nameText);
	infoSizer->AddSpacer(10);
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