#include "ContactContainer.h"

#include "Contact.h"

START_BSMS

ContactContainer::ContactContainer()
{  
  for (int i=0;i<'Z'-'A';i++)
    {
      contact_letters[i]=contact_list.end();
    }
  
}
void ContactContainer::add_contact( Contact contact )
{
  std::string name = contact.get_name();
  int letter = name[ 0 ] - 'A';
  ContactList::iterator end_it = contact_list.end();
  ContactList::iterator it = contact_letters[ letter ];
  if ( it == end_it )
    {
      int closestLetter = letter;
      while (it==end_it && closestLetter-- > 0)
	{
	  it = contact_letters[ closestLetter ];
	}
      it++;
      contact_letters[ letter ] = it;
    }
  else
    {
      bool is_done=false;
      while (!is_done && it!=end_it)
	{
	  unsigned int letter_index = 0;
	  std::string other_name = it->get_name();
	  unsigned int length = name.size();
	  
	  length = (length <= other_name.size()) ? length : other_name.size();
	  
	  while ( letter_index < length && name[ letter_index ] == other_name[ letter_index ] ) { }
	  
	  if ( letter_index == length || name[ letter_index ] < other_name[ letter_index ] )
	    {
	      is_done = true;
	    }
	}      
    }
  contact_list.insert( it, ( contact_map[ contact.get_id() ] = contact ) );
}

ContactContainer::ContactId ContactContainer::get_next_id()
{
  return next_id++;
}

ContactContainer::ContactIterator ContactContainer::iterator()
{
  return contact_list.begin();
}

ContactContainer::ContactIterator ContactContainer::iterator(char StartLetter)
{
  return contact_letters[ StartLetter - 'A' ];
}

Contact ContactContainer::find_by_id(ContactContainer::ContactId id)
{
  ContactMap::iterator it = ContactContainer::contact_map.find(id);
  if (it!=ContactContainer::contact_map.end())
    return it->second;
  else
    return Contact();
}

END_BSMS
