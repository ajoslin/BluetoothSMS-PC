#ifndef ContactsListBox_L
#define ContactsListBox_L

#include "wx/wx.h"
#include "wx/listbox.h"
#include "Contact.h"
#include "gui/SearchableItemInterface.h"
#include <vector>

class ContactsListBox : public wxListBox, SearchableItemInterface
{
private:

public:
	ContactsListBox(wxWindow * parent);

	//gets selected contact's id
	bsms::Contact::ContactId get_selected();

	void set_search_key(wxString);
	//called on opening or on a search or when contacts change. repopulates list.
	void repopulate();
};

#endif
