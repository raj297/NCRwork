#define Qsize 10
#include<iostream>

using namespace std;
class queue
{
	int  q[Qsize], rear = -1, front = -1;
public:
	queue()
	{
		cout << "lets start" << endl;
	}
	void enQ(int e);
	int  deQ();
	void print();
	void dispfwd();
	bool isEmpty();
	bool isFull();
};
void queue::print()
{
	cout << "rear" << rear << endl << "front" << front << endl;
}
bool queue::isEmpty()
{
	if (front==-1)
		return true;
	else
		return false;

}
bool queue::isFull()
{
	if (front == 0 && rear == Qsize- 1) 
	{
		return true;
	}
	else if (front == (rear + 1)%Qsize) 
	{
		return true;
	}
	return false;
}
void queue::enQ(int e)
{
	if (!isFull())
	{
		if (front == -1) 
			front = 0;
	//	cout << "done" << endl;
		rear = (rear + 1) % (Qsize);
		q[rear] = e;
	}
	else
		cout << endl << "Q is full" << endl;

}
int  queue::deQ()
{
	int del;
	if (isEmpty())
	{
		cout << endl << "Q is empty" << endl;
		return -1;
	}
	else
	{
		
			del = q[front];
			if (front == rear) // reset the Q after deleting last ele
			{
				front = -1;
				rear = -1;
			} 
			else if ( front == Qsize-1)
			{
				front = 0;
			}
			else 
			{
				front = (front + 1) % (Qsize);
			}
			return(del);
		
	}


}
void queue::dispfwd()
{
	if (!isEmpty()) {
		
		for (int i = front ; i < rear; i = (i + 1) % (Qsize))
		{
			cout << "" << q[i] << " ";
		
		}
	
	}
	else
		cout << "Q is empty";
	cout << endl;
}
int main()
{
	queue Q;
	Q.deQ();
	cout << "enquing" << endl;
	Q.enQ(1);
	Q.enQ(2);
	Q.enQ(3);
	Q.enQ(4);
	Q.enQ(5);
	Q.enQ(1);
	Q.enQ(2);
	Q.enQ(3);
	Q.enQ(3);
	Q.enQ(3);
	Q.dispfwd();
	cout << "dequing" << endl;
	Q.deQ();
	Q.deQ();
	Q.deQ();
	Q.deQ();
	Q.dispfwd();
	Q.enQ(38);
	Q.enQ(39);
	Q.dispfwd();
	getchar();
}