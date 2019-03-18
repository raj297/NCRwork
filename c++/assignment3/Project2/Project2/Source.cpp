#include<iostream>
using namespace std;
struct stack
{
	int top;
	char *ptr;
	int size;
};
template <class t>
class s
{

public:
	struct stack st;

	s();
	~s();
	void push(int);
	bool isFull();
	bool isEmpty();
	t pop();
	t peek();
	void getsize(int);
	void display();
};
template <class t>
s<t>::~s()
{
	cout << "adsd";
}
template <class t>
s<t>::s()
{
	st.top = -1;
	st.ptr = NULL;
	st.size = 0;
}
template <class t>
void s<t>::getsize(int n)
{
	st.ptr = new t[n];
	st.size = n;
}
template <class t>
void s<t>::push(int i)
{
	if (!isFull())
		st.ptr[++st.top] = i;
	else
		cout << "Stack Overflow";
}
template <class t>
t s<t>::pop()
{
	if (!isEmpty())
		return (st.ptr[st.top--]);
	else
		return -100;
}
template <class t>
t s<t>::peek()
{
	if (!isEmpty())
		return (st.ptr[st.top]);
	else
		return -100;
}
template <class t>
bool s<t>::isFull()
{
	if (st.top == st.size - 1)
		return true;
	else
		return false;
}
template <class t>
bool s<t>::isEmpty()
{
	if (st.top == -1)
		return true;
	else
		return false;
}
template <class t>
void s<t>::display()
{
	for (int i = 0; i <= st.top; i++)
		cout << " " << st.ptr[i] << " ";
}
int main()
{
	s<char> obj;
	int n, e;
	cout << "enter the number of elements" << endl;
	cin >> n;
	obj.getsize(n);
	cout << "enter the elements" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> e;
		obj.push(e);
	}
	cout << "stack is ready::";
	obj.display();
	cout << endl;
	cout << "peek gives" << obj.peek() << endl;
	cout << "poping the elements" << endl;
	while (!obj.isEmpty())
	{
		cout << obj.pop() << "  ";
	}
	getchar();
	getchar();

}