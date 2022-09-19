#ifndef CHARLIST_H
#define CHARLIST_H

#include "CharListNode.h"

class CharList
{
  public:
    CharList();
    ~CharList();
    void insertAtFront(const char&);
    void insertAtBack(const char&);
    bool removeFromFront(char&);
    bool removeFromBack(char&);
    bool isEmpty() const;
    void print() const;

  protected:
    CharListNode *firstPtr, *lastPtr;
    CharListNode *getNewNode(const char&);
};


#endif // CHARLIST_H
