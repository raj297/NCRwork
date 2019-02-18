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
	int getPrio(char ch);
	void getsize(int, char*);
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
int s::getPrio(char ch) {

	switch (ch)
	{
	
	case '/':
		return 5;
	case '*':
		return 5;
	case '+':
		return 0;
	case '-':
		return 0;

	case '(':
		return -1;
		break;
	case ')':
		return -1;
		break;


	}
}
void s::getsize(int n, char *str)
{
	st.ptr = new char[n + 1];
	st.size = n;
	strcpy_s(st.ptr, n + 1, str);
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
	int n;
	char *str, ch;
	str = new char[20];
	cout << "enter the string" << endl;
	cin >> str;
	n = strlen(str);
	obj.getsize(n, str);

	for (int i = 0;i < n;i++)
	{
		ch = str[i];
		if (str[i] >= 'a'&&str[i] <= 'z')
			cout << str[i];
		else if (str[i] == '(')
			obj.push(str[i]);
		else
		{
			if (obj.isEmpty())
			{
				obj.push(ch);
			}
			else
			{
				char t;
				t = obj.peek();
				if (obj.getPrio(t) >=obj.getPrio(ch))
				{
					while (obj.getPrio(t) >= obj.getPrio(ch))
					{
						char po = obj.pop();
						if (po != '('&& po != ')')
							cout << po;
						t = obj.peek();
					}
				}
				else
					obj.push(ch);


			}
		}

	
	}
	
	while (!obj.isEmpty())
	{
		char po = obj.pop();
		if (po != '('&& po != ')')
			cout << po;
	}
	getchar();
	getchar();


}
