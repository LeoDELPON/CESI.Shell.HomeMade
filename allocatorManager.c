#include "allocatorManager.h"


void* LdnMalloc(size_t size) {
	void* ptrMalloc = malloc(size);
	if (!ptrMalloc) SAFE_ERROR_EXIT(ptrMalloc);
	LdnMemset(ptrMalloc, 0, size);
	return ptrMalloc;
}


void* LdnMemset(void* ptr, int value, size_t count) {
	size_t i;
	unsigned char* tmp;

	tmp = ptr;
	i = 0;
	while (i < count) {
		tmp[i] = value;
		++i;
	}
	ptr = tmp;
	return ptr;
}

void* LdnMemcpy_s(void* dest, size_t destSize, const void* src, size_t count) {
	if (destSize < count) SAFE_ERROR_EXIT(dest, src);
	char* ptrSrc;
	char* ptrDest;
	size_t i = 0;

	ptrSrc = (char*)src;
	ptrDest = (char*)dest;

	while (i < count) {
		ptrDest[i] = ptrSrc[i];
		++i;
	}

	dest = ptrDest;
	return dest;
}