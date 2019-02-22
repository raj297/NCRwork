#include<iostream>
using namespace std;
class binsearch
{
	
public:
	int n, *a;
	binsearch()
	{
		a = NULL;
	}
	void read();
	int search(int,int,int);
	void print();
};
void binsearch::read()
{

	cout << "enter the number of elements to  the array" << endl;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "enter the element" << endl;
		cin >> a[i];
	}


}


void binsearch::print()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}
int  binsearch::search(int key,int lo,int hi)
{
	int mid = (lo + hi) / 2;

	
	if (key < a[mid])
	{
		search(key, lo, mid - 1);
	}
	else if (key > a[mid])
		search(key, mid + 1, hi);
	else if (key == a[mid])
	{
		cout << "found at idx " << mid << endl;
		return mid;
	}

	else
	return -1;
}
int main()
{
	binsearch ob;
	ob.read();
	ob.print();
	int e;//search ele
	cout << "enter element to search";
	cin >> e;
	ob.search(e,0,ob.n);
	ob.print();
	getchar();
	getchar();
	return 0;
}