#include "ImplicitDLL.h"
#include <iostream>

PRINTAPI void __stdcall PrintText(const char* msg) { std::cout << msg << std::endl; }
PRINTAPI void __stdcall PrintNumber(int num) { std::cout << num << std::endl; }