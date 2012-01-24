#include "gui/MessageThreadsPanel.h"

MessageThreadsPanel::MessageThreadsPanel(wxWindow * parent)
	: wxPanel(parent)
{
	
}

void MessageThreadsPanel::repopulate()
{
	
}

void MessageThreadsPanel::set_search_key(wxString key)
{
	SearchableItemInterface::set_search_key(key);
	repopulate();
}
