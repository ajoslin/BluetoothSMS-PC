#include "gui/MainFrame.h"
#include "gui/DevicePanel.h"
#include "appstrings.h"

MainFrame::MainFrame(const wxString title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize)
{
 	main_sizer = new wxBoxSizer(wxVERTICAL);
 	main_toolbar = new wxToolBar(this, wxID_ANY);

 	main_toolbar->AddTool(TOOL_Devices, wxT(STR_DEVICES));
 	main_toolbar->Realize();

 	//Connections
 	Connect(TOOLBAR_About, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::on_toolbar_devices));

 	SetSizerAndFit(main_sizer);
}

void MainFrame::on_toolbar_devices(wxCommandEvent &e)
{
	
}

void MainFrame::add_device(wxString name, wxString number)
{
	DevicePanel *device = new DevicePanel(devices_book);
	device->set_name(name);
	device->set_number(number);
	devices_book->AddPage(device, name);
}
