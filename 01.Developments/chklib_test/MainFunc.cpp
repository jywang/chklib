#include "../chklib_lib/chklib.h"
#pragma comment(lib,"../../04.Binary/chklib_lib.lib")

#include <iostream>
#include <process.h>

using namespace std;

using namespace CHKLIB;

OLOG_SETTING(OLOG_FILE, "./log.txt");

void Function(int a,char b)
{
    FuncTrace;
    OutputFuncValueTable("Function | a = 0x%X, b = 0x%X", a, b);

    cout<<"In Function"<<endl;		//函数执行体
}

void ThreadFunc(void* param)
{
	FuncTrace;
	for(int i = 0;i < 100;++i)
	{
		OutputCyclVarValues(5, 80, 5, "%s i=%d", "Thread Function", i);
		
		cout<<"in thread"<<endl;	//循环执行体
	}
}

int main()
{
    FuncTrace;
    OutputDbgLog("%s", "use global log output");

    Function(6,10);

	_beginthread(ThreadFunc, 0, NULL);

	for(int i = 0;i < 10000;++i)
	{
		OutputCyclVarValues(5, 200, 10, "%s i=%d", "Main Function", i);

		//cout<<"in main"<<endl;		//循环执行体
	}
		

    system("pause");
	return 0;
}