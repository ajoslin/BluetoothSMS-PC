#include "gui/MessageGroupPanel.h"
#include "appstrings.h"

MessageGroupPanel::MessageGroupPanel(wxWindow * parent)
	: wxPanel(parent)
{
	main_sizer = new wxBoxSizer(wxVERTICAL);

	items_count=0;

	SetSizer(main_sizer);
}

void MessageGroupPanel::add_message(bsms::Message msg)
{
	main_sizer->Prepend(new MessagePanel(this, msg));

	items_count++;

	repopulate();
}

void MessageGroupPanel::repopulate()
{
	//Hide/show items depending on search key
	for (int i=0; i<items_count; i++)
	{
		MessagePanel *p = (MessagePanel *)main_sizer->GetItem(i);
		main_sizer->Show(i, p->get_message_text().Contains(get_search_key()));
	}
	main_sizer->Layout();
}

void MessageGroupPanel::set_search_key(wxString key)
{
	SearchableItemInterface::set_search_key(key);
	repopulate();
}
