#include "IntList.h"
#include "IntListNode.h"
#include <iostream>
#include <new>
using namespace std;

IntList::IntList()
  :firstPtr(0), lastPtr(0)
{

}

IntList::~IntList()
{
  if(!isEmpty())
  {
    cout<<"Destroying nodes ..."<<endl;
    IntListNode *currentPtr=firstPtr;
    IntListNode *tempPtr;

    while(currentPtr!=0)
    {
      tempPtr=currentPtr;
      cout<<tempPtr->data<<endl;
      currentPtr=currentPtr->nextPtr;
      delete tempPtr;
    }
  }
  cout<<"All nodes destroyed."<<endl<<endl;
}

void IntList::insertAtFront(const int &value)
{
  IntListNode *newPtr=getNewNode(value);

  if (isEmpty())
    firstPtr=lastPtr=newPtr;
  else
  {
    newPtr->nextPtr=firstPtr;
    firstPtr=newPtr;
  }
}

void IntList::insertAtBack(const int &value)
{
  IntListNode *newPtr=getNewNode(value);

  if(isEmpty())
    firstPtr=lastPtr=newPtr;
  else
  {
    lastPtr->nextPtr=newPtr;
    lastPtr=newPtr;
  }
}

bool IntList::removeFromFront(int &value)
{
  if(isEmpty())
    return false;
  else
  {
    IntListNode *tempPtr=firstPtr;
    if(firstPtr==lastPtr)
        firstPtr=lastPtr=0;
    else
      firstPtr=firstPtr->nextPtr;

    value=tempPtr->data;
    delete tempPtr;
    return true;
  }
}

bool IntList::removeFromBack(int &value)
{
  if(isEmpty())
    return false;
  else
  {
    IntListNode *tempPtr=lastPtr;
    if(firstPtr==lastPtr)
      firstPtr=lastPtr=0;
    else
    {
      IntListNode *currentPtr=firstPtr;
      while(currentPtr->nextPtr!=lastPtr)
          currentPtr=currentPtr->nextPtr;
      lastPtr=currentPtr;
      currentPtr->nextPtr=0;
    }

    value=tempPtr->data;
    delete tempPtr;
    return true;
  }
}

bool IntList::isEmpty() const
{
  return (firstPtr==0);
}

IntListNode* IntList::getNewNode(const int &value)
{
  return new IntListNode (value);
}

void IntList::print() const
{
  if(isEmpty())
  {
    cout<<"The list is empty."<<endl<<endl;
    return;
  }
  else
  {
    IntListNode *currentPtr=firstPtr;
    while(currentPtr!=0)
    {
      cout<<currentPtr->data<<" ";
      currentPtr=currentPtr->nextPtr;
    }
    cout<<endl;
  }
}
