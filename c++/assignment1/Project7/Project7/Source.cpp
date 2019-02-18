
#include<iostream>

using namespace std;

class matrix {

	int r, c, i, j;
	int **p;
public:
	matrix(int r, int c) 
	{
		r = r;
		c = c;
		p = new int*[r];
		for (i = 0; i < r; i++)
			p[i] = new int[c];

		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				p[i][j] = 0;
			}
		}
	}

	void elements()
	{
		cout << "enter the elemnets" << endl;
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < c; j++) 
			{
				cin >> p[i][j];
			}
		}
	}

	void print() {
		for (i = 0; i < r; i++) 
		{
			for (j = 0; j < c; j++)
			{
				cout << p[i][j] << " ";
			}
			cout << endl;
		}
	}

	
	friend matrix mul(matrix, matrix);
};


int main() {

	
	matrix m1(2, 2);
	m1.elements();
	m1.print();
	matrix m2(2, 2);
	m2.elements();
	m2.print();
	matrix m3 = mul(m1, m2);
	m3.print();
	getchar();
	return 0;
}

matrix mul(matrix m1, matrix m2)
{
	matrix res(m1.r, m2.c);
	for (int i = 0; i < m1.r; i++)
	{
		for (int j = 0; j < m1.c; j++)
		{
			for (int k = 0; k < m2.c; k++)
				res.p[i][k] = res.p[i][k] + (m1.p[i][j] * m2.p[j][k]);
		}
	}
	return res;
}