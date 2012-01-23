#ifndef MessagePanel_L
#define MessagePanel_L

#include "wx/wx.h"
#include "Message.h"

class MessagePanel : public wxPanel
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
	MessagePanel(wxWindow * parent, bsms::Message message) : MessagePanel(parent) { setMessage(message); }

	void set_message(bsms::Message message);

	bool search(wxString);
};

#endif
