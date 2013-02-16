#include "chklib.h"
#include "Counter.h"
#include "LogStreamCtrl.h"

#include <stdio.h>
#include <stdarg.h>

//////////////////////////////////////////////////////////////////////////
// 全局变量

//////////////////////////////////////////////////////////////////////////
namespace CHKLIB{

void SetGlobalLogType(UINT nType, char* szFilePath)
{
    LOGSTM.SetLogStream(nType, szFilePath);
}

COLogSettings::COLogSettings()
{
	SetGlobalLogType(OLOG_FILE, "./log.txt");

}

COLogSettings::COLogSettings(UINT nType, char* szFilePath)
{
	SYSTEMTIME sysTime;

	GetLocalTime(&sysTime);
	SetGlobalLogType(nType, szFilePath);
	LOGSTM.OutputDbgLog(NULL);
	LOGSTM.OutputDbgLog("--------------------------------------------------------------");
	LOGSTM.OutputDbgLog("[%d-%d-%d		%02d:%02d:%02d]", sysTime.wYear, sysTime.wMonth, sysTime.wDay, sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
	LOGSTM.OutputDbgLog("--------------------------------------------------------------");
}


int CTracer::m_nCount = 1;
CTracer::CTracer(char *szFuncName)
{
    /*m_pSpace = new char[m_nCount + 2];
    memset(m_pSpace, 0, m_nCount + 2);
    memset(m_pSpace, '-', m_nCount);
    m_pSpace[m_nCount] = '>';*/

    LOGSTM.OutputDbgLog("Enter ---> %s", szFuncName);
    m_szFuncName = new char[(strlen(szFuncName) + 1)];
    strcpy(m_szFuncName, szFuncName);

    /*++m_nCount;*/
}
CTracer::~CTracer()
{
    LOGSTM.OutputDbgLog("Leave ---> %s", m_szFuncName);
    /*--m_nCount;
    delete[] m_szFuncName;*/
}


int OutputDbgLog(char* lpFmt, ...)
{
    va_list args;
    va_start(args, lpFmt);
    char strTmp[1024] = {0};
    _vsnprintf(strTmp, 1024, lpFmt, args);
    va_end(args);

    LOGSTM.OutputDbgLog(strTmp);

    return 0;
}

//void OutputFuncValueTable(char* lpFmt, ...)
//{
//	va_list args;
//	va_start(args, lpFmt);
//	char strTmp[1024] = {0};
//	_vsnprintf(strTmp, 1024, lpFmt, args);
//	va_end(args);
//	LOGSTM.OutputDbgLog(strTmp);
//}

void OutputCyclVarValues(ULONG nBegin, ULONG nEnd, ULONG nStep, char* lpFmt, ...)
{
	CCounter *pCurCounter = CPINST.GetCounter(GetCurrentThreadId());
	pCurCounter->Add();
	if(nBegin < pCurCounter->GetCurrentCounter() && nEnd > pCurCounter->GetCurrentCounter())
	{
		if(0 == pCurCounter->GetChildCounter()->GetCurrentCounter()%nStep)
		{
			va_list args;
			va_start(args, lpFmt);
			char strTmp[1024] = {0};
			_vsnprintf(strTmp, 1024, lpFmt, args);
			va_end(args);
			LOGSTM.OutputDbgLog(strTmp);//va_list(1 + &lpFmt));
		}
		pCurCounter->GetChildCounter()->Add();
		
	}
}

}//end namespace chklib