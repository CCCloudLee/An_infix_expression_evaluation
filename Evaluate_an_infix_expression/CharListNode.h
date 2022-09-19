#ifndef CHARLISTNODE_H
#define CHARLISTNODE_H


class CharListNode
{
    friend class CharList;
  public:
    CharListNode(const char&);
    char getData() const;

  protected:
    char data;
    CharListNode *nextPtr;
};

#endif // CHARLISTNODE_H
