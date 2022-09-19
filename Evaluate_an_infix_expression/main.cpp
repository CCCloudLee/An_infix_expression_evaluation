#include <iostream>
#include <cstdlib>
#include "InFixToPostFix.h"
#include "PostFixEvaluation.h"
using namespace std;

int main()
{
  const int MAXSIZE = 1000;
  char c;
  char *inFix;
  inFix= new char [MAXSIZE];
  int pos = 0;
  int answer;

  cout << "Enter the infix expression.\n";

   // get input
  while ( ( c = static_cast< char >( cin.get() ) ) != '\n' )
    if ( c != ' ' )
      inFix[ pos++ ] = c;
  inFix[ pos ] = '\0';

  InFixToPostFix IFTPF(inFix);
  cout << "The original infix expression is:\n" << IFTPF.getInFix() << '\n';
  IFTPF.convertToPostfix();
  cout << "The expression in postfix notation is:\n" << IFTPF.getPostFix() << endl;

  PostFixEvaluation PFE(IFTPF);
  answer=PFE.EvaluatePostFix();
  cout << "The value of the expression is: " << answer << endl;

  system("pause");
  return 0;
}
