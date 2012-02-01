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
  int letter = GET_LETTER_INDEX( name[ 0 ] );
  ContactList::iterator end_it = contact_list.end();
  ContactList::iterator it = contact_letters[ letter ];
  bool set_letter=false;
  if ( it == end_it )
    {
      int closestLetter = letter;
      while (it==end_it && --closestLetter >= 0)
	{	  
	  it = contact_letters[ closestLetter ];
	}
      if (it==end_it)
	{
	  it=contact_list.begin();
	}
      else
	{
	  it++;
	}
      set_letter=true;
    }
  else
    {
      bool is_done = false;
      unsigned int letter_index = 0;
      while (!is_done && it != end_it)
	{
	  std::string other_name = it->get_name();
	  unsigned int length = name.size();
	  char new_letter, other_letter;
	  
	  length = (length <= other_name.size()) ? length : other_name.size();
	  while ( letter_index < length && 
		  (new_letter   = GET_LETTER_INDEX( name[ letter_index ] ),       //sets new letter
		   other_letter = GET_LETTER_INDEX( other_name[ letter_index ] ), //sets other letter
		   new_letter == other_letter ) )                               
	    {
	      letter_index++;
	    }
	  if ( letter_index >= length )
	    {
	      is_done = true;
	    }
	  else if ( new_letter < other_letter )
	    {
	      is_done = true;
	    }
	  else //if the new_letter > other_letter
	    {
	      is_done = true;
	      it++;
	    }
	}      
      if ( it == contact_letters[ letter ] )
	{
	  set_letter=true;
	};
    }
  ContactList::iterator insert_it = contact_list.insert( it, ( contact_map[ contact.get_id() ] = contact ) );
  if (set_letter)
    {
      contact_letters[ letter ] = insert_it;
    }
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
  return contact_letters[ GET_LETTER_INDEX( StartLetter ) ];
}

ContactContainer::ContactIterator ContactContainer::end(char letter)
{
  int nextSet = GET_LETTER_INDEX( letter );
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
