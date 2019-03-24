#pragma once
#include "character_stack.h"
#include<string.h>
int paranthesis_check(char *str) {
	int i;
	charStack obj;
	int n=strlen(str), e;
	for (int i = 0; i < n; i++)
	{

		char ch = str[i];
		switch (ch) {
		case '(':
			obj.push(ch);
			break;
		case '{':
			obj.push(ch);
			break;
		case '[':
			obj.push(ch);
			break;
		case ')':
			if (!obj.isEmpty() && obj.peek() == '(')
			{
				obj.pop();

			}
			else
				obj.push(ch);
			break;
		case '}':if (!obj.isEmpty() && obj.peek() == '{')
		{
			obj.pop();

		}
				 else
			obj.push(ch);
			break;
		case ']':
			if (!obj.isEmpty() && obj.peek() == '[')
			{
				obj.pop();

			}
			else
				obj.push(ch);
			break;


		}
	}
	if (obj.isEmpty())
	{
	//	cout << "blanced";
		return 1;
	}
	else
	{	
		//	cout << "not";
	return 0;
	}

}

int chars_validity(char *input) {
	for (int i = 0; i < strlen(input); i++)
	{
		if (isdigit(input[i]) || (input[i] >= 42 && input[i] <= 47) || input[i] == ' ' || input[i] == ')' || input[i] == '(')
		{
			
			if (input[i] == '(')
			{
				if (input[i + 1] == ')')
					return 0;
			}
			continue;
		}
		else
			return 0;
	}

	return 1;
}

int operator_validity(char *input)
{

	int op_Left = 0, op_Right = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] >= 42 && input[i] <= 47)
		{
			//if operator at the begining itself (but this will disallow the -ve no.s)
			if (i - 1 >= 0)
				op_Left = i - 1;
			else
				return 0;
			if (i + 1 < strlen(input))
				op_Right = i + 1;
			else
				return 0;
			/*while (input[op_Left] != ' ')
				op_Left--;
			while (input[op_Right] != ' ')
				op_Right++;*/
			// case:()+2
			if (input[op_Left] == ')' || isdigit((input[op_Left])))
				continue;
			else
				return 0;
			//case: 2+()
			if (input[op_Right] == '(' || isdigit((input[op_Right])))
				continue;
			else
				return 0;
		}
		else
			continue;
	
	}

	return 1;
}
