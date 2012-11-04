#pragma once

/********************************************************************
	created:	2012/10/04
	created:	4:10:2012   15:01
	filename: 	e:\C++ Projects\chklib\01.Developments\chklib_lib\LogStream.h
	file path:	e:\C++ Projects\chklib\01.Developments\chklib_lib
	file base:	LogStream
	file ext:	h
	author:		JyWong
	
	purpose:	ILogStream的三种实现：文件、命令行、Windows日志
*********************************************************************/
#include "ILogStream.h"

/************************************************************************/
/* CLogStreamFile   输出流为文件                                        */
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
/* CLogStreamCmd    输出流为控制台                                      */
/************************************************************************/
class CLogStreamCmd : public ILogStream
{
public:
    CLogStreamCmd();
    void OutputDbgLog(char* lpFmt, ...);
    ~CLogStreamCmd();
};

/************************************************************************/
/*  CLogStreamSys   输出流为系统Log                                     */
/************************************************************************/
class CLogStreamSys : public ILogStream
{
public:
    CLogStreamSys();
    void OutputDbgLog(char* lpFmt, ...);
    ~CLogStreamSys();
};