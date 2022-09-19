#include "CharStack.h"
#include "CharList.h"
#include <iostream>
using namespace std;

void CharStack::push(const char &data)
{
  insertAtFront(data);
}

bool CharStack::pop(char &data)
{
  return removeFromFront(data);
}

char CharStack::stackTop() const
{
  return (!isEmpty() ? firstPtr->getData() : static_cast<char>(0));
}

bool CharStack::isStackEmpty() const
{
  return this->isEmpty();
}

void CharStack::printStack() const
{
  if(this->isEmpty())
  {
    cout<<"The stack is empty"<<endl;
    return ;
  }

  cout<<"The stack is: ";
  this->print();
}
