#include "Contact.h"
namespace bsms
{
  std::map<Contact::ContactId,Contact> Contact::contact_list;
  
  Contact::ContactId Contact::next_id = START_CONTACT_ID;

  Contact::Contact() : 
    id(EMPTY_CONTACT) { }

  Contact::Contact(std::string name_, std::string number_) :
    name(name_), number(number_), id(next_id++) 
  {
    Contact::contact_list[id] = *this; //copy constructor
  }

  Contact Contact::find_by_id(ContactId id)
  {
    ContactMap::iterator it=Contact::contact_list.find(id);
    if (it!=Contact::contact_list.end())
      return it->second;
    else
      return Contact();
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
};
