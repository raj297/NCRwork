#include<iostream>/*Define a class named Employee with data members empno, name, & salary and
appropriate member functions for setting and reading the data, constructors and
destructor. Create an array of 5 Employee objects, populate it with data by
overloading >> operator*/
using namespace std;
class emp
{
	int empno;
	char name[100];
	int sal;
public:
	emp()
	{
	}
	emp(int i,const char buf[100],int s)
	{
		empno = i;
		strcpy_s(name,strlen(buf)+1,buf);
		sal = s;
	}
	friend istream& operator>>(istream &std, emp &e);
	friend ostream& operator<<(ostream &std, emp e);
};
istream& operator>>(istream &std, emp &e)
{
	cout<<"enter the eno,name,sal "<<endl;	
	cin >>e.empno;
	cin >> e.name;
	cin >> e.sal;
	cout << endl;
	return std;
}
ostream& operator<<(ostream &std, emp e)
{
	cout<< e.empno;
	cout << e.name;
	cout << e.sal;
	cout << endl;
	return std;
}
int main()
{
	emp e, e1(1, "sad", 2123), e2[1];
	for (int i = 0; i < 1; i++)
	{
		cin >> e2[i];
	}
	cin >> e;

	cout << e1;
	for (int i = 0; i < 1; i++)
	{
		cout << "empoyee detail of employee" << i<<endl;
		cout << e2[i];
		cout << endl;
	}

	cout << e;
	getchar();
	getchar();
}