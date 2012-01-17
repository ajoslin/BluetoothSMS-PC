#ifndef Message_L
#define Message_L
#include "Contact.h"
#include "MessageThread.h"
namespace bsms
{
  class Message
  {
  private:
  public:
    typedef int TimeStamp;
    Message(MessageThread * owner, std::string message, TimeStamp time);

    //gets the message thread that this message belongs to
    MessageThread * get_owner();
    std::string get_message();
    std::string get_formatted_time();
  };
};
#endif
