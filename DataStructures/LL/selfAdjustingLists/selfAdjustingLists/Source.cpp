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
	void deleteSpec(int);
	void search(List &l, int);
	void dispBwd();
	void dispFwd();

};
void List:: search(List &l,int s)
{
	if (l.start != NULL) {
		if (l.start->data == s) {
			
		}
		else {
			struct node *temp, *cur = l.start;
			
			while (cur->next != NULL && cur->next->data != s)
				cur = cur->next;

			if (cur->next != NULL) 
			{
				cout << "it is found and repalcing";
				l.deleteSpec(s);
				l.insertFirst(s);
			}
			else
				cout << "element not found in search";
		}
	}
	else
		cout << "list is empty";
}

void List::insertFirst(int e) {
	struct node *temp;
	temp = new node;
	temp->data = e;
	temp->next = start;
	start = temp;
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
				cout << "element not found in delspec";
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
	e = cur->data;
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
	l.dispFwd();
	cout << endl;	
	l.dispFwd();
	cout << endl;
	l.dispFwd();
	cout << endl << "self adjusts on search of 65" << endl;
	l.search(l,65);
	cout << endl;
	cout << endl << "self adjusts on search of 10" << endl;
	l.search(l, 10);
	cout << endl;
	l.dispFwd();
	cout << endl;
	getchar();
	return 0;
}