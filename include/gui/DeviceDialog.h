#ifndef DeviceWindow_L
#define DeviceWindow_L

#include "wx/wx.h"
#include "wx/dialog.h"

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
	void add_device(Device *d);
};

#endif
