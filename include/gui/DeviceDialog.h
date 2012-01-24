#ifndef DeviceWindow_L
#define DeviceWindow_L

#include "wx/wx.h"
#include "wx/dialog.h"
#include "wx/listbook.h"

class Device; //made up for now

class DeviceDialog : public wxDialog
{
private:
	wxBoxSizer * main_sizer;

	wxListbook * devices_list;

	wxButton * new_device_button;
	wxButton * ok_button;
	wxButton * cancel_button;
	
public:
	DeviceDialog(wxWindow *parent);
};

#endif
