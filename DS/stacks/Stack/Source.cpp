#include<iostream>
using namespace std;
struct stack
{
	int top;
	char *ptr;
	int size;
};
class s
{
	struct stack st;
public:
	s();
	~s();
	void push(char);
	bool isFull();
	bool isEmpty();
	char pop();
	char peek();
	void getsize(int,char*);
	void display();
};
s::~s()
{
	cout << "adsd";
}
s::s()
{
	st.top = -1;
	st.ptr = NULL;
	st.size = 0;
}
void s::getsize(int n,char *str)
{
	st.ptr = new char[n+1];
	st.size = n;
	strcpy_s(st.ptr,n+1,str);
}
void s::push(char i)
{
	if (!isFull())
		st.ptr[++st.top] = i;
	else
		cout << "Stack Overflow";
}
char s::pop()
{
	if (!isEmpty())
		return (st.ptr[st.top--]);
	else
		return -100;
}
char s::peek()
{
	if (!isEmpty())
		return (st.ptr[st.top]);
	else
		return -100;
}
bool s::isFull()
{
	if (st.top == st.size - 1)
		return true;
	else
		return false;
}
bool s::isEmpty()
{
	if (st.top == -1)
		return true;
	else
		return false;
}
void s::display()
{
	for (int i = 0;i <= st.top;i++)
		cout << " " << st.ptr[i] << " ";
}
int main()
{
	s obj;
	int n, e;
	char *str;
	str = new char[15];
	cout << "enter the string" << endl;
	cin >> str;
	n = strlen(str);
	obj.getsize(n, str);
	for (int i = 0;i < n;i++)
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
		default:cout << "Done";
			break;



		}
	}
		if (obj.isEmpty())
		{
			cout << "blanced";
		}
		else
			cout << "not";
		getchar();
		getchar();

	}
