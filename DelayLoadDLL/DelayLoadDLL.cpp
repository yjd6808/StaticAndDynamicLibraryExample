#include "DelayLoadDLL.h"
#include <iostream>

PRINTAPI void __cdecl PrintHello()	{ std::cout << "Hello!" << std::endl; }
PRINTAPI void __cdecl PrintLove()	{ std::cout << "Love!" << std::endl; }