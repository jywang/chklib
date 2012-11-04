#include "LogStreamCtrl.h"

bool CLogStreamCtrl::SetLogStream(OLOG_TYPE nLogType, char* szFileName)
{
    if(NULL != m_pLogStm)
    {
        MessageBox(NULL, TEXT("��������������Ϣʱ��˵�������ĳ������ζ�����־��������������Ƽ���������Ӱ��ʹ��"), TEXT("����"), MB_OK);
        delete m_pLogStm;
    }
    switch (nLogType)
    {
    case OLOG_FILE:
        {
            if(NULL == szFileName)
                return false;
            m_pLogStm = new CLogStreamFile(szFileName);
            break;
        }
    case OLOG_CONSOLE:
        {
            m_pLogStm = new CLogStreamCmd();
            break;
        }
    case OLOG_WINLOG:
        {
            m_pLogStm = new CLogStreamSys();
            break;
        }
    default:
        return false;
    }

    return true;
}

void CLogStreamCtrl::OutputDbgLog(char* lpFmt, ...)
{
    char strTmp[1024] = {0};
    if(NULL == lpFmt)
    {
        strcpy(strTmp, "\n");
    }
    else
    {
        va_list args;
        va_start(args, lpFmt);

        _vsnprintf(strTmp, 1024, lpFmt, args);
        va_end(args);
    }
    

    m_pLogStm->OutputDbgLog(strTmp);
}

CLogStreamCtrl::~CLogStreamCtrl()
{
    if(NULL != m_pLogStm)
        delete m_pLogStm;
}

