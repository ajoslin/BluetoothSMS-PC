#ifndef Contact_L
#define Contact_L
#include"bsms.h"
#include<string>
#include<map>
#define START_CONTACT_ID 0
#define EMPTY_CONTACT -1
START_BSMS
class Contact
{
 public:
  typedef int ContactId;
 private:
  typedef std::map<ContactId,Contact> ContactMap;
  static ContactMap contact_list;
  static ContactId next_id;
  std::string name;
  std::string number;
  ContactId id;
 public:
  Contact();
  Contact(std::string name, std::string number);  
  //Pulls contact information from global contact list. Returns a copy
  static Contact find_by_id(ContactId id);
  std::string get_name();
  std::string get_number();
  //Gets the contact's unique id
  ContactId get_id();
  bool is_empty();
};
END_BSMS
#endif
