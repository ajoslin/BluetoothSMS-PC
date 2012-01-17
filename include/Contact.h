#ifndef Contact_L
#define Contact_L
#include<string>
#include<map>
namespace bsms
{
  class Contact
  {
  private:
    static std::map<ContactId,Contact> contact_list;
  public:
    Contact(std::string name, std::string number);

    //Id used to reference contacts
    typedef int ContactId;
    
    //Pulls contact information from global contact list. Returns a copy
    static Contact find_by_id(ContactId id);
    std::string get_name();
    std::string get_number();
    //Gets the contact's unique id
    ContactId get_id();
  };
};
#endif
