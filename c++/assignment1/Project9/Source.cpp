#include<iostream>
using namespace std;

class swaper 
{
public :
	void byval(int a,int b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}
	void byref(int *a, int *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
};
int main()
{
	swaper s;int a, b;
	cout << "enter a,b" << endl;
	cin >> a >> b;
	cout << "initially a=" << a << "   b=" << b << endl;
	cout << "enter the choice"<<endl<<"1.byvalue"<<endl<<"2.byreference";
	
	cin >> n;
	switch (n)
	{ case 1:s.byref(&a, &b);
		cout << "using byvalue a=" << a << "  b=" << b << endl;
		getchar();
		break;
	case 2:s.byval(a, b);
		cout << "using byref  a=" << a << "   b=" << b << endl;
		getchar();
		break;
	case 3:cout << "end";
		exit(0);
		break;
	}

}