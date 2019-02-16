#include<iostream>
using namespace std;
class point
{
	float x;
	float y;
public :
	void read()
	{
		cout << "enter x , y";
		cin >> x >> y;
	}
	friend void distance(point p1, point p2);
};
void distance(point p1,point p2)
{
	float res;
	res = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
	cout << "result="<<res;
}
int main()
{
	point p1, p2;
	p1.read();
	p2.read();
	distance(p1, p2);
}