#ifndef MessagePanel_L
#define MessagePanel_L

#include "wx/wx.h"
#include "Message.h"
#include "gui/SearchableItemInterface.h"

class MessagePanel : public wxPanel, SearchableItemInterface
{
private:
	wxBoxSizer * main_boxsizer;
	wxBoxSizer * info_boxsizer;

	wxStaticText * sender_label;
	wxStaticText * date_label;
	wxStaticText * message_label;

	bsms::Message message;

public:
	MessagePanel(wxWindow * parent);

	void set_message(bsms::Message message);

	void set_search_key(wxString);
};

#endif
