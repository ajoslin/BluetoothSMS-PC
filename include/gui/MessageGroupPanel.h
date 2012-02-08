//MessageGroupPanel just holds a list of message threads

#ifndef MessageGroupPanel_L
#define MessageGroupPanel_L

#include "wx/wx.h"
#include "MessageThread.h"
#include "gui/MessagePanel.h"
#include "gui/SearchableItemInterface.h"
#include <vector>

enum MsgAlign {
	MSGALIGN_Left,
	MSGALIGN_Right,
};

class MessageGroupPanel : public wxPanel, SearchableItemInterface
{
private:
	wxBoxSizer * main_sizer;
	int items_count;

public:
	MessageGroupPanel(wxWindow * parent);

	void add_message(bsms::Message m);

	void set_search_key(wxString);

	void repopulate();
};

#endif
