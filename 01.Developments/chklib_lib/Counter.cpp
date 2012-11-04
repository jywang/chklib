#include "Counter.h"

//////////////////////////////////////////////////////////////////////////
// CCounter
CCounter::CCounter(DWORD nThreadID)
{
	m_nCounter = 0;
	m_nThreadID = nThreadID;
	m_pCounterChild = NULL;
}

void CCounter::Add()
{
	++m_nCounter;
}

void CCounter::Add(ULONG nLen)
{
	m_nCounter += nLen;
}

void CCounter::Minus()
{
	--m_nCounter;
}

void CCounter::Minus(ULONG nLen)
{
	m_nCounter -= nLen;
}

ULONG CCounter::GetCurrentCounter()
{
	return m_nCounter;
}

DWORD CCounter::GetThreadID()
{
	return m_nThreadID;
}

CCounter* CCounter::GetChildCounter()
{
	if(NULL == m_pCounterChild)
		m_pCounterChild = new CCounter(m_nThreadID);

	return m_pCounterChild;
}

CCounter::~CCounter()
{
	delete m_pCounterChild;
}

//////////////////////////////////////////////////////////////////////////
// CCounterPool
CCounter* CCounterPool::GetCounter(DWORD dwThreadID)
{
	for(int i = 0;i < m_CounterPool.size();++i)
	{
		if(m_CounterPool[i]->GetThreadID() == dwThreadID)
		{
			return m_CounterPool[i];
		}
	}

	CCounter *pCounter = new CCounter(dwThreadID);
	m_CounterPool.push_back(pCounter);
	return pCounter;
}

CCounterPool::~CCounterPool()
{
	for(int i = 0;i < m_CounterPool.size();++i)
	{
		if(NULL != m_CounterPool[i])
		{
			delete m_CounterPool[i];
		}
	}
}