/***********************************
* 共享头文件
* JyWong
***********************************/

#ifndef _CHKLIB_H_

#define _CHKLIB_H_

#include <Windows.h>
#include <iostream>
#include <fstream>

using namespace std;

//////////////////////////////////////////////////////////////////////////
//打印调试信息
//////////////////////////////////////////////////////////////////////////

#define OLOG_TYPE UINT

#define OLOG_FILE		0x01	//将调试信息打印至文件中
#define OLOG_CONSOLE	0x02	//					console控制台
#define OLOG_WINLOG		0x03	//					windows logs

namespace CHKLIB{


/**
* 设置全局调试信息输出类型
*   arg1：输出方式
*   arg2：输出文件（当输出方式为文件时有效）
*/
void _cdecl SetGlobalLogType(UINT nType, char* szFilePath);

/**
* 设置全局调试信息输出类型
*/
class COLogSettings
{
public:
	COLogSettings();
	COLogSettings(UINT nType, char* szFilePath);
};
#define OLOG_SETTING(TYPE, PATH)	 COLogSettings settings(TYPE, PATH)

/**
* 格式化打印调试信息（全局）
*   args:格式化字符串
*/
int _cdecl OutputDbgLog(char* lpFmt, ...);


/**
* 输出函数参数表
*   args：格式化字符串
*/
void _cdecl OutputFuncValueTable(char* lpFmt, ...);

/**
* 根据步数输出循环中的指定变量的值
*	arg1：从第nBegin次循环开始输出
*	arg2：第nEnd次循环后停止输出
*	arg3：步长，指定每循环多少次输出一次变量值
*	arg4：格式化字符串
*/
void _cdecl OutputCyclVarValues(ULONG nBegin, ULONG nEnd, ULONG nStep, char* lpFmt, ...);


/**
* 用于跟踪函数调用情况，服从全局设置
* 用法：
*       在函数首行执行FuncTrace宏
* 注：
*       该宏仅适用于c++
*/
class CTracer
{
public:
    CTracer(char*);
    ~CTracer();
private:
    char *m_szFuncName;
    char *m_pSpace;
    static int m_nCount;
};
#define FuncTrace CTracer func_trace(__FUNCTION__); 

//////////////////////////////////////////////////////////////////////////
//其他
//////////////////////////////////////////////////////////////////////////



}//end namespace chklib


#endif