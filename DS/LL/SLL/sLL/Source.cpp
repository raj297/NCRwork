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

	~List() {
		struct node *temp;
		while (start != NULL) {
			temp = start;
			start = start->next;
			delete(temp);
		}
	}
	void insertFirst(int);
	void insertLast(int);
	void insertAfter(int, int);
	void insertBefore(int, int);

	int deleteFirst();
	int deleteLast();
	void deleteSpec(int);

	void dispBwd();
	void dispFwd();
	void reverse();

};
void List::reverse()
{
	struct node *cur=start, *pre=NULL, *suc;
	while (cur != NULL)
	{
		suc = cur->next;
		cur->next = pre;
		pre = cur;
		cur = suc;
		
	}
	start = pre;
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
	if (start != NULL) {
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
		cout << "list is empty";
}


void List::dispFwd() {
	struct node *cur = start;
	while (cur != NULL) {
		cout << cur->data << " -> ";
		cur = cur->next;
	}
}

void List::dispBwd() {
	static struct node *cur = start;
	int e;
	if (cur == NULL)
		return;
	e= cur->data;
	cur = cur->next;
	List::dispBwd();
	cout << e << " -> ";
}




int main() {



	List l;
	cout << endl << "INSERTING" << endl;
	l.insertFirst(10);
	l.insertFirst(2);
	l.insertFirst(3);
	l.insertFirst(54);
	l.insertLast(75);
	l.insertLast(65);
	l.insertLast(75);
	l.insertLast(84);
	l.insertAfter(10, 100);
	l.insertBefore(100, 20);
	l.dispFwd();
	cout << endl;
	cout << endl << "deleting first" << endl;
	l.deleteFirst();
	l.dispFwd();
	cout << endl;
	cout << endl << "deleting last" << endl;
	l.deleteLast();
	l.dispFwd();
	cout << endl;
	cout << endl << "deleting spec" << endl;
	l.deleteSpec(20);
	l.deleteSpec(10);
	l.dispFwd();
	l.reverse();
	cout << endl<<"reverse"<<endl;
	l.dispFwd();

	cout << endl;
	getchar();
	return 0;
}