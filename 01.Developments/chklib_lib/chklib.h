/***********************************
* ����ͷ�ļ�
* JyWong
***********************************/

#ifndef _CHKLIB_H_

#define _CHKLIB_H_

#include <Windows.h>
#include <iostream>
#include <fstream>

using namespace std;

//////////////////////////////////////////////////////////////////////////
//��ӡ������Ϣ
//////////////////////////////////////////////////////////////////////////

#define OLOG_TYPE UINT

#define OLOG_FILE		0x01	//��������Ϣ��ӡ���ļ���
#define OLOG_CONSOLE	0x02	//					console����̨
#define OLOG_WINLOG		0x03	//					windows logs

namespace CHKLIB{


/**
* ����ȫ�ֵ�����Ϣ�������
*   arg1�������ʽ
*   arg2������ļ����������ʽΪ�ļ�ʱ��Ч��
*/
void _cdecl SetGlobalLogType(UINT nType, char* szFilePath);

/**
* ����ȫ�ֵ�����Ϣ�������
*/
class COLogSettings
{
public:
	COLogSettings();
	COLogSettings(UINT nType, char* szFilePath);
};
#define OLOG_SETTING(TYPE, PATH)	 COLogSettings settings(TYPE, PATH)

/**
* ��ʽ����ӡ������Ϣ��ȫ�֣�
*   args:��ʽ���ַ���
*/
int _cdecl OutputDbgLog(char* lpFmt, ...);


/**
* �������������
*   args����ʽ���ַ���
*/
void _cdecl OutputFuncValueTable(char* lpFmt, ...);

/**
* ���ݲ������ѭ���е�ָ��������ֵ
*	arg1���ӵ�nBegin��ѭ����ʼ���
*	arg2����nEnd��ѭ����ֹͣ���
*	arg3��������ָ��ÿѭ�����ٴ����һ�α���ֵ
*	arg4����ʽ���ַ���
*/
void _cdecl OutputCyclVarValues(ULONG nBegin, ULONG nEnd, ULONG nStep, char* lpFmt, ...);


/**
* ���ڸ��ٺ����������������ȫ������
* �÷���
*       �ں�������ִ��FuncTrace��
* ע��
*       �ú��������c++
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
//����
//////////////////////////////////////////////////////////////////////////



}//end namespace chklib


#endif