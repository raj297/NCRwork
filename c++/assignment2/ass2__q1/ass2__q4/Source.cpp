#include<iostream>

using namespace std;

class complex {

	float real;
	float imag;


public:
	complex() {

		real = 0;
		imag = 0;

	}

	complex(float r, float i) {

		real = r;
		imag = i;


	}

	complex operator=(complex c) {

		real = c.real;
		imag = c.imag;

	}

	complex operator+(complex c) {

		complex temp;
		temp.real = real + c.real;
		temp.imag = imag + c.imag;
		return temp;

	}

	complex operator-(complex c) {

		complex temp;
		temp.real = real - c.real;
		temp.imag = imag - c.imag;
		return temp;

	}

	complex operator-() {

		complex temp;
		temp.real = -real;
		temp.imag = -imag;
		return temp;

	}

	complex operator++() {

		++real;
		++imag;
		return *this;

	}

	complex operator++(int i) {
		complex temp;
		temp.real = real++;
		temp.imag = imag++;
		return temp;
	}

	complex operator,(complex c) {
		return c;
	}



	friend ostream& operator<<(ostream &, complex);
	friend istream& operator>>(istream &, complex &);


};

ostream& operator<<(ostream &cout, complex c) {
	cout << c.real << "+i" << c.imag << endl;
	return cout;

}

istream& operator>>(istream &cout, complex &c) {
	cin >> c.real >> c.imag;
	return cin;
}

int main() {


	complex c1(3, 4);
	cout << c1;
	complex c2(2, 5);
	cout << c2;
	complex c3 = c1 + c2;
	cout << c3;
	complex c4 = ++c1;
	cout << c4;
	complex c5 = c2++;
	cout << c5;
	cout << c1;
	cout << c2;


	getchar();
	return 0;
}