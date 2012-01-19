class MessageThread;
#ifndef MessageThread_L
#define MessageThread_L
#include "bsms.h"
#include <vector>
#include "Message.h"
START_BSMS
class MessageThread
{
 private:
 public:
  typedef std::vector<Message>::const_iterator MessageIterator;
  
  //gets the contact that is connected to this message thread.
  Contact::ContactId get_owner_id();
  
  //Used for iterating through messages
  MessageIterator iterator();
  
  //Handles sending a message to the owner of the Message thread
  void send_message(Message message);
  
  //returns true if new message is received since last message
  bool poll_messages();
  
  //returns the last message in the list
  Message get_last_message();
};
END_BSMS
#endif
