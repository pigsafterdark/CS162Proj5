#include "LinkedList.h"

LinkedList::LinkedList()
{
  listLen_ = 0;
  last_ = 0;
  first_ = 0;
  curNode_ = 0;
}

LinkedList::~LinkedList()
{

}

void LinkedList::AddLinkToBack(void* ptr)
{
  //Store passed-in ptr in a new Node
  Node* aNode = new Node;
  aNode->data_ = ptr;
  aNode->next_ = 0;

  //If there are no nodes in the list,
  //set first_ and last_ pointers to the
  //new Node
  if (listLen_ == 0)
    {
      first_ = aNode;
      last_ = aNode;
    }
  //Else, add the new Node onto the end of the list
  else
    {
      last_->next_ = aNode;
      last_ = aNode;
    }
  //Increment the number of nodes in the linked list
  listLen_++;

}

void* LinkedList::GetFirstNode()
{
  //Set curNode_ to the second node in the list,
  //so the list can be traversed with GetNextNode().
  //Return the data contained in the first Node,
  //so the void* can be caught as Shell* in main.cpp
  curNode_ = first_->next_;
  return first_->data_;
}

void* LinkedList::GetNextNode()
{
  //Store curNode_ in aNode. Set curNode_ to
  //the next node in the list. Return the data
  //contained in aNode, so the void* can be caught as Shell*
  //in main.cpp
  Node* aNode;
  aNode = curNode_;
  curNode_ = curNode_->next_;
  return aNode->data_;
  
}

long LinkedList::GetListLength()
{
  return listLen_;
}

void* LinkedList::RemoveLinkFromFront()
{
  //Store first_ in aNode. Set first_ to the next
  //node in the list. Delete aNode. Decrement the 
  //number of nodes in the list. If there are still
  //nodes in the list, return the data in first_ so
  //that it can be caught in main.cpp as *Shell. 
  //Else, return nothing because the list is empty.
  Node * aNode;
  aNode = first_;
  first_ = first_->next_;
  delete aNode;
  listLen_--;
  if (listLen_ != 0)
    {
      return first_->data_;
    }
  else
    {
      return 0;
    }
}
