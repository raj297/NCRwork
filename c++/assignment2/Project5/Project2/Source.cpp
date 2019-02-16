/*Define string class with dynamic memory allocation for string. Define default
constructor, parameterized constructors, copy constructor, destructor, Overload +,
[], =, <<, >> operators. Observe the behavior of shallow copying and deep copying.*/
#include<iostream>
using namespace std;
class string;
class string1
{
	int l;
	char* ptr;
public:
	string1()
	{
		ptr = NULL;

	}
	string1(const char *s)
	{
		l = strlen(s)+1;
		ptr = new char[l];
		strcpy_s(ptr,l,s);
	}
	string1(string1 &str)
	{
		l = (str.l)+1;
		ptr = new char[l ];
		strcpy_s(ptr, l,str.ptr);
	}
	~string1()
	{
		if(ptr==NULL)
		delete ptr;
	}
	string1 operator+(string1 c)
	{
		strcat_s(ptr,l+(c.l)+2,c.ptr);
		return *this;
	}
	char& operator[](int i)
	{
		char a = 'n';
		if (i < l)
			return *(ptr + i);
		else
			return a;
	}
	string1 operator=(string1 c)
	{
		l = c.l+1;
		ptr = new char[l];
		strcpy_s(ptr, l, c.ptr);
		return *this;
	}
	string1 operator,(string1 c)
	{

		return *this;
	}
	string1* operator->()
	{
		return  this;
	}
   friend ostream& operator<<(ostream &std, string1 c);
	friend istream& operator>>(istream &std, string1 &c);
}; 
ostream& operator<<(ostream &std, string1 c)
{
	cout << c.ptr << endl;
	return std;
}
istream& operator>>(istream &std, string1 &c)
{
	char buf[100];
	cout << "enter the string";
	cin >>buf;
	c.l = strlen(buf)+1;
	c.ptr = new char[c.l];
	strcpy_s(c.ptr, c.l, buf);
return std;
}
int main()
{
	string1 s,s1,s2("APE");
	cout << "overloading operator >>" << endl;
	cin >> s;
	cout << "overloading operator <<" << endl;
	cout << s;
	cout << "overloading operator =" << endl;
	s1 = s;
	cout << s1;
	cout << "overloading operator +" << endl;
	 s1+s2;
	cout << s1;
	cout << "overloading operator []" << endl;
	int i;
	cout << "enter the idx" << endl;
	cin >> i;
	cout << s2[i];
	getchar();
	getchar();
}