#ifndef POSTFIXEVALUATION_H
#define POSTFIXEVALUATION_H

#include "InFixToPostFix.h"

class PostFixEvaluation
{
  public:
    PostFixEvaluation(InFixToPostFix);
    ~PostFixEvaluation();
    int EvaluatePostFix();

  private:
    char *postFix;
    bool isDigit(char);
    int calculate(int, int, char);
};

#endif
