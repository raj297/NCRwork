
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
class dlist
{
	struct node *start;
public:
	dlist()
	{
		start = NULL;
	}
	void insertFirst(int e);
	void insertLast(int e);
	void insertAfter(int e, int k);
	void insertBefore(int e, int k);
	int deleteFirst();
	int deleteLast();
	void deleteSpecific(int e);

	void disFwd();
	void disBwd();
	~dlist();
};
void dlist::insertFirst(int e) {
	struct node *temp;
	temp = new node;
	temp->data = e;
    if(start!=NULL)
	start->prev=temp;
	
	temp->next = start;

	temp->prev=NULL;

	start = temp;
}
void dlist::insertLast(int e) {
	struct node *temp, *cur;
	temp = new node;
	temp->data = e;
	if (start != NULL)
	{
		cur = start;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		temp->prev=cur;
		cur->next = temp;
		temp->next = NULL;
	}
}
void dlist::disFwd()
{
	struct node *cur;
	cur = start;
	while (cur != NULL)
	{
		cout << cur->data << "--->";
		cur = cur->next;
	}
	cout << endl;
}
void dlist::disBwd()
{
	struct node *cur;
	cur = start;
	while (cur->next != NULL)
	{
		
		cur = cur->next;
	}
	while (cur!= NULL)
	{
		cout << cur->data << "--->";
		cur = cur->prev;
	}
	
	cout << endl;
}
void dlist::insertAfter(int e, int k)
{
	struct node *cur, *temp;
	cur = start;
	if (start != NULL)
	{
		while (cur != NULL&&cur->data != k)
		{
			cur = cur->next;
		}
		if (cur != NULL)
		{
			temp = new node;
			temp->data = e;
			temp->next = cur->next;
			temp->prev=cur;
			cur->next = temp;
		}
		else
			cout << endl << "no such element" << endl;
	}
	else
		cout << endl << "List empty" << endl;

}
void dlist::insertBefore(int e, int k)
{
	struct node *cur, *temp;
	cur = start;


	if (start != NULL)
	{
		if (start->data == k)
		{
			temp = new node;
			temp->next = start;
			start = temp;
			temp->data;
		}
		else
		{
			while (cur->next != NULL &&cur->next->data != k)
			{
				cur = cur->next;
			}
			if (cur->next != NULL)
			{
				temp = new node;
				temp->next = cur->next;
				cur->next = temp;
				temp->prev=cur;
				temp->data = e;
			}
			else
				cout << endl << "no such eele" << endl;
		}


	}
	else
		cout << endl << "no list" << endl;

}
int dlist::deleteFirst()
{
	struct node *temp;
	int e = -1;
	if (start != NULL)
	{
		temp = start;
	
		start = start->next;
		start->prev=NULL;
		e = temp->data;
		delete temp;
	}
	return e;
}
int dlist::deleteLast()
{
	int e = -1;
	struct node *temp, *cur;

	if (start != NULL)
	{
		cur = start;
	
		while (cur->next != NULL)
		{
			
			cur = cur->next;

		}
		temp = cur;
	temp->prev->next=NULL;

		e = temp->data;
		delete temp;
	}

	return e;

}
void dlist::deleteSpecific(int e) {
	struct node *cur, *temp;
	cur = start;


	if (start != NULL)
	{
		if (start->data == e)
		{
			temp = start;
			start = NULL;
			delete temp;

		}
		else
		{
			while (cur!= NULL &&cur->data != e)
			{
				cur = cur->next;
			}
			if (cur != NULL)
			{
				temp = cur;
				cur->prev->next= temp->next;
				temp->next->prev=cur->prev;
				delete temp;
			}
			else
				cout << endl << "no such eele" << endl;
		}


	}
	else
		cout << endl << "no list" << endl;

}

dlist ::~dlist()
{
	struct node *cur, *temp;
	cur = start;
	while (cur != NULL)
	{
		temp = cur;
		cur = cur->next;
		delete temp;
	}
	start = NULL;
	cout << "DONe";
}
int main()
{
	dlist l;int e;

	l.insertFirst(2);
	l.insertFirst(1);
	l.insertFirst(0);
	l.insertLast(3);
	l.insertLast(4);
	
	l.insertAfter(5, 4);

	l.insertBefore(5, 3);

	l.deleteSpecific(5);

	l.disFwd();

	
	l.disBwd();
	getchar();
}