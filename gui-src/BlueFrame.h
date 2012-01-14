#ifndef BLUEFRAME_H_
#define BLUEFRAME_H_

#include "wx/wx.h"
#include "wx/listbook.h"

class BlueFrame : public wxFrame
{
private:
	wxBoxSizer *mainSizer;
	wxBoxSizer *deviceSizer;

	wxStaticText *devicesLabel;
	wxListbook *devicesBook;
	wxButton *newDeviceButton;
public:
	BlueFrame(const wxString title);

	void onNewDeviceButtonPressed(wxCommandEvent &e);

	void addDevice(wxString name = wxEmptyString, wxString number = wxEmptyString);
};

#endif