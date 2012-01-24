#include "gui/MessagePanel.h"

MessagePanel::MessagePanel(wxWindow * parent)
	: wxPanel(parent)
{
}

void MessagePanel::set_message(bsms::Message message)
{
	
}

void MessagePanel::set_search_key(wxString key)
{
	SearchableItemInterface::set_search_key(key);
}