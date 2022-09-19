#include "IntStack.h"
#include "IntList.h"
#include <iostream>
using namespace std;

void IntStack::push(const int &data)
{
  insertAtFront(data);
}

bool IntStack::pop(int &data)
{
  return removeFromFront(data);
}

char IntStack::stackTop() const
{
  return (!isEmpty() ? firstPtr->getData() : static_cast<int>(0));
}

bool IntStack::isStackEmpty() const
{
  return this->isEmpty();
}

void IntStack::printStack() const
{
  if(this->isEmpty())
  {
    cout<<"The stack is empty"<<endl;
    return ;
  }

  cout<<"The stack is: ";
  this->print();
}
