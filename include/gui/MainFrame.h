#ifndef BlueFrame_L
#define BlueFrame_L

#include "wx/wx.h"
#include "wx/toolbar.h"
#include "wx/srchctrl.h"

//Toolbar options
enum ToolbarOptions
{
	TOOL_Devices,
};

class MainFrame : public wxFrame
{
private:
	wxBoxSizer * main_boxsizer;

	wxToolBar * main_toolbar;

	//contact list with search
	wxSearchCtrl * contacts_search;
	ContactsListView * contacts_list;
	wxButton * contacts_open_button;

	//message threads list with search
	wxSearchCtrl * messages_search;
	MessageThreadsPanel * messages_panel;

	void event_search_contacts(wxCommandEvent &);
	void event_search_messages(wxCommandEvent &);

public:
	MainFrame(const wxString title);
};

#endif
