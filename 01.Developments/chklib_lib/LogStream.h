#pragma once

/********************************************************************
	created:	2012/10/04
	created:	4:10:2012   15:01
	filename: 	e:\C++ Projects\chklib\01.Developments\chklib_lib\LogStream.h
	file path:	e:\C++ Projects\chklib\01.Developments\chklib_lib
	file base:	LogStream
	file ext:	h
	author:		JyWong
	
	purpose:	ILogStream������ʵ�֣��ļ��������С�Windows��־
*********************************************************************/
#include "ILogStream.h"

/************************************************************************/
/* CLogStreamFile   �����Ϊ�ļ�                                        */
/************************************************************************/
class CLogStreamFile : public ILogStream
{
public:
    CLogStreamFile(char *);
    void OutputDbgLog(OLOG_TYPE nType, char* szDirectory, char* lpFmt, ...);
    void OutputDbgLog(char* lpFmt, ...);
    ~CLogStreamFile();
private:
    fstream m_FileStream;
};

/************************************************************************/
/* CLogStreamCmd    �����Ϊ����̨                                      */
/************************************************************************/
class CLogStreamCmd : public ILogStream
{
public:
    CLogStreamCmd();
    void OutputDbgLog(char* lpFmt, ...);
    ~CLogStreamCmd();
};

/************************************************************************/
/*  CLogStreamSys   �����ΪϵͳLog                                     */
/************************************************************************/
class CLogStreamSys : public ILogStream
{
public:
    CLogStreamSys();
    void OutputDbgLog(char* lpFmt, ...);
    ~CLogStreamSys();
};