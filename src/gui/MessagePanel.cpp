#include "gui/MessagePanel.h"
#include "gui/dimensions.h"

MessagePanel::MessagePanel(wxWindow * parent, bsms::Message message, int align)
	: wxPanel(parent)
{
	main_sizer = new wxStaticBoxSizer(wxVERTICAL, this, wxT(""));
	info_sizer = new wxBoxSizer(wxHORIZONTAL);
	message_sizer = new wxBoxSizer(wxHORIZONTAL);

	sender_label = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxBORDER_NONE);
	date_label = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxBORDER_NONE);
	message_label = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxBORDER_NONE);
	message_label->SetSize(wxSize(DIM_MESSAGEBIG_W*0.9, DIM_MESSAGE_H*0.9));

	info_sizer->Add(sender_label, wxALIGN_LEFT | wxEXPAND | wxALL);
	info_sizer->Add(date_label, wxALIGN_RIGHT | wxEXPAND | wxALL);

	message_sizer->AddSpacer(5);
	message_sizer->Add(message_label);

	main_sizer->Add(info_sizer, wxEXPAND);
	main_sizer->Add(message_sizer, wxEXPAND);

	SetSizer(main_sizer);

	if (align==wxALIGN_CENTER)
		SetMaxSize(wxSize(DIM_MESSAGEBIG_W, DIM_MESSAGE_H));
	else
		SetMaxSize(wxSize(DIM_MESSAGE_W, DIM_MESSAGE_H));

	set_message(message);
}

void MessagePanel::set_message(bsms::Message message)
{
	sender_label->ChangeValue(wxT("Bob Frank Joe"));
	date_label->ChangeValue(wxString::FromUTF8(message.get_formatted_time().c_str()));
	//message_label->ChangeValue(wxString::FromUTF8(message.get_message().c_str()));

	message_label->ChangeValue(wxT("The quick brown fox jumped over the lazy cat. And then it died. But GitHub came and created a new one. Hooray. Yay."));
}

void MessagePanel::set_search_key(wxString key)
{
	SearchableItemInterface::set_search_key(key);
}