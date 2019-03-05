#include<iostream>
using namespace std;
class allStringFns
{
public:
	int stringlen(char *p);
	void stringrev(char *str);
	void stringcopy(char *s1, char *s2);
    void stringconcat(char *s1, char *s2);
   int stringcomp(char *s1, char *s2);
   void rev()
   {
	   char *str1; int l;
	   cout << "enter string 1 lenght" << endl;
	   cin >> l;
	   str1 = new char[l];
	   cout << "enter string 1" << endl;
	   cin >> str1;
	   stringrev(str1);
   }
   void comp()
   {
	   char *str1, *str2; int l;
	   cout << "enter string 1 lenght" << endl;
	   cin >> l;
	   str1 = new char[l];
	   cout << "enter string 1" << endl;
	   cin >> str1;
	   cout << "enter string 2 lenght" << endl;
	   cin >> l;
	   str2 = new char[l];
	   cout << "enter string 12" << endl;
	   cin >> str2;
	   stringcomp(str1, str2);
   }
   void concat()
   {
	   char *str1, *str2; int l;
	   cout << "enter string 1 lenght" << endl;
	   cin >> l;
	   str1 = new char[l];
	   cout << "enter string 1" << endl;
	   cin >> str1;
	   cout << "enter string 2 lenght" << endl;
	   cin >> l;
	   str2 = new char[l];
	   cout << "enter string 12" << endl;
	   cin >> str2;
	   stringconcat(str1, str2);
   }
   void copy()
   {
	   char *str1, *str2; int l;
	   cout << "enter string 1 lenght" << endl;
	   cin >> l;
	   str1 = new char[l];
	   cout << "enter string 1" << endl;
	   str2 = new char[l];
	   stringcopy(str2, str1);
   }
};
int allStringFns:: stringlen(char *p) {
	int count = 0;
	for (; *p != '\0'; p++)
		count++;
	return count;
}
void allStringFns:: stringrev(char *str) {

	char *p1, *p2;
	char temp;
	for (p1 = str, p2 = str + stringlen(str) - 1; p1 < p2; p1++, p2--) {
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
	cout << endl << "reversed to" << str;
}
void allStringFns::stringcopy(char *s1, char *s2) {
	while ((*s1++ = *s2++) != '\0');
}
void  allStringFns::stringconcat(char *s1, char *s2) {

	int i, j;
	for (i = 0; s1[i] != '\0'; i++);
	for (j = 0; s2[j] != '\0'; i++, j++) {
		s1[i] = s2[j];
	}
	s1[i] = '\0';
	cout <<endl<< "concatinated to   " << s1;
}
int allStringFns:: stringcomp(char *s1, char *s2) {
	while (*s1 == *s2) {
		if (*s1 == '\0')
			return *s1 - *s2;
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

int main()
{
	allStringFns obj;
	int choice;
	cout << "enter Your Choice" << endl;
	cout << "1.String Compare" << endl;
	cout << "2.String Concat" << endl;
	cout << "3.String Reverse" << endl;
	cout << "4.String Copy" << endl;;
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
	default:cout << "enter the right choice!!!";
		break;
	}
	getchar();
	getchar();
}