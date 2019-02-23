#include<iostream>

using namespace std;

struct node {

	int data;
	struct node *next;

};

class List {

	struct node *start;


public:
	List() {
		start = NULL;
	}

	/*~List() {
		struct node *temp;
		while (start != NULL) {
			temp = start;
			start = start->next;
			delete(temp);
		}
	}*/
	void insertFirst(int);
	void insertLast(int);
	void insertAfter(int, int);
	void insertBefore(int, int);
	struct node* getMin();
	List merge(List, List);
	int deleteFirst();
	int deleteLast();
	void deleteSpec(int);
	void dispBwd();
	void dispFwd();
	void reverse();

};
List List::merge(List l1, List l2)
{
	List l3;
	while (l1.start!= NULL && l2.start != NULL)
	{
		cout << "sasas";
		int ele1 = l1.getMin()->data;
		int ele2 =l2.getMin()->data;
		if (ele1 <= ele2)
		{
			l3.insertLast(ele1);
			l1.deleteSpec(ele1);
		}
		else {
			l3.insertLast(ele2);
			l2.deleteSpec(ele2);
		}
	}
	if (l1.start != NULL)
	{
		
		while (l1.start != NULL)
		{
			cout << "sasas1";
			int ele1 = l1.getMin()->data;
			l3.insertLast(ele1);
			l1.deleteSpec(ele1);
		}
	}
	if (l2.start != NULL)
	{
		
		while (l2.start != NULL)
		{
			cout << "sasas2";
			int ele2 = l2.getMin()->data;
			l3.insertLast(ele2);
			l1.deleteSpec(ele2);
		}
	}
	return l3;
}
void List::reverse()
{
	struct node *cur = start, *pre = NULL, *suc;
	while (cur != NULL)
	{
		suc = cur->next;
		cur->next = pre;
		pre = cur;
		cur = suc;

	}
	start = pre;
}
struct node* List::getMin()
{
	struct node *tcur=this->start,*temp=this->start;
	cout << endl<<"iam in getmin"<<endl;
	if (this->start != NULL)
	{
		int e =this->start->data;
		while (tcur != NULL)
		{
			cout << "sasas2000";
			if (tcur->data < e)
			{
				temp = tcur;
			break;
			}
				tcur = tcur->next;
		}
		
	}
	if(temp!=NULL)
	cout << endl << "iam in getmin" <<temp->data<< endl;

	return temp;
}
void List::insertFirst(int e) {
	struct node *temp;
	temp = new node;
	temp->data = e;
	temp->next = start;
	start = temp;
}

void List::insertLast(int e) {
	struct node *cur = start;
	struct node *temp;
	temp = new node;
	temp->data = e;
	temp->next = NULL;
	if (start == NULL) {
		start = temp;
	}
	else {
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = temp;
	}
}

void List::insertAfter(int s, int e) {

	if (start != NULL) {
		struct node *cur = start;
		while (cur != NULL && cur->data != s)
			cur = cur->next;
		if (cur != NULL) {
			struct node *temp;
			temp = new node;
			temp->data = e;
			temp->next = cur->next;
			cur->next = temp;
		}
		else
			cout << "element not found";
	}
	else
		cout << "list is empty";
}

void List::insertBefore(int s, int e) {

	if (start != NULL) {
		if (start->data == e) {
			struct node *temp;
			temp = new node;
			temp->data = e;
			temp->next = start;
			start = temp;
		}
		else {
			struct node *cur = start;
			while (cur->next != NULL && cur->next->data != s)
				cur = cur->next;
			if (cur->next != NULL) {
				struct node *temp;
				temp = new node;
				temp->data = e;
				temp->next = cur->next;
				cur->next = temp;
			}
			else
				cout << "element not found";
		}
	}
	else
		cout << "list is empty";
}

int List::deleteFirst() {
	int x = -999;
	if (start != NULL) {
		x = start->data;
		struct node *temp = start;
		start = start->next;
		delete(temp);
	}
	else
		cout << "list is empty";
	return x;
}


int List::deleteLast() {

	int x = -999;

	if (start != NULL) {
		if (start->next != NULL) {
			struct node *cur = start;
			while (cur->next->next != NULL) {
				cur = cur->next;
			}
			x = cur->next->data;
			delete(cur->next);
			cur->next = NULL;
		}
		else {
			x = start->data;
			delete(start);
			start = NULL;
		}
	}
	else
		cout << "list is empty";

	return x;
}

void List::deleteSpec(int s) {
	if (this->start != NULL) {
		if (start->data == s) {
			struct node *temp = start;
			start = start->next;
			delete(temp);
		}
		else {
			struct node *temp, *cur = start;
			while (cur->next != NULL && cur->next->data != s)
				cur = cur->next;
			if (cur->next != NULL) {
				temp = cur->next;
				cur->next = cur->next->next;
				delete(temp);
			}
			else
				cout << "element not found";
		}
	}
	else
		cout << "list is empty delspec";
}


void List::dispFwd() {
	struct node *cur = start;
	while (cur != NULL) {
		cout << cur->data << " -> ";
		cur = cur->next;
	}	cout << endl;
}

void List::dispBwd() {
	static struct node *cur = start;
	int e;
	if (cur == NULL)
		return;
	e = cur->data;
	cur = cur->next;
	List::dispBwd();
	cout << e << " -> ";
}




int main() {



	List l1,l2,l3;
	cout << endl << "INSERTING" << endl;
	l1.insertFirst(10);
	l1.insertFirst(2);
	l1.insertFirst(3);
	l1.insertFirst(54);
	l1.dispFwd();
	l2.insertLast(75);
	l2.insertLast(65);
	l2.insertLast(75);
	l2.insertLast(84);
	l2.dispFwd();
	l3.merge(l1, l2);
	l3.dispFwd();
	cout << endl;
	getchar();
	return 0;
}