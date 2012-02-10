#include "gui/MessageGroupPanel.h"
#include "gui/MessagePanel.h"
#include "gui/dimensions.h"
#include "appstrings.h"

MessageGroupPanel::MessageGroupPanel(wxWindow * parent)
	: wxPanel(parent)
{
	main_sizer = new wxStaticBoxSizer(wxVERTICAL, this, wxT(""));
	main_sizer->AddSpacer(10);

	SetMinSize(wxSize(DIM_MESSAGES_W, DIM_MESSAGES_H));
	main_sizer->SetMinSize(wxSize(DIM_MESSAGES_W, DIM_MESSAGES_H));
	SetSizer(main_sizer);

	add_message(bsms::Message());
}

void MessageGroupPanel::add_message(bsms::Message msg, int align)
{
	MessagePanel * m_panel = new MessagePanel(this, msg, align);
	main_sizer->Insert(1, m_panel, align | wxEXPAND);
	main_sizer->Layout();

	message_panels.push_back(m_panel);

	repopulate();
}

void MessageGroupPanel::repopulate()
{
	//Hide/show items depending on search key
	int n=message_panels.size();
	for (int i=0; i<n; i++)
	{
		wxString search = get_search_key().Lower();
		wxString message = message_panels[i]->get_message_text().Lower();
		wxString sender = message_panels[i]->get_sender_text().Lower();
		message_panels[i]->Show(message.Contains(search) || sender.Contains(search));
	}
	main_sizer->Layout();
}

void MessageGroupPanel::set_search_key(wxString key)
{
	SearchableItemInterface::set_search_key(key);
	repopulate();
}
