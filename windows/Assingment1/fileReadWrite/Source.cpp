#include<windows.h>
#include<iostream>
#include "tchar.h"
using namespace std;
int _tmain(int argc, TCHAR *argv[], TCHAR **evar[])
{

	handle_t hFile = CreateFileA("abc.txt", GENERIC_ALL, 0, NULL, 3, FILE_ATTRIBUTE_NORMAL, NULL);
	wcout << hFile << GetLastError();
	TCHAR fileBuff[100];
	ZeroMemory(fileBuff, 100);
	LPCVOID writeTofile = "hello";
	DWORD num ;
	LPDWORD ptr = &num;
	BOOL RET = ReadFile(hFile, fileBuff, 100, ptr, NULL);
	cout << endl <<"ptr=="<< *ptr <<"return=="<< RET << GetLastError();
	printf("%s", fileBuff);
	cout << endl << "writing to file " << endl;
	BOOL WRT = WriteFile(hFile, writeTofile, 6, 0, NULL);
	cout << endl << WRT << GetLastError();
	cout << "done";
	getchar();
	return 0;
}