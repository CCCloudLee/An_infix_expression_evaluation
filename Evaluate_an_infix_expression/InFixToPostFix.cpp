#include "InFixToPostFix.h"
#include "CharStack.h"
#include <iostream>
#include <cstring>
using namespace std;

InFixToPostFix::InFixToPostFix(char *c)
{
  postFix=new char [1000];
  inFix=c;
}

InFixToPostFix::~InFixToPostFix()
{
  delete [] inFix;
  delete [] postFix;
}

void InFixToPostFix::convertToPostfix()
{
  CharStack charStack;
  int infixCount;
  int postfixCount;
  bool higher;
  char popValue;
  char leftParen = '(';

  // push a left paren onto the stack and add a right paren to infix
  charStack.push( leftParen );
  charStack.printStack();
  strcat( inFix, ")" );

  // convert the infix expression to postfix
  for ( infixCount = 0, postfixCount = 0; charStack.stackTop();infixCount++ )
  {
    if ( isDigit( inFix[ infixCount ] ) )
      postFix[ postfixCount++ ] = inFix[ infixCount ];
    else if ( inFix[ infixCount ] == '(' )
    {
      charStack.push( leftParen );
      charStack.printStack();
    } // end else if
    else if ( isOperator( inFix[ infixCount ] ) )
    {
      higher = true; // used to store value of precedence test

      while ( higher )
      {
        if ( isOperator( charStack.stackTop() ) )
        {
          if ( precedence( charStack.stackTop(),inFix[ infixCount ] ) )
          {
            charStack.pop(postFix[ postfixCount++ ]);
            charStack.printStack();
          } // end if
          else
            higher = false;
        } // end if
        else
          higher = false;
      } // end while

      charStack.push( inFix[ infixCount ] );
      charStack.printStack();
    } // end else if
    else if ( inFix[ infixCount ] == ')' )
    {
      while (charStack.pop(popValue) && popValue!='(' )
      {
        charStack.printStack();
        postFix[ postfixCount++ ] = popValue;
      } // end while

      charStack.printStack();
    } // end else if
  } // end for

  postFix[ postfixCount ] = '\0';
}

bool InFixToPostFix::isOperator( char c )
{
   if ( c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' )
      return true;
   else
      return false;
}

bool InFixToPostFix::isDigit( char c )
{
  if (c>='0' && c<='9')
    return true;
  else
    return false;
}

bool InFixToPostFix::precedence( char operator1, char operator2 )
{
   if ( operator1 == '^' )
      return true;
   else if ( operator2 == '^' )
      return false;
   else if ( operator1 == '*' || operator1 == '/' || operator1 == '%' )
      return true;
   else if ( operator1 == '+' || operator1 == '-' )
   {
      if ( operator2 == '*' || operator2 == '/' || operator2 == '%' )
         return false;
      else
         return true;
   }

   return false;
}

char* InFixToPostFix::getInFix() const
{
  return inFix;
}

char* InFixToPostFix::getPostFix() const
{
  return postFix;
}
