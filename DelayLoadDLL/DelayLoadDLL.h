//�ۼ��� : ������
//����   : DLL DelayLoading Ȯ�ο�

#ifndef __DELAYLOAD_DLL_
#define __DELAYLOAD_DLL_

#ifdef DELAYLOADDLL_EXPORTS
	#define PRINTAPI __declspec(dllexport)
#else
	#define PRINTAPI __declspec(dllimport)
#endif

extern "C" PRINTAPI void __cdecl PrintHello();
extern "C" PRINTAPI void __cdecl PrintLove();

#endif //__TESTL_DLL_