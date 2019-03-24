#pragma once
#include<iostream>
using namespace std;
struct node {
	char data;
	struct node *next;
};

//charStack implementation using linked list
class charStack {

	struct node *top;

public:
	charStack() {
		top = NULL;
	}

	~charStack() {
		struct node *temp;
		while (top != NULL) {
			temp = top;
			top = top->next;
			delete(temp);
		}
	}
	void push(char);
	char pop();
	char peek();
	int isEmpty();
	void display();
};

//charStack operations...
void charStack::push(char e) {
	struct node *temp;
	temp = new node;
	temp->data = e;
	temp->next = top;
	top = temp;
}
char charStack::pop() {
	char x = NULL;
	if (top != NULL) {
		x = top->data;
		struct node *temp = top;
		top = top->next;
		delete(temp);
	}
	else
		cout << "list is empty";
	return x;
}
char charStack::peek() {

	if (top != NULL)
		return top->data;
	else
		return  NULL;
}
int charStack::isEmpty() {

	return(top == NULL);

}
void charStack::display() {
	struct node *cur = top;
	while (cur != NULL) {
		cout << cur->data << " -> ";
		cur = cur->next;
	}
}


