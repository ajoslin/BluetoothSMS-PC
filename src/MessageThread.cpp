#include "MessageThread.h"
START_BSMS
Contact::ContactId MessageThread::get_owner_id()
{
  return id;
}
MessageThread::MessageIterator MessageThread::begin()
{
  return messages.begin();
}
MessageThread::MessageIterator MessageThread::end()
{
  return messages.end();
}
void MessageThread::send_message(Message message)
{
  //TODO: implement sending message
}
bool MessageThread::poll_messages()
{
  //TODO: implement polling messages, and adding them to the new message stack
  return !new_messages.empty();
}
Message MessageThread::get_last_message()
{
  if (new_messages.empty())
    return Message();
  Message * msg = new_messages.top();
  new_messages.pop();
  return *msg;
}
END_BSMS
