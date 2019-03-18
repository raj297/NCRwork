#include<iostream>

using namespace std;

class String {

	char *ptr;
	int len;

public:
	//default const. using for initializing
	String() {
		ptr = NULL;
		len = 0;
	}
	//to allocate DM
	String(const char *str) {

		len = strlen(str);
		ptr = new char[len + 1];
		strcpy_s(ptr, len + 1, str);
	}
	//copy const
	String(String &s) {


		len = s.len;
		ptr = new char[len + 1];
		strcpy_s(ptr, len + 1, s.ptr);


	}
	//overloading =
	String operator=(String temp) {
		String res;
		ptr = new char[temp.len + 1];
		strcpy_s(ptr, temp.len + 1, temp.ptr);
		len = temp.len;
		return(*this);
	}

	String operator=(const char *c) {
		String res;

		res.ptr = new char[strlen(c) + 1];
		strcpy_s(res.ptr, strlen(c) + 1, c);
		res.len = strlen(c) + 1;
		return(res);
	}
	//overloading +
	String operator+(String& s2) {
		
	}

	char& operator[](int n) {
		return ptr[n];
	}
	//overloading ,
	String operator,(String c)
	{
		return c;
	}
	//overloading ->
	String* operator->()
	{
		return  this;
	}
	void print()
	{
		cout <<*this;
	}
	friend istream& operator>>(istream &, String &);
	friend ostream& operator<<(ostream &, String);

};

istream& operator>>(istream &cin, String &s) {

	s.ptr = new char[20];
	cin >> s.ptr;
	s.len = strlen(s.ptr);
	return cin;

}


ostream& operator<<(ostream &cout, String s) {

	cout << "string::"<<s.ptr << endl;
	cout <<"length::" <<s.len<<endl;
	return cout;

}

int main() {
	
	String s;
	cout << "enter a string";
	//demo for overloading >>
	cin >> s;
	cout << s;


	String s1("cdac");
	//demo for overloading <<
	cout << s1 << endl;


	String s2(s1);
	cout << s2 << endl;

	String s3 = " ncr";
	cout << s3 << endl;
	//demo for overloading =
	    String s4 = s1;
	    cout << s4;
	//demo for overloading ->
	     s4->print();
	
		 
   //demo for overloading []
	      cout << s1[1];

	//demo for overloading ,
	    s4 = s1 , s2;
	    cout << s4;
		//demo for overloading + yet tod do
		
   getchar();
	getchar();
	return 0;
}