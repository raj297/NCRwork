#include<iostream>

using namespace std;

class dis1;
class dis2;

class dist1 {

	float mts;
	float cms;

	dist1() {
		mts = 0;
		cms = 0;
	}

	dist1(float a, float b) {
		mts = a;
		cms = b;
	}

	friend class dist2;


	void display()
	{
		cout << mts << endl;
		cout << cms << endl;
	}

	void add(dist1 d1, dist2 d2);
	friend int main();

};


class dist2 {

	float feet;
	float inches;

	dist2(float a, float b) {
		feet = a;
		inches = b;
	}

	friend class dist1;


	void disp()
	{
		cout << feet << endl;
		cout << inches << endl;
	}

	void add(dist1 d1, dist2 d2);
	friend int main();
};
void dist2::add(dist1 d1, dist2 d2) {

	feet = d1.mts*3.28084 + d2.feet;
	inches = d1.cms*0.393701 + d2.inches;

}

void dist1::add(dist1 d1, dist2 d2) {

	mts = d1.mts + d2.feet*0.3048;
	cms = d1.cms + d2.inches*2.54;

}


int main() {

	dist1 d1(1, 1);
	dist2 d2(1, 1);

	dist1 d3;

	d3.add(d1, d2);

	d3.display();


	getchar();
	return 0;
}