#include "gui/MainFrame.h"
#include "gui/ContactsListBox.h"
#include "gui/MessageGroupPanel.h"
#include "appstrings.h"
#include "gui/dimensions.h"

#include <stdio.h>

MainFrame::MainFrame(const wxString title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize)
{
	main_sizer = new wxBoxSizer(wxVERTICAL);

	//Create the toolbar
	main_toolbar = CreateToolBar(wxTB_TEXT | wxTB_HORIZONTAL);
	//main_toolbar->AddTool(TOOL_Devices, wxT(STR_ADD_DEVICE));
	main_toolbar->Realize();

	contacts_search = new wxSearchCtrl(this, wxID_ANY);
	contacts_list = new ContactsListBox(this);
	contacts_open_button = new wxButton(this, wxID_ANY, wxT(STR_OPEN_CONVO));

	messages_search = new wxSearchCtrl(this, wxID_ANY);
	message_group_panel = new MessageGroupPanel(this);

	main_sizer->AddSpacer(15);
	main_sizer->Add(contacts_search);
	main_sizer->Add(contacts_list);
	main_sizer->Add(contacts_open_button);
	main_sizer->AddSpacer(30);
	main_sizer->Add(messages_search);
	main_sizer->Add(message_group_panel);

	Connect(contacts_search->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::event_search_contacts));
	//Connect(contacts_list->GetId(), wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler(MainFrame::event_contact_doubleclicked));
	Connect(messages_search->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::event_search_messages));

	//Searchbox sizes
	int width,height;
	contacts_search->GetSize(&width, &height);
	contacts_search->SetMinSize(wxSize(width*2, height));
	messages_search->SetMinSize(wxSize(width*2, height));

	SetSizerAndFit(main_sizer);
}

void MainFrame::event_search_contacts(wxCommandEvent & e)
{
	contacts_list->set_search_key(contacts_search->GetValue());
}

void MainFrame::event_search_messages(wxCommandEvent & e)
{
	message_group_panel->set_search_key(messages_search->GetValue());
}
