#ifndef ContactsListView_L
#define ContactsListView_L

#include "wx/wx.h"
#include "wx/listctrl.h"
#include "Contact.h"
#include "SearchInterface.h"
#include <vector>

class ContactsListView : public wxListView
{
private:
	wxString current_filter;

	//called on opening or on a search
	void repopulate_list();

public:
	ContactsListView(wxWindow *, wxWindowID id);

	//gets selected contact's id
	bsms::ContactId get_selected();

	//sets the filter (a search phrase) to display the list with. could be empty.
	void set_filter(wxString);
};

#endif
