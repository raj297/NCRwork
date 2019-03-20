#include<stack> 
#include<iostream>
int add(int a, int b);
int mul(int a, int b);
int divi(int a, int b);
int sub(int a, int b);
using namespace std;
int eval(char *);
//Function to return precedence of operators 
int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// The main function to convert infix expression 
//to postfix expression 
void infixToPostfix(string s)
{
	std::stack<char> st;
	st.push('N');
	int l = s.length();
	string ns;
	for (int i = 0; i < l; i++)
	{
		// If the scanned character is an operand, add it to output string. 
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			ns += s[i];

		// If the scanned character is an ‘(‘, push it to the stack. 
		else if (s[i] == '(')

			st.push('(');

		// If the scanned character is an ‘)’, pop and to output string from the stack 
		// until an ‘(‘ is encountered. 
		else if (s[i] == ')')
		{
			while (st.top() != 'N' && st.top() != '(')
			{
				char c = st.top();
				st.pop();
				ns += c;
			}
			if (st.top() == '(')
			{
				char c = st.top();
				st.pop();
			}
		}

		//If an operator is scanned 
		else {
			while (st.top() != 'N' && prec(s[i]) <= prec(st.top()))
			{
				char c = st.top();
				st.pop();
				ns += c;
			}
			st.push(s[i]);
		}

	}
	//Pop all the remaining elements from the stack 
	while (st.top() != 'N')
	{
		char c = st.top();
		st.pop();
		ns+= c;
	}

	//cout << ns << endl;

}

//Driver program to test above functions 
int main()
{
	char *exp = "1+2*8";
	infixToPostfix(exp);
	eval(exp);
	getchar();
	return 0;
}

// Stack type  
struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

// Stack Operations  
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

	if (!stack) return NULL;

	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));

	if (!stack->array) return NULL;

	return stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}

void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}


// The main function that returns value of a given postfix expression  
int evaluatePostfix(char* exp)
{
	// Create a stack of capacity equal to expression size  
	struct Stack* stack = createStack(strlen(exp));
	int i;

	// See if stack was created successfully  
	if (!stack) return -1;

	// Scan all characters one by one  
	for (i = 0; exp[i]; ++i)
	{
		// If the scanned character is an operand (number here),  
		// push it to the stack.  
		if (isdigit(exp[i]))
			push(stack, exp[i] - '0');

		// If the scanned character is an operator, pop two  
		// elements from stack apply the operator  
		else
		{
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (exp[i])
			{
			case '+': push(stack,add( val2 ,val1)); break;
			case '-': push(stack, sub(val2 , val1)); break;
			case '*': push(stack, mul(val2 , val1)); break;
			case '/': push(stack, divi(val2 , val1)); break;
			}
		}
	}
	return pop(stack);
}

// Driver program to test above functions  
int eval(char *exp)
{

	cout << "postfix evaluation: " << evaluatePostfix(exp);
	return 0;
}