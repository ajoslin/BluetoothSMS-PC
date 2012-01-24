#include "gui/ContactsListBox.h"

ContactsListBox::ContactsListBox(wxWindow *parent)
	: wxListBox(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxArrayString(), wxLB_SINGLE)
{
	bsms::Contact("Bob Smith", "22-22222222");
	bsms::Contact("Harry Jones", "40040404");
	bsms::Contact("Andy Joslin", "72602119");
	bsms::Contact("Tyler Dodge", "9392040");

	repopulate();
}

void ContactsListBox::repopulate()
{
	//TODO maybe add <firstLetter, lastLetter> filter for the iterator (For search efficiency)
	Clear();

	wxString search_key = get_search_key().Lower(); //lowercase for comparison

	bsms::Contact::ContactIterator itr = bsms::Contact::begin();
	bsms::Contact::ContactIterator end = bsms::Contact::end();

	bsms::Contact c;
	while (itr != end)
	{
		c = *itr;
		wxString contact_name = wxString::FromUTF8(c.get_name().c_str());
		wxString contact_number = wxString::FromUTF8(c.get_number().c_str());
		if (contact_name.Lower().Contains(search_key) || contact_number.Lower().Contains(search_key))
			Append(contact_name + wxT(" - ") + contact_number);
		itr++;
	}


	//todo add iterator gotten from bsms::contact once added
	//Iterate through contacts and if the contact name or number contains current filter, add it to list
}

void ContactsListBox::set_search_key(wxString key)
{
	SearchableItemInterface::set_search_key(key);
	repopulate();
}

bsms::Contact::ContactId ContactsListBox::get_selected()
{
	return bsms::Contact().get_id();
}
