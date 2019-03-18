#include<iostream>

using namespace std;

class student {

	char *name;
	int roll_no;
	int marks[3];
	int total;
	char grade;

	friend void generate_result(student[], int);
public:

	student() {

	}

	void getvalues(const char *n, int r, int m[], int t, char g) {

		name = new char[strlen(n) + 1];
		char na[20];
		cin >> na;
		name = new char[strlen(na) + 1];
		strcpy_s(name, strlen(na) + 1, na);

		roll_no = r;

		marks[0] = m[0];
		marks[1] = m[1];
		marks[2] = m[2];

		total = t;

		char grade = g;
	}

	friend ostream& operator<<(ostream &, student);

};

ostream& operator<<(ostream &cout, student s) {

	cout << s.name << endl;
	cout << s.roll_no << endl;
	cout << s.marks[0] << " " << s.marks[1] << " " << s.marks[2] << " " << endl;
	cout << s.total << endl;
	cout << s.grade << endl;

	return cout;
}

void generate_result(student s[], int n) {

	for (int i = 0; i < n; i++) {
		s[i].total = s[i].marks[0] + s[i].marks[1] + s[i].marks[2];

		if (s[i].total / 3 > 90)
			s[i].grade = 'A';
		else if (s[i].total / 3 > 70 && s[i].total / 3 <= 70)
			s[i].grade = 'B';
		else
			s[i].grade = 'C';

	}
}

int main() {

	student s[3];
	int m1[] = { 95,90,90 };

	s[0].getvalues("yashwanth", 1, m1, 0, 'c');
	int m2[] = { 60,80,70 };
	s[1].getvalues("reddy", 1, m2, 0, 'c');
	int m3[] = { 60,30,70 };
	s[2].getvalues("raj", 1, m3, 0, 'c');

	generate_result(s, 3);

	for (int i = 0; i < 3; i++)
		cout << s[i];

	int k;
	cin >> k;
	getchar();
	return 0;
}