#include<iostream>
using namespace std;
class polar
{
	int theta, rad;
	static int cnt;
public:
	polar()
	{
		cnt++;
	}
	~polar()
	{
		cnt--;
	}
	polar(int theta, int rad)
	{
		cnt++;
	}
	friend int get_active();

};
int  get_active()
{
	return polar::cnt;
}
int polar::cnt;
int main()
{
	polar p1, p2(1, 2);
	cout << "active objs";
	cout<<get_active();
	p1.~polar();
	cout << "After destruction of 1 obj" << get_active();;
	getchar();

	
}