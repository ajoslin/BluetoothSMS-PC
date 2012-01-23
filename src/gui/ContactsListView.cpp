#include "ContactsListView.h"

ContactsListView::ContactsListView(wxWindow *parent, wxWindowID id)
	: wxListView(parent, id, wxDefaultPosition, wxDefaultSize, wxLC_VIRTUAL | wxLC_SMALL_ICON | wxLC_SINGLE_SEL)
{
	InsertColumn(0, wxT(STR_NAME));
	InsertColumn(0, wxT(STR_NUMBER));
}

void ContactsListView::repopulate_list(long item)
{
	DeleteAllItems();
	//todo add iterator gotten from bsms::contact once added
	//Iterate through contacts and if the contact name or number contains current filter, add it to list
}

void ContactsListView::set_filter(wxString filter_str)
{
	current_filter = filter_str;
	repopulate_list();
}

bsms::ContactId get_selected()
{
	int selected_index = GetFirstSelected();
	bsms::ContactId * contact_id = (bsms::ContactId *)GetItemData(Get)
}