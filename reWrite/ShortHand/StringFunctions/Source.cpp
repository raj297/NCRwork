//string fns
#include<iostream>
#define lenmax 10
using namespace std;
class allStringFns
{
public:
	int len = lenmax;//used during dynaminc memeory allocation yo string
	allStringFns()
	{
	//constructor
	}
	~allStringFns()
	{
		//destructor
	}
	int stringlen(char *p);
	void stringrev(char *str);
	void stringcopy(char *s1, char *s2);
	void stringconcat(char *s1, char *s2);
	int stringcomp(char *s1, char *s2);
	//wrapper to rev
	void rev()
	{
		char *str1;
		str1 = new char[len];
		cout << "enter string 1" << endl;
		cin >> str1;
		stringrev(str1);
	}
	//wrapper to compare
	void comp()
	{
		char *str1, *str2;
		str1 = new char[len];
		cout << "enter string 1" << endl;
		cin >> str1;
		str2 = new char[len];
		cout << "enter string 2" << endl;
		cin >> str2;
		stringcomp(str1, str2);
	}
	//wrapper to concate
	void concat()
	{
		char *str1, *str2;
		str1 = new char[len];
		cout << "enter string 1" << endl;
		cin >> str1;
		str2 = new char[len];
		cout << "enter string 12" << endl;
		cin >> str2;
		stringconcat(str1, str2);
	}
	//wrapper to copy
	void copy()
	{
		char *str1, *str2;
		// cout << "enter string 1 lenght" << endl;
	   //  cin >> l;
		str1 = new char[len];
		cout << "enter string 1" << endl;
		cin >> str1;
		str2 = new char[stringlen(str1)];
		stringcopy(str2, str1);
		cout << str1;
	}
};
//implementation of funtions
int allStringFns::stringlen(char *sourceItr) {
	int count = 0;
	for (/*no initialization as ierating on source */; *sourceItr != '\0'; sourceItr++)
		count++;
	return count;
}
void allStringFns::stringrev(char *str) {

	char *from_start, *from_end;
	char temp;
	for (from_start = str, from_end = str + stringlen(str) - 1; from_start < from_end; from_start++, from_end--) {
		/*swaping start with end*/
		temp = *from_start;
		*from_start = *from_end;
		*from_end = temp;
	}
	cout << endl << "reversed to" << str;
}
void allStringFns::stringcopy(char *dest, char *source) {

	while (*source != '\0')
	{
		*dest++ = *source++;
	}
	cout << endl << "copy sucessful copied  ::";
}
void  allStringFns::stringconcat(char *str1, char *str2) {

	int i, j;//iterators
	for (i = 0; str1[i] != '\0'; i++);
	for (j = 0; str2[j] != '\0'; i++, j++) {
		str1[i] = str2[j];
	}
	str1[i] = '\0';
	cout << endl << "concatinated to " << str1;
}
int allStringFns::stringcomp(char *str1, char *str2) {
	int ret;
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			ret = *str1 - *str2;
			break;
		}str1++;
		str2++;
	}
	ret = *str1 - *str2;
	if (ret == 0)
		cout << endl << "yes matched";
	else if(ret < 0)
		cout << endl << "Not matched,str1 comes 1st in dictionary order";
	else
		cout << endl << "Not matched,str2 comes 1st in dictionary order";
	return ret;
}

int main()
{
	allStringFns obj;
	int choice;
	while (1) {
		cout << endl << "enter Your Choice" << endl;
		cout << "1.String Compare" << endl;
		cout << "2.String Concat" << endl;
		cout << "3.String Reverse" << endl;
		cout << "4.String Copy" << endl;
		cout << "5.String len" << endl;
		cout << "6.Exit" << endl;;
		cin >> choice;

		switch (choice)
		{
		case 1:
			obj.comp();
			break;

		case 2:
			obj.concat();
			break;

		case 3: obj.rev();
			break;

		case 4:obj.copy();
			break;

		case 5:char *str;
			str = new char[lenmax];
			cout << endl << "enter the string" << endl;
			cin >> str;
			cout << endl << "length = " << obj.stringlen(str) << endl;
			break;

		case 6:exit(1);
			break;
		default:cout << "enter the right choice!!!";
			break;
		}
	}
	getchar();
	getchar();
}