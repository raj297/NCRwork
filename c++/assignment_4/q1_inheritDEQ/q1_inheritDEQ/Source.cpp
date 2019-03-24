#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
class deQ
{
	struct node *front, *rear;
public:
	int size = 0;
	deQ()
	{
		front = NULL;
		rear = NULL;
	}
	void enQ_front(int e);
	void enQ_last(int e);
	int deQ_first();
	int deQ_last();
	void disFwd();
	void disBwd();
	~deQ();
};
void deQ::enQ_front(int e) {
	struct node *temp;
	temp = new node;
	temp->data = e;
	if (front != NULL)
	{
		front->prev = temp;

		temp->next = front;
		temp->prev = NULL;
		front = temp;

	}
	else {

		temp->next = front;

		temp->prev = NULL;

		front = temp;
		rear = temp;
	}
}
void deQ::enQ_last(int e) {
	struct node *temp, *cur;
	temp = new node;
	temp->data = e;
	if (front != NULL)
	{
		cur = front;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		temp->prev = cur;
		cur->next = temp;
		temp->next = NULL;
		rear = temp;
	}
	else
	{
		front = temp;
		rear = temp;
	}

}
void deQ::disFwd()
{
	struct node *cur;
	cur = front;
	if (front != NULL)
		while (cur != NULL)
		{
			cout << cur->data << "--->";
			cur = cur->next;
		}
	else
		cout << "nothing to display";
	cout << endl;
}
void deQ::disBwd()
{
	struct node *cur;
	cur = front;
	if (front != NULL) {
		while (cur->next != NULL)
		{

			cur = cur->next;
		}
		while (cur != NULL)
		{
			cout << cur->data << "--->";
			cur = cur->prev;
		}
	}
	else
		cout << "nothing to Display";
	cout << endl;
}
int deQ::deQ_first()
{
	cout << "in deq";
	struct node *temp;
	int e = -1;
	if (front != NULL)
	{
		temp = front;
		front = front->next;
		front->prev = NULL;
		e = temp->data;
		delete temp;
	}
	else
		cout << "NO eles " << endl;

	return e;
}
int deQ::deQ_last()
{
	int e = -1;
	struct node *temp, *cur;

	if (front != NULL)
	{
		cur = front;

		while (cur->next != NULL)
		{

			cur = cur->next;

		}
		temp = cur;
		temp->prev->next = NULL;

		e = temp->data;
		delete temp;
	}
	else
		cout << "NO eles in Queue" << endl;

	return e;

}
deQ ::~deQ()
{
	struct node *cur, *temp;
	cur = front;
	while (cur != NULL)
	{
		temp = cur;
		cur = cur->next;
		delete temp;
	}
	front = NULL;
	cout << "DONe";
}
class stack :private deQ
{
	int size_Count = 0;
public:
	bool isEmpty()
	{
		if (size_Count == 0)
			return true;
		else
			return false;

	}
	bool isFull()
	{
		if (size_Count == size)
			return true;
		else
			return false;

	}
	void getSize()
	{
		cout << "enter thhe stack size req." << endl;
		cin >> size;
	}
	void stack_disFwd()
	{
		disFwd();
	}
	int pop()
	{
		//cout << "Stack POp";
		if (!isEmpty())
		{
			size_Count--;
		//	cout << "innn" << endl;
			// cout<< deQ_last()<<"whoo"<<endl;
		}
		else {
			cout << "Underflow" << endl;
		}
		return 1;

	}
	void push(int element)
	{

		if (!isFull())
		{
			size_Count++;
			enQ_front(element);
		}
		else
			cout << "Overflow" << endl;
	}

};
int main()
{
	deQ l;
	stack s;
	int e = 1, ch = 0;
	s.getSize();
	while (1)
	{

		cout << "enter the choice \n 1.push \n 2.pop \n 3.display\n 4.exit" << endl;
		cin >> ch;

		switch (ch)
		{

		case 1:
			cout << "enter the ele" << endl;
			cin >> e;
			s.push(e);
			break;
		case 2:
			//cout << "in Switch pop";
			cout << s.pop();
			break;

		case 3:
			s.stack_disFwd();
			break;

		case 4:
			exit(0);
			break;
		default:
			cout << "im i a joke to you!!!";
			break;

		}

	}
	getchar();
}