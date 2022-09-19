#ifndef INTLIST_H
#define INTLIST_H

#include "IntListNode.h"

class IntList
{
  public:
    IntList();
    ~IntList();
    void insertAtFront(const int&);
    void insertAtBack(const int&);
    bool removeFromFront(int&);
    bool removeFromBack(int&);
    bool isEmpty() const;
    void print() const;

  protected:
    IntListNode *firstPtr, *lastPtr;
    IntListNode *getNewNode(const int&);
};
#endif
