#include<iostream>
using namespace std;
class selSort
{
	int n, *a;

public:
	void read();
	void sort();
	void swap(int &a, int &b);
	void print();
};
void selSort::read()
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
void selSort::swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;

}
void selSort::sort()
{
	int mintemp;
	for (int i = 0; i < n-1; i++)
	{

		mintemp = i;
		for (int j = i + 1; j < n; j++)
		{
			
			if (a[j] < a[mintemp])
				mintemp = j;
		}
		swap(a[i], a[mintemp]);
	}
}
void selSort::print()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}
int main()
{
	selSort ob;
	ob.read();
	ob.print();
	ob.sort();
	ob.print();
	getchar();
	getchar();
	return 0;
}