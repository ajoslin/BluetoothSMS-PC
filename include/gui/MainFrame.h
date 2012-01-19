#ifndef BlueFrame_L
#define BlueFrame_L

#include "wx/wx.h"
#include "wx/toolbar.h"
#include "wx/srchctrl.h"

//Toolbar options
enum
{
	TOOL_Devices,
};

class MainFrame : public wxFrame
{
private:
	wxBoxSizer * main_boxsizer;

	wxToolBar * main_toolbar;

	//contact list with search
	wxSearchControl * contacts_searchctrl;
	wxListBox * contacts_listbox;
	wxButton * start_convo_button;

	//message threads list with search
	wxSearchControl * messages_searchctrl;
	MessageThreadsPanel * messages_panel;

public:
	MainFrame(const wxString title);

	//wx events
	void on_toolbar_devices(wxCommandEvent e);
};

#endif
