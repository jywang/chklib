#ifndef _COUNTER_H_
#define  _COUNTER_H_

#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class CCounter
{
public:
	CCounter(DWORD);
	void Add();
	void Add(ULONG);
	void Minus();
	void Minus(ULONG);
	ULONG GetCurrentCounter();
	DWORD GetThreadID();
	CCounter* GetChildCounter();
	~CCounter();
public:
	CCounter *m_pCounterChild;
private:
	ULONG m_nCounter;
	DWORD m_nThreadID;
	
};

/**
* 使用了单例模式的计数器池
*/
class CCounterPool
{
public:
	static CCounterPool & Instance()
	{
		static CCounterPool cp;
		return cp;
	}

	CCounter* GetCounter(DWORD);

	~CCounterPool();

private:
	CCounterPool(){}
	vector<CCounter*> m_CounterPool;
};
#define CPINST CCounterPool::Instance()


#endif