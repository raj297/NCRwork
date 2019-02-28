#include<windows.h>
#include<iostream>
#include "tchar.h"
using namespace std;
int _tmain(int argc, TCHAR *argv[], TCHAR **evar[])
{
	char arry[] = "sdas";
	CHAR  c = 'a';
	WCHAR warr[] = L"wsdass";
	BOOL uniCheck = IsTextUnicode(warr, wcslen(warr), NULL);
	cout << "get last error and Unicode check returns::" << endl << GetLastError() << endl <<uniCheck<< endl;
	wchar_t buf[10];
	char cbuf[10];
	int ret = MultiByteToWideChar(CP_UTF8, 0, arry, strlen(arry), buf, 5);
	if (ret> 0) {

		cout << "Multibyte to wide char success " << endl << "it gave ::";
		wcout << buf << endl;

	}
	else
		cout << "Multibyte to wide char failed" << endl;

	ret = WideCharToMultiByte(CP_UTF8, 0, buf, wcslen(buf), cbuf, 5, 0, 0);
	if (ret||1) {

		cout << "wide to Multibyte char success " << endl << "it gave ::  ";
		cout << cbuf << endl;

	}
	else
		cout << endl<<"wide to Multibyte char failed" << endl;

	cout << "size of ansci array" << (sizeof(arry)) << endl;
	cout << "size of wide char array" << (sizeof(warr)) << endl;
	
	getchar();
	return 0;
}