#include "ContactContainer.h"

#include "Contact.h"

#include<iostream>
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
  bool set_letter=false;
  if ( it == end_it )
    {
      int closestLetter = letter;
      while (it==end_it && --closestLetter > 0)
	{
	  it = contact_letters[ closestLetter ];
	}
      if (it==end_it)
	it=contact_list.begin();
      else
	{
	}
      set_letter=true;
    }
  else
    {
      std::cout << name << std::endl;
      bool is_done = false;
      unsigned int letter_index = 0;
      while (!is_done && it != end_it)
	{
	  std::string other_name = it->get_name();
	  unsigned int length = name.size();
	  
	  length = (length <= other_name.size()) ? length : other_name.size();
	  while ( letter_index < length && name[ letter_index ] == other_name[ letter_index ] ) 
	    {
	      letter_index++;
	    }
	  std::cout << letter_index << std::endl;
	  if ( letter_index >= length )
	    {
	      is_done = true;
	    }
	  else if ( name[ letter_index ] < other_name[ letter_index ] )
	    {
	      is_done = true;
	    }
	  else
	    letter_index++;
	}      
      if ( it == contact_letters[ letter ] )
	{
	  set_letter=true;
	};
    }
  contact_list.insert( it, ( contact_map[ contact.get_id() ] = contact ) );
  if (set_letter)
      contact_letters[ letter ] = it;
}

ContactContainer::ContactId ContactContainer::get_next_id()
{
  return next_id++;
}

ContactContainer::ContactIterator ContactContainer::begin()
{
  return contact_list.begin();
}
ContactContainer::ContactIterator ContactContainer::end()
{
  return contact_list.end();
}

ContactContainer::ContactIterator ContactContainer::begin(char StartLetter)
{
  return contact_letters[ StartLetter - 'A' ];
}

ContactContainer::ContactIterator ContactContainer::end(char letter)
{
  int nextSet = letter-'A';
  ContactIterator end_it = contact_list.end();
  ContactIterator it = end_it;
  while ( ++nextSet < TOTAL_LETTERS && ( it = contact_letters[ nextSet ] ) == end_it ) { }
  return end_it;
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
