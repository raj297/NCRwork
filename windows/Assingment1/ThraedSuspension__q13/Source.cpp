#include<iostream>
#include<windows.h>
#include "tchar.h"
using namespace std;
DWORD WINAPI threadFunction(LPVOID lpParam)
{
	cout << "this is a thread function";
	Sleep(5000);
		for (int i = 0;i < 10;i++)
			cout << "--" << i << "--" << endl;
	
	return 0;
}

/*HANDLE CreateThread(
  LPSECURITY_ATTRIBUTES   lpThreadAttributes,
  SIZE_T                  dwStackSize,
  LPTHREAD_START_ROUTINE  lpStartAddress,
  __drv_aliasesMem LPVOID lpParameter,
  DWORD                   dwCreationFlags,
  LPDWORD                 lpThreadId
);*/
int main(int argc, char *argv[])
{
	DWORD param = 10, *ptr, tId;
	ptr = &param;

	handle_t hThread = CreateThread(NULL,0, threadFunction, ptr, CREATE_SUSPENDED, &tId);
	ResumeThread(hThread);

	if (GetLastError() == 0)
	{
		cout << hThread << endl;
		
	}
	else
		cout << "ended up due to error id::" << GetLastError();
getchar();
}
