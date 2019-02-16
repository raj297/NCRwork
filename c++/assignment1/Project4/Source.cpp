#include<iostream>

using namespace std;
inline int  add(int a, int b)
{
	return a + b;
}
inline int  sub(int a, int b)
{
	return a - b;
}
inline float ndiv(float a, float b)
{
	return a / b;
}
inline int  mul(int a, int b)
{
	return a * b;
}


int main()
{
	int  n = 0,x,y;
	cout << "enter x,y" << endl;
	cin >> x >> y;
	cout << "add::" << add(x, y) << "...mul::" << mul(x, y) << "...sub::" << sub(x, y) << "...enter elements for div::";
	cin >>x >> y;
	cout << ndiv(x, y);
	cin >> n;
}