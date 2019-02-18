#include<iostream>
using namespace std;
struct stack
{
	int top;
	int *ptr;
	int size;
};
class s
{
	struct stack st;
public:
	s();
	~s();
	void push(int);
	bool isFull();
	bool isEmpty();
	int pop();
	int peek();
	void getsize(int);
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
void s::getsize(int n)
{
	st.ptr = new int[n];
	st.size = n;
}
void s::push(int i)
{
	if (!isFull())
		st.ptr[++st.top] = i;
	else
		cout << "Stack Overflow";
}
int s:: pop()
{
	if (!isEmpty())
		return (st.ptr[st.top--]);
	else
		return -100;
}
int s::peek()
{
	if (!isEmpty())
		return (st.ptr[st.top]);
	else
		return -100;
}
bool s:: isFull()
{
	if (st.top==st.size - 1 )
		return true;
	else
		return false;
}
bool s::isEmpty()
{
	if (  st.top==-1)
		return true;
	else
		return false;
}
void s::display()
{
	for (int i = 0;i <=st.top;i++)
		cout << " " << st.ptr[i] << " ";
}
int main()
{
	s obj;
	int n,e;
	cout << "enter the number of elements" << endl;
	cin >> n;
	obj.getsize(n);
	cout << "enter the elements" << endl;
	for (int i = 0;i < n;i++)
	{
		cin >> e;
		obj.push(e);
	}
	cout << "stack is ready::";
	obj.display();
	cout << endl;
	cout << "peek gives" << obj.peek()<<endl;
	cout << "poping the elements" << endl;
	while (!obj.isEmpty())
	{
		cout << obj.pop() << "  ";
	}
	getchar();
	getchar();

}