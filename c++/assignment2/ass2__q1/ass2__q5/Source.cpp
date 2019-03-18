#include<iostream>

using namespace std;

class String {

	char *ptr;
	int len;

public:
	String() {
		ptr = NULL;
		len = 0;
	}

	String(const char *c) {

		len = strlen(c);
		ptr = new char[len + 1];
		strcpy_s(ptr, len + 1, c);
	}

	String(String &s) {


		len = s.len;
		ptr = new char[len + 1];
		strcpy_s(ptr, len + 1, s.ptr);


	}

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

	String operator+(String& s2) {
		
	}

	char& operator[](int n) {
		return ptr[n];
	}

	String operator,(String c)
	{
		return c;
	}
	String* operator->()
	{
		return  this;
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

	cout << s.ptr << endl;
	cout << s.len;
	return cout;

}

int main() {

	String s1("cdac");
	cout << s1 << endl;
	String s2(s1);
	cout << s2 << endl;
	String s3 = " ncr";
	cout << s3 << endl;
	//String s4 = s1 + s3;
	//cout << s4;
	cout << s1[1];



	getchar();
	return 0;
}