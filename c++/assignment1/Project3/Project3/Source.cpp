#include <iostream>

using namespace std;
class complex
{
	float real;
	float img;
public:
	complex()
	{
		real = 0;
		img = 0;
	}
	complex(float f)
	{
		img = real = f;
	}
	complex(float f1, float f2)
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
	add(c2, c3);

	mul(c2, c3);
	getchar();
}