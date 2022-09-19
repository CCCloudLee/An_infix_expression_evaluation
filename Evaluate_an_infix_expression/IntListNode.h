#ifndef INTLISTNODE_H
#define INTLISTNODE_H


class IntListNode
{
    friend class IntList;
  public:
    IntListNode(const int&);
    int getData() const;

  protected:
    int data;
    IntListNode *nextPtr;
};

#endif
