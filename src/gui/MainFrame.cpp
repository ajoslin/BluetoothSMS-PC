#include "gui/MainFrame.h"
#include "appstrings.h"

MainFrame::MainFrame(const wxString title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize)
{
	main_boxsizer = new wxBoxSizer(wxVERTICAL);

	//Create the toolbar
	main_toolbar = CreateToolBar(wxTB_TEXT | wxTB_HORIZONTAL);
	//main_toolbar->AddTool(TOOL_Devices, wxT(STR_ADD_DEVICE));
	main_toolbar->Realize();

	int window_width, window_height;
	GetSize(&window_width, &window_height);

	//variables for settings different things' width/height
	int width, height;

	//Create the contacts list stuffs
	contacts_search = new wxSearchCtrl(this, wxID_ANY);
	contacts_search->GetSize(&width, &height);
	contacts_search->SetMinSize(wxSize(width*2, height));

	contacts_list = new ContactsListBox(this);
	contacts_list->SetMinSize(wxSize(window_width, window_height/4));
	contacts_open_button = new wxButton(this, wxID_ANY, wxT(STR_OPEN_CONVO));

	//Create messagethreadlist stuff
	messages_search = new wxSearchCtrl(this, wxID_ANY, wxT(STR_SEARCH_MSG));
	messages_search->GetSize(&width, &height);
	messages_search->SetMinSize(wxSize(width*2, height));

	messages_panel = new MessageThreadsPanel(this);
	messages_panel->SetMinSize(wxSize(window_width, window_height/2));

	main_boxsizer->AddSpacer(15);
	main_boxsizer->Add(contacts_search);
	main_boxsizer->Add(contacts_list);
	main_boxsizer->Add(contacts_open_button);
	main_boxsizer->AddSpacer(30);
	main_boxsizer->Add(messages_search);
	main_boxsizer->Add(messages_panel);

	Connect(contacts_search->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::event_search_contacts));
	//Connect(contacts_list->GetId(), wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler(MainFrame::event_contact_doubleclicked));
	Connect(messages_search->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::event_search_messages));

	SetSizerAndFit(main_boxsizer);
}

void MainFrame::event_search_contacts(wxCommandEvent & e)
{
	contacts_list->set_search_key(contacts_search->GetValue());
}

void MainFrame::event_search_messages(wxCommandEvent & e)
{
	messages_panel->set_search_key(messages_search->GetValue());
}
