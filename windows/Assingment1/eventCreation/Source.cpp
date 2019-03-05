#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	LPCSTR name="E";
	HANDLE  h = CreateEventA(NULL, TRUE, TRUE, name);
	if (0 == GetLastError())
		cout << "handle of the event =" << h << endl << "with name " << *name;
	else
		cout << "there is error wih error id::" << GetLastError();
	getchar();
}