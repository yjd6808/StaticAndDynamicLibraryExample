//�ۼ��� : ������
//����   : IAT, EAT Ȯ�ο�

#ifndef __EXPLICIT_DLL_
#define __EXPLICIT_DLL_

#ifdef EXPLICITDLL_EXPORTS
	#define MATHAPI __declspec(dllexport)
#endif

extern "C" MATHAPI int __stdcall Add(int, int);
extern "C" MATHAPI int __stdcall Sub(int, int);
extern "C" MATHAPI int __stdcall Mul(int, int);
extern "C" MATHAPI int __stdcall Div(int, int);

#endif //__TESTL_DLL_