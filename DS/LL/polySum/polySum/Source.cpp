#include<iostream>
using namespace std;
struct node
{
	int data;
	int power;
	struct node *next;
};
class list
{
	struct node *start;
public:
	list()
	{

		start = NULL;
	}
	void insertFirst(int e, int pow);
	void insertLast(int e, int pow);

	friend void add(list, list);

	void disFwd();
	
};
void list::insertFirst(int e, int pow) {
	struct node *temp;
	temp = new node;
	temp->next = start;
	temp->data = e;
	temp->power = pow;
	start = temp;
}
void list::insertLast(int e, int pow) {
	struct node *temp, *cur;
	temp = new node;
	temp->data = e;
	temp->power = pow;
	cur = start;
	if (start != NULL)
	{

		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = temp;

	}
	else
		start = temp;
	temp->next = NULL;
}
void list::disFwd()
{
	struct node *cur;
	cur = start;
	while (cur != NULL)
	{

		cout << cur->data << "x^" << cur->power;
		if (cur->power != 0)
			cout << "+";
		cur = cur->next;
	}
	cout << endl;
}
void  add(list l1, list l2)
{
	struct node *c1 = l1.start;
	struct node *c2 = l2.start;
	list l3;

	while ((c1 != NULL && c2 != NULL))
	{
		if (c1->power == c2->power) {
			l3.insertLast(c1->data + c2->data, c1->power);
			c1 = c1->next;
			c2 = c2->next;
		}
		else if (c1->power > c2->power)
		{
			l3.insertLast(c1->data, c1->power);
			c1 = c1->next;
		}
		else if (c1->power < c2->power)
		{
			l3.insertLast(c2->data, c2->power);
			c2 = c2->next;
		}
	}
	
	l3.disFwd();
}



int main()
{
	list l1, l2; 

	l1.insertFirst(5, 3);
	//l1.insertFirst(4, 2);
	l1.insertLast(3, 1);
	l1.insertLast(4, 0);
	//l2.insertFirst(5, 3);
	l2.insertFirst(4, 2);
	l2.insertLast(3, 1);
	l2.insertLast(4, 0);
	l1.disFwd();
	l2.disFwd();
	add(l1, l2);

	
	getchar();
	return 0;
}