#ifndef ContactsListView_L
#define ContactsListView_L

#include "wx/wx.h"
#include "Contact.h"

class ContactsListView : public wxListView
{
private:

public:
	ContactsListView(wxWindow *parent);

	//set contact

	//gets selected contact's id
	bsms::ContactId get_selected();
	//updates displayed contacts, with selected filter (empty, or a search phrase)
	void filter_list(wxString);
	//gets the contaclist
	void fetch_contact_list();
};

#endif