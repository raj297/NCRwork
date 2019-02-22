#include<iostream>
using namespace std;
class lsearch
{
	int n, *a;
public:
	void read();
	void search(int);
	void print();
};
void lsearch::read()
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


void lsearch::print()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}
void lsearch::search(int key)
{
	int i;
	for ( i = 0; i < n; i++)
	{
		if (a[i] == key)
		{
			cout << endl << "found at index" << i << endl;
			break;
		}
	}
	if (i == n)
		cout <<endl<< "NO such ele in list";

}
int main()
{
	lsearch ob;
	ob.read();
	ob.print();
	int e;//search ele
	cout << "enter element to search";
	cin >> e;
	ob.search(e);
	ob.print();
	getchar();
	getchar();
	return 0;
}