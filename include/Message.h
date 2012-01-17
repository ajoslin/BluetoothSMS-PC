#ifndef Message_L
#define Message_L
#include "Contact.h"
namespace bsms
{
  class Message
  {
  private:
  public:
    typedef int TimeStamp;
    Message(Contact::ContactId owner, std::string message, TimeStamp time);

    Contact::ContactId get_owner_id();
    std::string get_message();
    std::string get_formatted_time();
  };
};
#endif
