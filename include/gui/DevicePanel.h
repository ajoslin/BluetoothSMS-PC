#ifndef BlueDevice_L
#define BlueDevice_L

#include "wx/wx.h"

class Device; //made up class for now

class DevicePanel : public wxPanel
{
private:
	wxBoxSizer * main_sizer;
	wxBoxSizer * info_sizer;

	wxStaticText * name_label_text;
	wxTextCtrl * name_text;

	wxStaticText * number_label_text; 
	wxTextCtrl * number_text;

	wxString device_name;
	wxString device_number;

	Device * device;

public:
	DevicePanel(wxWindow * parent);

	void set_name(wxString name);
	void set_number(wxString number);
	wxString get_name() { return device_name; }
	wxString get_number() { return device_number; }
};


#endif
