#include<iostream>
#include<windows.h>
#include "tchar.h"
using namespace std;
DWORD WINAPI threadFunction(LPVOID lpParam)
{
	cout << endl<<"this is a thread function";
	cout << endl << "secondary thread id:::" << GetCurrentThreadId() << endl;
    //Sleep(5000);
	ExitThread(10);
	return 0;
}


int main(int argc, char *argv[])
{
	DWORD param = 10, *ptr, tId;
	ptr = &param;

	handle_t hThread = CreateThread(NULL, 0, threadFunction, ptr, CREATE_SUSPENDED, &tId);
	ResumeThread(hThread);
	DWORD waitReturns = WaitForSingleObject(hThread, INFINITE);
	DWORD exitStatus;
	//TerminateThread(hThread, 999);
	cout << endl << "secondary exit code(boolean value):::" << GetExitCodeThread(hThread, &exitStatus);
	cout<<endl<<"exit status  as given::"<< exitStatus << endl;

	if (GetLastError() == 0)
	{
		cout << endl <<"primary thread id:::"<<GetCurrentThreadId()<< endl;
		
	}
	else
		cout << "ended up due to error id::" << GetLastError();
	getchar();
}
