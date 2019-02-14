#include<iostream>
#include<string.h>
using namespace std;

class student
{
public:
	char *sname;
	char grade;
	float marks[3];
	float avg;
public:
	student()
	{
		sname = NULL;
		grade = 'N';
		for (int i = 0; i < 3; i++)
			marks[i] = 0.0;
	}
	student(char *s, float m1, float m2, float m3)
	{
		int len = strlen(s);
		sname = (char *)malloc(len * sizeof(char) + 1);
		strcpy_s(sname, len * sizeof(char) + 1, s);
		marks[0] = m1;
		marks[1] = m2;
		marks[2] = m3;
	}

	

}; 
class course
{
public:
	
	void calculate_grade(student s)
	{
		float sum = 0,avg;
		for (int i = 0; i < 3; i++)
		{
			sum = sum + s.marks[i];
		}
		avg = sum / 3;
		if (avg > 60)
			s.grade = 'A';

		else if (avg < 60 && avg>50)
			s.grade = 'B';
		else if (avg < 50 && avg>40)
			s.grade = 'C';
		else
			s.grade = 'F';
	}
	void display(student s)
	{
		cout << s.sname << s.grade<<">>";
	}

};
int main()
{
	//student s;
	course c;
	char s[10];
	float m1,m2,m3;
	cout << "enter the name and marks";
	cin >>s>> m1 >> m2 >> m3;
	student s1(s,m1,m2,m3);
	c.calculate_grade(s1);
	//s.display();
	c.display(s1);

	
	int num;
	cin>>num;
	
}