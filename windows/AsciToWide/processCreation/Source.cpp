#include <iostream>
#include<Windows.h>
#include "pch.h"


using namespace std;



int main()
{
	STARTUPINFOA startInfo1;
	PROCESS_INFORMATION processInfo1;
	

	ZeroMemory(&startInfo1, sizeof(startInfo1));
	startInfo1.cb = sizeof(startInfo1);
	ZeroMemory(&processInfo1, sizeof(processInfo1));

	LPCSTR lp1 =("C:\\Windows\\system32\\notepad.exe");

	BOOL ret1 = CreateProcessA(lp1,
		NULL,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&startInfo1,
		&processInfo1
	);

	   cout << "Handle for Notepad:" << processInfo1.hProcess << endl;
	  cout << "ID for Notepad:" << processInfo1.dwProcessId << endl << endl;	


	  STARTUPINFOA startInfo2;
	  PROCESS_INFORMATION processInfo2;
	  ZeroMemory(&startInfo2, sizeof(startInfo2));
	  startInfo1.cb = sizeof(startInfo2);
	  ZeroMemory(&processInfo2, sizeof(processInfo2));

	  LPCSTR lp2 = ("C:\\Program Files\\internet explorer\\iexplore.exe");

	  BOOL ret2 = CreateProcessA(lp2,
		  NULL,
		  NULL,
		  NULL,
		  FALSE,
		  0,
		  NULL,
		  NULL,
		  &startInfo2,
		  &processInfo2
	  );
	  if (ret2)
	  {
		  cout << "error";
	  }
	  else
	  {
		  cout << "Handle for Notepad:" << processInfo2.hProcess << endl;
		  cout << "ID for Notepad:" << processInfo2.dwProcessId << endl << endl;
	  }
	getchar();
	CloseHandle(processInfo1.hProcess);
	CloseHandle(processInfo1.hThread);

}
