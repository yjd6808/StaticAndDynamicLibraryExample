//�ۼ��� : ������
//����   : IAT, EAT Ȯ�ο�

#ifndef __IMPLICIT_DLL_
#define __IMPLICIT_DLL_

#ifdef IMPLICITDLL_EXPORTS
	#define PRINTAPI __declspec(dllexport)
#else
	#define PRINTAPI __declspec(dllimport)
#endif

extern "C" PRINTAPI void __stdcall PrintText(const char*);
extern "C" PRINTAPI void __stdcall PrintNumber(int);

#endif //__TESTL_DLL_