#include<iostream>
using namespace std;
class emp
{
	int sal;
	int id;
public:
	emp()
	{
		sal = 0;
		id = 0;
		cout << "this is a default const"<<endl;
	}
	emp(int i, int j)
	{
		sal = i;
		id = j;
		cout << "this is a param const" << endl;
	}
	~emp()
	{
		cout << "destructed" << endl;;

	}
	void print()
	{
		cout << "emp1::" << id << "  " << sal << endl;

	}
};
int main()
{
	emp e, e1(30, 20);
	e.print();
	e1.print();
	cout << sizeof(emp);
	getchar();
}