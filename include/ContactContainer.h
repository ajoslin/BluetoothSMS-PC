#ifndef ContactContainer_H
#define ContactContainer_H

#include "bsms.h"
#include<map>
#include<list>

#define TOTAL_LETTERS ('Z'-'A')
#define GET_LETTER_INDEX( L ) ( ((L)>='a' ? (L)-('a'-'Z') : (L)) - 'A' )

START_BSMS

class Contact;

class ContactContainer
{
 public:
  typedef int ContactId;
  typedef std::list<Contact> ContactList;
  typedef ContactList::const_iterator ContactIterator;
 private:
  typedef std::map<ContactId,Contact> ContactMap;

  ContactList::iterator contact_letters[TOTAL_LETTERS];

  ContactMap contact_map;

  ContactList contact_list;

  ContactId next_id;
 public:
  ContactContainer();
  
  void add_contact(Contact contact);  
  
  ContactId get_next_id();
  
  Contact find_by_id(ContactId id);

  ContactIterator begin();
  
  ContactIterator begin(char startLetter);
  
  ContactIterator end(char letter);
  
  ContactIterator end();
};

END_BSMS

#endif

