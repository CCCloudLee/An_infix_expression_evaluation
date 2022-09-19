#include "CharList.h"
#include "CharListNode.h"
#include <iostream>
#include <new>
using namespace std;

CharList::CharList()
  :firstPtr(0), lastPtr(0)
{

}

CharList::~CharList()
{
  if(!isEmpty())
  {
    cout<<"Destroying nodes ..."<<endl;
    CharListNode *currentPtr=firstPtr;
    CharListNode *tempPtr;

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

void CharList::insertAtFront(const char &value)
{
  CharListNode *newPtr=getNewNode(value);

  if (isEmpty())
    firstPtr=lastPtr=newPtr;
  else
  {
    newPtr->nextPtr=firstPtr;
    firstPtr=newPtr;
  }
}

void CharList::insertAtBack(const char &value)
{
  CharListNode *newPtr=getNewNode(value);

  if(isEmpty())
    firstPtr=lastPtr=newPtr;
  else
  {
    lastPtr->nextPtr=newPtr;
    lastPtr=newPtr;
  }
}

bool CharList::removeFromFront(char &value)
{
  if(isEmpty())
    return false;
  else
  {
    CharListNode *tempPtr=firstPtr;
    if(firstPtr==lastPtr)
        firstPtr=lastPtr=0;
    else
      firstPtr=firstPtr->nextPtr;

    value=tempPtr->data;
    delete tempPtr;
    return true;
  }
}

bool CharList::removeFromBack(char &value)
{
  if(isEmpty())
    return false;
  else
  {
    CharListNode *tempPtr=lastPtr;
    if(firstPtr==lastPtr)
      firstPtr=lastPtr=0;
    else
    {
      CharListNode *currentPtr=firstPtr;
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

bool CharList::isEmpty() const
{
  return (firstPtr==0);
}

CharListNode* CharList::getNewNode(const char &value)
{
  return new CharListNode (value);
}

void CharList::print() const
{
  if(isEmpty())
  {
    cout<<"The list is empty."<<endl<<endl;
    return;
  }
  else
  {
    CharListNode *currentPtr=firstPtr;
    while(currentPtr!=0)
    {
      cout<<currentPtr->data<<" ";
      currentPtr=currentPtr->nextPtr;
    }
    cout<<endl;
  }
}
