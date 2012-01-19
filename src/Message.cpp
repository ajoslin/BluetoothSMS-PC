#include "Message.h"
START_BSMS
Message::Message(): owner(NULL), message(""), time(0) { }
Message::Message(MessageThread * owner_, std::string message_, Message::TimeStamp time_):
  owner(owner_), message(message_), time(time_) { }

MessageThread * Message::get_owner()
{
  return owner;
}
std::string Message::get_message()
{
  return message;
}
std::string Message::get_formatted_time()
{
  std::stringstream stream;
  stream << time;
  return stream.str();
}
END_BSMS
