class Message;
#ifndef Message_L
#define Message_L
#include "bsms.h"
#include "Contact.h"
#include "MessageThread.h"
#include <sstream>
#include <string>
START_BSMS
class Message
{
 public:
  typedef int TimeStamp;
 private:
  MessageThread * owner;
  std::string message;
  TimeStamp time;
 public:
  Message();
  Message(MessageThread * owner, std::string message, TimeStamp time);
  
  //gets the message thread that this message belongs to
  MessageThread * get_owner();
  std::string get_message();
  std::string get_formatted_time();
};
END_BSMS
#endif
