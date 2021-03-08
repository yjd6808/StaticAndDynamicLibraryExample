// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include <Windows.h>
#include <iostream>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		std::cout << "ExplicitDLL.dll Attatched !" << std::endl;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
		std::cout << "ExplicitDLL.dll Detached !" << std::endl;
        break;
    }
    return TRUE;
}

