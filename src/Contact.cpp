#include "Contact.h"


START_BSMS

ContactContainer Contact::contact_list;

Contact::Contact() : 
  id(EMPTY_CONTACT) { }

Contact::Contact(std::string name_, std::string number_) :
  name(name_), number(number_), id(contact_list.get_next_id()) 
{
  contact_list.add_contact(*this); //copy constructor
}

Contact::ContactIterator Contact::begin()
{
  return contact_list.begin();
}
Contact::ContactIterator Contact::iterator(char letter)
{
  return contact_list.iterator(letter);
}
Contact::ContactIterator Contact::end()
{
  return contact_list.end();
}

std::string Contact::get_name()
{
  return name;
}

std::string Contact::get_number()
{
  return number;
}

Contact::ContactId Contact::get_id()
{
  return id;
}

bool Contact::is_empty()
{
  return id==EMPTY_CONTACT;
}

END_BSMS
