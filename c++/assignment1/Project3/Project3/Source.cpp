#include <iostream>

using namespace std;
class complex
{
	float real;
	float img;
public:
	complex()//default const
	{
		real = 0;
		img = 0;
	}
	complex(float f)//parameterized (with 1 param) const
	{
		img = real = f;
	}
	complex(float f1, float f2)//parameterized (with 2 param) const
	{
		real = f1;
		img = f2;
	}
	friend void add(complex &c1, complex &c2);
	friend void mul(complex &c1, complex &c2);
};
void add(complex &c1, complex &c2)
{
	c1.real = c1.real + c2.real;
	c1.img = c1.img + c2.img;
	cout << c1.real << "+" << c2.img << " " << endl;
}
void mul(complex &c1, complex &c2)
{
	c1.real = c1.real*c2.real;
	c1.img = c1.img*c2.img;
	cout << c1.real << "+" << c2.img << " " << endl;
}

int main() {
	complex c1(), c2(12), c3(12, 13);
	cout << "addition" << endl;
	add(c2, c3);
	cout << "muultiplication" << endl;
	mul(c2, c3);
	getchar();
}