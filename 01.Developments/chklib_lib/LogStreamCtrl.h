#pragma once

/********************************************************************
	created:	2012/10/04
	created:	4:10:2012   15:26
	filename: 	e:\C++ Projects\chklib\01.Developments\chklib_lib\LogStreamCtrl.h
	file path:	e:\C++ Projects\chklib\01.Developments\chklib_lib
	file base:	LogStreamCtrl
	file ext:	h
	author:		JyWong
	
	purpose:	���ڲ�ͬ�����ʽ������Ŀ��ƣ���ʵ�ֲ��õ���ģʽ,������Ĵ������ù���ģʽ(ò�ƣ�)
*********************************************************************/
#include "chklib.h"
#include "LogStream.h"

class CLogStreamCtrl
{
public:
    static CLogStreamCtrl & Instance()
    {
        static CLogStreamCtrl LogStm;

        return LogStm;
    }

    bool SetLogStream(OLOG_TYPE, char*);
    void OutputDbgLog(char* lpFmt, ...);
    ~CLogStreamCtrl();
private:
    CLogStreamCtrl(){}
    ILogStream *m_pLogStm;
};
#define LOGSTM CLogStreamCtrl::Instance()