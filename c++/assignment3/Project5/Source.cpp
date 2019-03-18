#include<iostream>
using namespace std;
class person
{
public:
	char name[12];
	int age;
};
class physique :virtual public person 
{
public:
	int height;
	int weight;
};
class family :virtual public person {
public:
	int numChildren;
	char relegion[12];


};
class employee :public physique,public family {
public :
	int empno;
	int sal;
	relegion  = "HINDU";

	void print()
	{
		cout << "empno" <<empno << endl;
		cout << "name "<<name << endl;
		cout << "age "<< age<< endl;
		cout << "height" << height<< endl;
		cout <<" weight" << weight << endl;
		cout << "relegion" << relegion<< endl;
		cout << "numChildren" << numChildren << endl;
		cout << "sal" << sal << endl;
		getchar();
	}
	
};

int main() {
	employee obj;
	obj.empno = 12;
	obj.sal = 1000;
	obj.numChildren = 12;
	obj.print();
}