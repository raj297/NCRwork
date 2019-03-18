#include<iostream>

using namespace std;

class employee {

	int empno;
	char name[10];
	int salary;


public:
	void setter() {
		cin >> *this;
	}

	void readValues() {
		cout << *this << endl;
	}

	friend istream& operator>>(istream &, employee&);
	friend ostream& operator<<(ostream &, employee);

};

istream& operator>>(istream &cin, employee &e) {

	cin >> e.empno;
	cin >> e.name;
	cin >> e.salary;

	return cin;
}

ostream& operator<<(ostream &cout, employee e) {

	cout << e.empno;
	cout << e.name;
	cout << e.salary;

	return cout;
}



int main() {

	employee emp[3];

	for (int i = 0; i < 3; i++) {
		cout << "enter details of emp::" << i << endl;
		emp[i].setter();
	}

	for (int i = 0; i < 3; i++) {
		cout << "entries::" << endl;
		emp[i].readValues();
	}



	getchar();
	getchar();
	return 0;
}

