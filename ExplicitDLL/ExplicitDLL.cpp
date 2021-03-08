//작성자 : 윤정도
//목적   : IAT, EAT 확인용

#include "ExplicitDLL.h"

MATHAPI int __stdcall Add(int a, int b) { return a + b; };
MATHAPI int __stdcall Sub(int a, int b) { return a - b; };
MATHAPI int __stdcall Mul(int a, int b) { return a * b; };
MATHAPI int __stdcall Div(int a, int b) { return a / b; };
