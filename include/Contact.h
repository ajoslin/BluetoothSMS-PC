#ifndef Contact_H
#define Contact_H

#include"bsms.h"
#include<string>
#include<map>
#include"ContactContainer.h"

#define START_CONTACT_ID 0
#define EMPTY_CONTACT -1

START_BSMS

class Contact
{
 public:
  typedef ContactContainer::ContactId ContactId;
  typedef ContactContainer::ContactIterator ContactIterator;
 private:
  std::string name;

  std::string number;

  Contact::ContactId id;

  //Global list of contacts
  static ContactContainer contact_list;

 public:
  //Constructs a dummy contact
  Contact();

  //Constructs Contact and adds it to the global list of contacts
  Contact(std::string name, std::string number);

  
  //Pulls contact information from global contact list. Returns a copy
  static Contact find_by_id(Contact::ContactId id);

  //Starts iterator at 'A'
  static ContactIterator begin();
  static ContactIterator end();
  
  //Starts iterator at specified letter. Letter can be uppercase or lowercase, the function converts it to uppercase
  static ContactIterator iterator(char StartLetter);

  
  //Gets Contact's name
  std::string get_name();
  
  //Gets Contact's phone number
  std::string get_number();
  
  //Gets the contact's unique id
  Contact::ContactId get_id();
  
  //Checks if Contact is not a dummy contact
  bool is_empty();
};
END_BSMS
#endif
