#pragma once
#include "functions.h";
#include<iostream>
#include<stack>
#include<string.h>
//call to external functions
int operation(int op1, int op2, char operator1) {

	switch (operator1) {
	case '*':
		return Multiply(op1, op2);
	case '/':
		return Divide(op1, op2);
	case '+':
		return Add(op1, op2);
	case '-':
		return Subtract(op1, op2);

	}

}

int Postfix_Eval(char *postFix_expr) {
	//use of stack from stl 
	stack<int> s;
	int top_op1=0, top_op2=0, sum=0, base=1;
	int result = 0;
	for (int i = 0; i < strlen(postFix_expr); i++) 
	{
		if (postFix_expr[i] >= 42 && postFix_expr[i] <= 47) //ascii range of all operators
		{
			top_op2 = s.top();
			s.pop();
			top_op1 = s.top();
			s.pop();
			s.push(operation(top_op1, top_op2, postFix_expr[i]));
		}
		else
		{
			//now generating the numbers using the delimiters
			sum = 0, base = 10;
			//starts from one delemiter
			while (postFix_expr[i] != '@') 
			{
				sum = sum * base + (postFix_expr[i] - '0');
				i++;
				//till another delimiter encouters
				
			}
			//pushing finally the converted NUMBER
			
			s.push(sum);
		}
	}
	result= s.top();
	return result;
}


