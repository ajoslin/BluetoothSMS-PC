#ifndef MessagePanel_L
#define MessagePanel_L

#include "wx/wx.h"
#include "Message.h"
#include "gui/SearchableItemInterface.h"

class MessagePanel : public wxPanel, SearchableItemInterface
{
private:
	wxStaticBoxSizer * main_sizer;
	wxBoxSizer * info_sizer;
	wxBoxSizer * message_sizer;

	wxTextCtrl * sender_label;
	wxTextCtrl * date_label;
	wxTextCtrl * message_label;

	bsms::Message message;

public:
	MessagePanel(wxWindow * parent, bsms::Message message, int align = wxALIGN_CENTER);

	void set_message(bsms::Message message);

	void set_search_key(wxString);

	wxString get_message_text() { return message_label->GetValue(); }
	wxString get_sender_text() { return sender_label->GetValue(); }
};

#endif
