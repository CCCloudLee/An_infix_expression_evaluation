#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#include "CharStack.h"
using namespace std;

class InFixToPostFix
{
  public:
    InFixToPostFix(char*);
    ~InFixToPostFix();
    void convertToPostfix();
    bool isOperator( char );
    bool isDigit( char );
    bool precedence( char, char );
    char* getInFix() const;
    char* getPostFix() const;
  private:
    char *inFix, *postFix;
};

#endif // INFIXTOPOSTFIX_H
