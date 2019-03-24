#pragma once
#define max_len 50
#include "character_stack.h"
int GetPriority(char a) {

	switch (a) {

	case '(': 
		return 0;
	case ')': 
		return 0;
	case '+':
		return 1;
	case '-':
		return 1;
	case '/': 
		return 2;
	case '*': 
		return 2;

	}

}

char* InfixToPostfix(char *inputExpr) {

	charStack s;
	char *toPostFix= new char[max_len];
	int pos = 0;//pos iterates on toPostFix expr;

	for (int i = 0; i < strlen(inputExpr); i++)
	{

		if (inputExpr[i] == ' ')
			continue;

		else if (isdigit(inputExpr[i]))//if digit just add it to postfix expr
			toPostFix[pos++] = inputExpr[i];

		else if (inputExpr[i] == '(')
			s.push(inputExpr[i]);
		//if any operator we compare priority of TopOfStack and inputChar and  and then work
		else if (GetPriority(s.peek()) < GetPriority(inputExpr[i]))
		{
			//while coversion to postfix  if any digit occurs by using delimiter @ we can differentiate and use it incase of multidigits
			if (isdigit(toPostFix[pos-1]))
				toPostFix[pos++] = '@';
			//if TOS is less priority we push
			s.push(inputExpr[i]);
		}
		else {

			if (isdigit(toPostFix[pos-1]))
				toPostFix[pos++] = '@';
			//if TOS is greater or eequal priority we pop from stack put in the post Expr and then push the inputChar 
			while (GetPriority(inputExpr[i]) <= GetPriority(s.peek())) {
				//pushing to the postfix expr other than paranthesis
				if (s.peek() != '(' && s.peek() != ')') 
				    {
					toPostFix[pos++] = s.pop();
				     }
				else 
				    {
					s.pop();
				     }
				if (s.isEmpty())
					break;
			}

			s.push(inputExpr[i]);
		}
	}

	if (isdigit(toPostFix[pos-1]))
		toPostFix[pos++] = '@';
	//adding up to postFix Expr elements left in  stack
	while (!s.isEmpty())
		if (s.peek() != '(' && s.peek() != ')')
			toPostFix[pos++] = s.pop();
		else
			s.pop();

	toPostFix[pos] = '\0';

	return toPostFix;
}
