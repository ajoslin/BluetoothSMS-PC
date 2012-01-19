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
	wxSearchCtrl * contacts_searchctrl;
	wxListBox * contacts_listbox;
	wxButton * start_convo_button;

	//message threads list with search
	wxSearchCtrl * messages_searchctrl;
	//MessageThreadsPanel * messages_panel;

public:
	MainFrame(const wxString title);
};

#endif
