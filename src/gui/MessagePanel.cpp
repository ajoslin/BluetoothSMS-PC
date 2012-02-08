#include "gui/MessagePanel.h"

MessagePanel::MessagePanel(wxWindow * parent, bsms::Message message)
	: wxPanel(parent)
{
	main_sizer = new wxBoxSizer(wxVERTICAL);
	info_sizer = new wxBoxSizer(wxHORIZONTAL);

	sender_label = new wxStaticText(this, wxID_ANY, wxT(""));
	date_label = new wxStaticText(this, wxID_ANY, wxT(""));
	message_label = new wxStaticText(this, wxID_ANY, wxT(""));

	info_sizer->Add(sender_label, wxALIGN_LEFT);
	info_sizer->Add(date_label, wxALIGN_RIGHT);

	main_sizer->Add(info_sizer);
	main_sizer->AddSpacer(10);
	main_sizer->Add(message_label);

	set_message(message);

	SetSizer(main_sizer);
}

void MessagePanel::set_message(bsms::Message message)
{
	sender_label->SetLabel(wxT("Bob Frank Joe"));
	date_label->SetLabel(wxString::FromUTF8(message.get_formatted_time().c_str()));
	message_label->SetLabel(wxString::FromUTF8(message.get_message().c_str()));
}

void MessagePanel::set_search_key(wxString key)
{
	SearchableItemInterface::set_search_key(key);
}