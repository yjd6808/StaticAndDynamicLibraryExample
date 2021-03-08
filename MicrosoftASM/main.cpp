//작성자 : 윤정도
//작성자 : IAT, EAT 확인용

#include <iostream>
#include <Windows.h>

//DLL 딜레이 로딩을 사용하기 위해
#pragma comment(lib, "delayimp")

#ifdef _DEBUG
	#pragma comment(lib, "../Debug/ImplicitDLL.lib")
	#pragma comment(lib, "../Debug/StaticLib.lib")
	#pragma comment(lib, "../Debug/DelayLoadDLL.lib")
#else
	#pragma comment(lib, "../Release/ImplicitDLL.lib")
	#pragma comment(lib, "../Release/DelayLoadDLL.lib")
	#pragma comment(lib, "../Release/StaticLib.lib")
#endif

#include "ImplicitDLL.h"
#include "DelayLoadDLL.h"
#include "StaticLib.h"

bool ExplicitDLLExample();
bool ImplicitDLLExample();
bool DelayLoadDLLExample();
bool StaticLibExample();

int main()
{
	if ( ! ExplicitDLLExample() )
		return -1;

	if ( ! ImplicitDLLExample() )
		return -1;

	if ( ! StaticLibExample() )
		return -1;

	if ( ! DelayLoadDLLExample() )
		return -1;

	std::cout << "모든 함수가 정상적으로 실행되었습니다." << std::endl;
	return 0;
}

bool ExplicitDLLExample()
{
	std::cout << "[ExplicitDLLExample]" << std::endl;

	std::string environment_path(MAX_PATH, NULL);
	GetModuleFileName(NULL, &environment_path[0], MAX_PATH);

	if (SetDllDirectory(environment_path.c_str()) == false)
	{
		std::cout << environment_path << " : DLL 디렉토리 세팅 실패!" << std::endl;
		return false;
	}

	//명시적 DLL 로딩(Explicit Linking)
	HMODULE testdll_module = LoadLibrary("ExplicitDLL.dll");

	if (testdll_module == NULL)
	{
		std::cout << "ExplicitDLL.dll 로딩 실패했당께!(" << GetLastError() << ")" << std::endl;
		return false;
	}

	typedef int(__stdcall* ExplicitDLLProc)(int, int);

	// stdcall 호출규약을 따르므로 함수명을 호출 규약형식에 맞게 해줘야함.
	ExplicitDLLProc FnAdd = reinterpret_cast<ExplicitDLLProc>(GetProcAddress(testdll_module, "_Add@8"));
	ExplicitDLLProc FnSub = reinterpret_cast<ExplicitDLLProc>(GetProcAddress(testdll_module, "_Sub@8"));
	ExplicitDLLProc FnMul = reinterpret_cast<ExplicitDLLProc>(GetProcAddress(testdll_module, "_Mul@8"));
	ExplicitDLLProc FnDiv = reinterpret_cast<ExplicitDLLProc>(GetProcAddress(testdll_module, "_Div@8"));

	if (FnAdd == NULL)
	{
		std::cout << "Add 함수를 찾지 못했습니다." << std::endl;
		return false;
	}

	// ExplicitDLL 함수 사용
	std::cout << FnAdd(1, 2) << std::endl;
	std::cout << FnSub(2, 4) << std::endl;
	std::cout << FnMul(1, -5) << std::endl;
	std::cout << FnDiv(3, 7) << std::endl;

	if (FreeLibrary(testdll_module) == false)
	{
		std::cout << "TestDLL.dll 해제 실패 !" << std::endl;
		return false;
	}

	std::cout << "==================================\n" << std::endl;

	return true;
}

bool ImplicitDLLExample()
{
	std::cout << "[ImplicitDLLExample]" << std::endl;

	// ImplicitDLL 함수 사용
	PrintNumber(1);
	PrintText("Hello World!");

	std::cout << "==================================\n" << std::endl;

	return true;
}

bool StaticLibExample()
{
	std::cout << "[StaticLibExample]" << std::endl;

	std::string text(50, NULL);

	// StaticLib 함수 사용 - 정적 라이브러리 함수 호출
	if (WriteText("Text.txt", "Hello World!") < 0)
		return false;

	if (ReadText("Text.txt", &text[0]) < 0)
		return false;

	std::cout << "읽은 텍스트 : " << text << std::endl;
	std::cout << "==================================\n" << std::endl;

	return true;
}

bool DelayLoadDLLExample()
{
	std::cout << "[DelayLoadDLLExample]" << std::endl;

	PrintHello();
	PrintLove();

	std::cout << "==================================\n" << std::endl;

	return true;
}