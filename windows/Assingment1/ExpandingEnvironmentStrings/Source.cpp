#include<windows.h>
#include<iostream>

#define Max 100
#include "tchar.h"
using namespace std;
int _tmain(int argc, TCHAR *argv[], TCHAR *evar[])
{
	//implementing get command line function
	cout << endl << "value in argc(number of args)=" << argc << endl;
	LPWSTR *lp = CommandLineToArgvW(GetCommandLine(), &argc);
	int itr = 0;
	cout << endl << "the args are  " << endl;
	if (argc > 0)
		while (itr < argc) {
			wcout << *lp[itr] << " ";
			itr++;
		}
	else
		cout << endl << "insufficient args" << endl;

	//environment string expansions
	LPCTSTR src = L"%systemroot%";
	TCHAR buff[Max];
	DWORD s1 = ExpandEnvironmentStrings(src, buff, Max);
	wcout << endl << "expanding the variable name gave us" << endl << s1 << " chars which are stored into output buffer " << endl;
	wcout << "expanded output buffer " << buff << endl;

	
	getchar();
	return 0;
}