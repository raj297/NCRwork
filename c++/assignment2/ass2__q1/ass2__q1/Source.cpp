
#include<iostream>

using namespace std;

class polar {

	static int count;
	float angle;
	float radius;

public:

	polar(float a, float b) {
		count++;
		angle = a;
		radius = b;
	}

	static void ObjectCount() {
		cout << count;
	}

	~polar() {
		count--;
	}

};

int polar::count;



int main() {

	polar t1(2, 3);
	polar t2(2, 3);
	polar t3(2, 3);

	t3.ObjectCount();

	t1.~polar();
	t2.~polar();

	t1.ObjectCount();


	getchar();
	return 0;
}