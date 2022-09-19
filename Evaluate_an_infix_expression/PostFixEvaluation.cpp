#include "PostFixEvaluation.h"
#include "IntStack.h"
#include "InFixToPostFix.h"
#include <cmath>
using namespace std;

PostFixEvaluation::PostFixEvaluation(InFixToPostFix k)
{
  postFix=k.getPostFix();
}

PostFixEvaluation::~PostFixEvaluation()
{

}

int PostFixEvaluation::EvaluatePostFix()
{
  IntStack intStack;
  int answer, n1, n2;
  for (int i=0; postFix[i]!='\0'; i++)
  {
    if(isDigit(postFix[i]))
      intStack.push(postFix[i]-'0');
    else
    {
      intStack.pop(n1);
      intStack.pop(n2);
      intStack.push(calculate(n1, n2, postFix[i]));
    }
  }
  intStack.pop(answer);
  return answer;
}

bool PostFixEvaluation::isDigit(char c)
{
  if(c>='0' && c<='9')
    return true;
  else
    return false;
}

int PostFixEvaluation::calculate(int op1, int op2, char oper)
{
  int answer=0;
  switch(oper)
  {
    case '+':
      answer=op2+op1;
      break;
    case '-':
      answer=op2-op1;
      break;
    case '*':
      answer=op2*op1;
      break;
    case '/':
      answer=op2/op1;
      break;
    case '^':
      answer=pow(op2, op1);
      break;
    case '%':
      answer=op2%op1;
      break;
  }
  return answer;
}
