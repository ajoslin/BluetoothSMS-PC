#ifndef BLUEDEVICE_H_
#define BLUEDEVICE_H_

#include "wx/wx.h"
#include "wx/statbmp.h"

class BlueDevice : public wxPanel
{
private:
	wxBoxSizer *mainSizer;
	wxBoxSizer *infoSizer;

	wxStaticText *nameLabelText;
	wxTextCtrl *nameText;

	wxStaticText *numberLabelText; 
	wxTextCtrl *numberText;

	wxString deviceName;
	wxString deviceNumber;

public:
	BlueDevice(wxWindow *parent);

	void setName(wxString name);
	void setNumber(wxString number);
	wxString getName() { return deviceName; }
	wxString getNumber() { return deviceNumber; }
};


#endif

