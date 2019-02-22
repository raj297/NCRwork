#include<iostream>
using namespace std;
class bsort
{
	int n, *a;

public:
	void read();
	void sort();
	void swap(int &a, int &b);
	void print();
};
void bsort::read()
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
void bsort::swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;

}
void bsort::sort()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			if (a[i] < a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}
void bsort::print()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}
int main()
{
	bsort ob;
	ob.read();
	ob.print();
	ob.sort();
	ob.print();
	getchar();
	getchar();
	return 0;
}