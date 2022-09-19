#ifndef CHARSTACK_H
#define CHARSTACK_H

#include "CharList.h"

class CharStack : private CharList
{
  public:
    void push(const char&);
    bool pop(char&);
    char stackTop() const;
    bool isStackEmpty() const;
    void printStack() const;
};

#endif // CHARSTACK_H
