#pragma once
#include "fwd.h"


VOID CustomArrayInit(Array_t* a, size_t sizeInit);
VOID CustomArrayAddElement(Array_t* a, long element, int isSpecifiedIndex);
VOID CustomArrayFreeElement(Array_t* a);
VOID SafeFree(char* pointerToFree);
VOID CustomArrayDeleteElement(Array_t* a, size_t indexCount);
VOID CustomArrayAddEOF(Array_t* a);
char* LdnStrncpy_s(char* dest, unsigned int destLength, char* source, int sourceStart, int wordLength);