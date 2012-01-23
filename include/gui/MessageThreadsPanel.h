//MessageThreadsPanel just holds a list of message threads

#ifndef MessageThreadsPanel_L
#define MessageThreadsPanel_L

#include "wx/wx.h"
#include "wx/scrolbar.h"
#include "MessageThread.h"
#include <stack>

class MessageThreadsPanel : public wxPanel
{
private:
	//stack so latest is on top
	std::stack<MessagePanel> messages;

public:
	MessageThreadsPanel(wxWindow *parent);

	void add_message_thread(bsms::MessageThread thread);
};

#endif