#include "IntListNode.h"

IntListNode::IntListNode(const int &info)
  :data(info), nextPtr(0)
{

}

int IntListNode::getData() const
{
  return data;
}
