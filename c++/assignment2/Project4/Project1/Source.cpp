#include <iostream>
/*Define a complex class, define default constructor, parameterized constructors, copy
constructor, destructor. Overload +, -, unary -, ++ (prefix, postfix), =, comma (,), ->,
<< and >> operators.*/
using namespace std;
class complex
{
	float real;
	float img;
public:
	void print()
	{
		cout << "real =" << real << "img=" << img << endl;
	}
	complex()
	{

	}
	complex(float r, float i)
	{
		real = r;
		img = i;

	}
	complex operator+(complex c)
	{
		real = real + c.real;
		img = img + c.img;
		return (*this);
	}
	complex operator-(complex c)
	{
		real = real - c.real;
		img = img - c.img;
		return (*this);
	}
	complex operator++(int x)
	{
		complex c;
		c.real = real++;
		c.img = img++;
		return (c);
	}
	complex operator++()
	{
		real = ++real;
		img = ++img;
		return (*this);
	}
	void operator=(complex c)
	{
		real = c.real;
		img = c.img;

	}
	complex operator,(complex c)
	{
		
		return *this;
	}
	complex* operator->()
	{
		return  this;
	}
	friend ostream& operator<<(ostream &std, complex c);
	friend istream& operator>>(istream &std, complex &c);
};
ostream& operator<<(ostream &std, complex c)
{
	cout << "real =" << c.real << "img=" << c.img << endl;
	return std;
}
istream& operator>>(istream &std, complex &c)
{
	cout << "enter real part";
	cin>> c.real;
	cout << "enter img part";
	cin>> c.img;
	return std;
}
int main() {
	complex c3, c1(2.3, 3.2), c2(0, 0);
	
	cout <<"initially "<<endl<<"c1:"<<endl<< c1<<endl;
	cout << "c2:" <<endl<< c2 << endl;
	cout << "overloading binary +" << endl;
	c3 = c1 + c2;
	cout << c3;
	cout << "overloading binary -"<<endl;
	c3 = c2 - c1;
	cout << c3;
	cout << "overloading operator =" << endl;
	complex c4 = c3;
	cout << c4;
	complex c5;
	cout << "overloading operator >>" << endl;
	cin >> c5;
	cout << "overloading operator pre ++" << endl;
	cout << ++c5;
	cout << "overloading operator post ++" << endl;
	cout << c5++;
	cout << "overloading operator (coma)," << endl;
	cout << c4,c5;
	cout << "overloading operator ->" << endl;
	c1->print();
	getchar();
	getchar();

}