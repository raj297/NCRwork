#include<iostream>
using namespace std;
class time
{
	int h;
	int m;
	int s;
public:
	time()
	{
		h = 0;
		m = 0;
		s = 0;
	}
	time(int hr, int mr, int sr)
	{
		h = hr;
	  m = mr;
		s = sr;
	}
	void print()
	{
		cout << h << ":" << m << ":" << s<<endl;
	}
	void add(time t, time t1)//adding
	{

		s =s+ t1.s + t.s;
		if (s >= 60) {
			m = m + 1;
			s = s%60;
		}
		m = m+t1.m + t.m;
		if (m>= 60) {
			h= h+ 1;
			m=m%60;
		}
		h=h+t1.h + t.h;
		if (h > 24)
		{
			h = h % 24;

		}
	}
};
int main()
{
	time t,t2;
	time t3(22, 40, 60);
	time t1(11, 43, 66);
	cout << "HELLo the time is";
	t.print();
	cout <<endl<< "Now it is";
	t1.print();
	t2.add(t3, t1);//adding t1 and t2 and placing in t2
	cout << endl << "After adding it is";
	t2.print();
	getchar();
}