class MessageThread;
#ifndef MessageThread_L
#define MessageThread_L
#include "bsms.h"
#include <vector>
#include <stack>
#include "Message.h"
START_BSMS
class MessageThread
{
 private:
  typedef std::vector<Message> MessageList;
  std::stack<Message *> new_messages;
  Contact::ContactId id;
  MessageList messages;
 public:
  typedef MessageList::const_iterator MessageIterator;
  
  //gets the contact that is connected to this message thread.
  Contact::ContactId get_owner_id();
  
  //Used for iterating through messages
  MessageIterator begin();
  MessageIterator end();
  
  //Handles sending a message to the owner of the Message thread
  void send_message(Message message);
  
  //returns true if any messages are on the new message stack
  bool poll_messages();
  
  //pops the newest message off the stack
  Message get_last_message();
};
END_BSMS
#endif
