//MessageGroupPanel just holds a list of message threads

#ifndef MessageGroupPanel_L
#define MessageGroupPanel_L

#include "wx/wx.h"
#include "MessageThread.h"
#include "gui/SearchableItemInterface.h"
#include <vector>

//fwd declaration
class MessagePanel;

class MessageGroupPanel : public wxPanel, SearchableItemInterface
{
private:
	wxStaticBoxSizer * main_sizer;

	std::vector<MessagePanel *> message_panels;

public:
	MessageGroupPanel(wxWindow * parent);

	void add_message(bsms::Message m, int align = wxALIGN_CENTER);

	void set_search_key(wxString);

	void repopulate();
};

#endif
