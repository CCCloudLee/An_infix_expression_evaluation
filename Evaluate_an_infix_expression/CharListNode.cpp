#include "CharListNode.h"

CharListNode::CharListNode(const char &info)
  :data(info), nextPtr(0)
{

}

char CharListNode::getData() const
{
  return data;
}
