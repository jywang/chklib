#pragma once

/********************************************************************
	created:	2012/10/04
	created:	4:10:2012   14:58
	filename: 	e:\C++ Projects\chklib\01.Developments\chklib_lib\ILogStream.h
	file path:	e:\C++ Projects\chklib\01.Developments\chklib_lib
	file base:	ILogStream
	file ext:	h
	author:		JyWong
	
	purpose:	Log输出的接口类
*********************************************************************/

#include "chklib.h"

class ILogStream
{
public:
    ILogStream(void){}
    virtual void OutputDbgLog(char* lpFmt, ...) = 0;
    virtual ~ILogStream(void){}
};
