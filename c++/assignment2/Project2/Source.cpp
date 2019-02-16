#include<iostream>
#include <stdio.h>
#define n 3
using namespace std;
class student
{
	int rollno,total,marks[n];
	char name[20], grade;
public:
	
	student()
	{
	
		
		cout << "enter the roll";

		cin >> rollno;
		cout << "name" << endl;
		cin >> name;
		
		int i = 0;
		cout << "marks of" << n << "subjects";
		while (i++< n)
		{
			cin >> marks[i];
		}
		int total = 0;
		i = 0;
		while (i++<n)
		{
			total = total + marks[i];

			if (total > 70)
			grade = 'A';
			else if (total > 50 && total <= 70)
				grade = 'B';
			else if (total < 50 && total >= 40)
				grade = 'c';
		}
		
		
	}
friend ostream& operator<<(ostream &std, student s);
};

ostream& operator<<(ostream &cout, student s)
{

	cout << s.rollno << " rollno." << endl;
	int i = 0;
	while (i++ < n)
	{
		cout << s.marks[i];
	}
	cout << endl;
	cout << "name"<<s.name << endl;
	cout << "grade" << s.grade;
	return cout;
}
int main()
{
	int n1=3;
	cout << " enter 3 details number of students";
	//cin >> n1;
	
	student s1[3];
	for (int i = 0;i<n1;i++)
	cout <<s1[i];
	cin >> n1;

}