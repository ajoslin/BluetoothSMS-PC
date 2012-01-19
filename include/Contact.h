#ifndef Contact_L
#define Contact_L
#include<string>
#include<map>
#define START_CONTACT_ID 0
#define EMPTY_CONTACT -1
namespace bsms
{
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

    //Id used to reference contacts
    
    //Pulls contact information from global contact list. Returns a copy
    static Contact find_by_id(ContactId id);
    std::string get_name();
    std::string get_number();
    //Gets the contact's unique id
    ContactId get_id();
    bool is_empty();
  };
};
#endif
