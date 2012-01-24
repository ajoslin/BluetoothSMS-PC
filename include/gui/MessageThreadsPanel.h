//MessageThreadsPanel just holds a list of message threads

#ifndef MessageThreadsPanel_L
#define MessageThreadsPanel_L

#include "wx/wx.h"
#include "MessageThread.h"
#include "gui/MessagePanel.h"
#include "gui/SearchableItemInterface.h"
#include <stack>

class MessageThreadsPanel : public wxPanel, SearchableItemInterface
{
private:

public:
	MessageThreadsPanel(wxWindow * parent);

	void set_search_key(wxString);
	//called when opening or on search or when message threads change
	void repopulate();
};

#endif
