#include<iostream>
using namespace std;
class insort
{
	int n, *a;

public:
	void read();
	void sort();
	void print();
};
void insort::read()
{

	cout << "enter the number of elements to sort" << endl;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "enter the element" << endl;
		cin >> a[i];
	}


}

void insort::sort()
{
	int temp, j;
	for (int i = 1; i < n; i++)
	{
		j = i - 1;
		temp = a[i];
		while (j >= 0 && temp < a[j])
		{
			a[j + 1] = a[j];//moves
			j--;

		}
		a[j + 1] = temp;
	}
}

void insort::print()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}
int main()
{
	insort ob;
	ob.read();
	ob.print();
	ob.sort();
	ob.print();
	getchar();
	getchar();
	return 0;
}