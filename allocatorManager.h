#include "fwd.h"


void* LdnMalloc(size_t size);
void* LdnMemset(void* ptr, int value, size_t count);
void* LdnMemcpy_s(void* dest, size_t destSize, const void* src, size_t count);