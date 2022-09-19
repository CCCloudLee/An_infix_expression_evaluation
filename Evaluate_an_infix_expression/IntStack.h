#ifndef INTSTACK_H
#define INTSTACK_H

#include "IntList.h"

class IntStack : private IntList
{
  public:
    void push(const int&);
    bool pop(int&);
    char stackTop() const;
    bool isStackEmpty() const;
    void printStack() const;
};

#endif
