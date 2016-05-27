#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define _CRT_SECURE_NO_WARNINGS

struct Node
{
  void* data_;
  Node* next_;

  Node()
  {
    data_ = 0;
    next_ = 0;
  }
};

class LinkedList
{
 private:
  Node* first_;
  Node* last_;
  Node* curNode_;
  long listLen_;

 public:
  LinkedList();
  ~LinkedList();
  void AddLinkToBack(void* ptr);
  void* RemoveLinkFromFront();
  void* GetFirstNode();
  void* GetNextNode();
  long GetListLength();
};



#endif
