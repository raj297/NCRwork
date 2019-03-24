#define max_Len 50
#include<iostream>
#include<stack>
#include "character_stack.h"
#include "InfixToPostfix.h"
#include "PostfixEval.h"
#include "InputValidation.h"
#include<string.h>
using namespace std;
int Is_valid(char *input) {
	if (paranthesis_check(input) && chars_validity(input) && operator_validity(input)) 
	{
		return 1;
	}
//	cout <<paranthesis_check(input)<< "    " << chars_validity(input) << "          " << operator_validity(input);
	return 0;
}



int main()
{

	char input_expr[max_Len],y_toContinue='y';

	while ('y' == y_toContinue) 
	{
		cout << "Enter the expression:"<<endl;
		cin >> input_expr;

		if (Is_valid(input_expr)) 
		{
			cout << InfixToPostfix(input_expr) << endl;
			cout << "result =  " << Postfix_Eval(InfixToPostfix(input_expr)) << endl;
		}
		else
			cout << "Enter a valid expression" << endl;

		cout << "Press 'y' to continue anyother to exit:";
		cin >> y_toContinue;	
	}
	return 0;
}