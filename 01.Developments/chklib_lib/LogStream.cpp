#include "LogStream.h"

//////////////////////////////////////////////////////////////////////////
// CLogStreamFile
//////////////////////////////////////////////////////////////////////////
CLogStreamFile::CLogStreamFile(char *szFileName)
{
    if(!m_FileStream.is_open())
    {
        m_FileStream.open(szFileName, ios_base::out | ios_base::app);
    }
}

void CLogStreamFile::OutputDbgLog(char* lpFmt, ...)
{
    // ����ִ�е���һЩ�ظ��Եĸ�ʽ���ַ���������ʵӦ�÷ŵ�������ȥ�ģ���������Ҫ��дһ��������bufferlen��ʵ�ڲ�����ô���� [10/4/2012 Jinyang]
    char szMsg[1024] = {0};
    char szLog[1024] = {0};
    DWORD dwProcID = GetCurrentProcessId();
    DWORD dwThreadID = GetCurrentThreadId();
    DWORD dwTime = GetTickCount();

    int nLen = vsprintf(szMsg, lpFmt, va_list(1 + &lpFmt) );
    sprintf(szLog, "[ProcessID:0x%08X | ThreadID:0x%08X][Time:%d] %s", dwProcID, dwThreadID, dwTime, szMsg);

    m_FileStream<<szLog<<endl;
}

CLogStreamFile::~CLogStreamFile()
{
    if(m_FileStream.is_open())
    {
        m_FileStream.close();
    }
}


//////////////////////////////////////////////////////////////////////////
// CLogStreamCmd
//////////////////////////////////////////////////////////////////////////
CLogStreamCmd::CLogStreamCmd()
{

}

void CLogStreamCmd::OutputDbgLog(char* lpFmt, ...)
{
    char szMsg[1024] = {0};
    char szLog[1024] = {0};
    DWORD dwProcID = GetCurrentProcessId();
    DWORD dwThreadID = GetCurrentThreadId();
    DWORD dwTime = GetTickCount();

    int nLen = vsprintf(szMsg, lpFmt, va_list(1 + &lpFmt) );
    sprintf(szLog, "[ProcessID:0x%08X | ThreadID:0x%08X][Time:%d] %s", dwProcID, dwThreadID, dwTime, szMsg);

    cout<<szLog<<endl;
}

CLogStreamCmd::~CLogStreamCmd()
{

}

//////////////////////////////////////////////////////////////////////////
// CLogStreamSys
//////////////////////////////////////////////////////////////////////////
CLogStreamSys::CLogStreamSys()
{

}

void CLogStreamSys::OutputDbgLog(char* lpFmt, ...)
{
    char szMsg[1024] = {0};
    char szLog[1024] = {0};
    DWORD dwProcID = GetCurrentProcessId();
    DWORD dwThreadID = GetCurrentThreadId();
    DWORD dwTime = GetTickCount();

    int nLen = vsprintf(szMsg, lpFmt, va_list(1 + &lpFmt) );
    sprintf(szLog, "[ProcessID:0x%08X | ThreadID:0x%08X][Time:%d] %s", dwProcID, dwThreadID, dwTime, szMsg);

    ::OutputDebugStringA(szLog);
    ::OutputDebugStringA("\n");
}

CLogStreamSys::~CLogStreamSys()
{

}