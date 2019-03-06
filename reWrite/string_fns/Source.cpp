#include<iostream>
#define lenmax 10
using namespace std;
class allStringFns
{
public:
	int l = lenmax;//used during dynaminc memeory allocation yo string
	int stringlen(char *p);
	void stringrev(char *str);
	void stringcopy(char *s1, char *s2);
    void stringconcat(char *s1, char *s2);
   int stringcomp(char *s1, char *s2);
   //wrapper to rev
   void rev()
   {
	   char *str1; 
	   //check here....
	  // cout << "enter string 1 lenght" << endl;
	 //  cin >> l;
	   str1 = new char[l];
	   cout << "enter string 1" << endl;
	   cin >> str1;
	   stringrev(str1);
   }
   //wrapper to compare
   void comp()
   {
	   char *str1, *str2;
	  // cout << "enter string 1 lenght" << endl;
	  // cin >> l;
	   str1 = new char[l];
	   cout << "enter string 1" << endl;
	   cin >> str1;
	   //cout << "enter string 2 lenght" << endl;
	   //cin >> l;
	   str2 = new char[l];
	   cout << "enter string 12" << endl;
	   cin >> str2;
	   stringcomp(str1, str2);
   }
   //wrapper to concate
   void concat()
   {
	   char *str1, *str2;
	//   cout << "enter string 1 lenght" << endl;
//cin >> l;
	   str1 = new char[l];
	   cout << "enter string 1" << endl;
	   cin >> str1;
	  // cout << "enter string 2 lenght" << endl;
	 //  cin >> l;
	   str2 = new char[l];
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
	   str1 = new char[l];
	   cout << "enter string 1" << endl;
	   cin >> str1;
	   str2 = new char[stringlen(str1)];
	   stringcopy(str2, str1);
	   cout << str1;
   }
};
//implementation of funtions
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

	while (*s2 != '\0')
	{
		*s1++ = *s2++;
	}
	cout << endl<<"copy sucessful copied  ::";
}
void  allStringFns::stringconcat(char *s1, char *s2) {

	int i, j;
	for (i = 0; s1[i] != '\0'; i++);
	for (j = 0; s2[j] != '\0'; i++, j++) {
		s1[i] = s2[j];
	}
	s1[i] = '\0';
	cout <<endl<< "concatinated to " << s1;
}
int allStringFns:: stringcomp(char *s1, char *s2) {
	int ret;
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			ret= *s1 - *s2;
			break;
		}s1++;
		s2++;
	}
	ret=*s1 - *s2;
	if (ret == 0)
		cout <<endl<< "yes matched";
	else
		cout << endl << "Not matched";
	return ret;
}

int main()
{
	allStringFns obj;
	int choice;
	while (1) {
		cout <<endl<< "enter Your Choice" << endl;
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
			cout << endl<<"enter the string"<<endl;
			cin >> str;
			cout<<endl<<"length=="<<obj.stringlen(str)<<endl;
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