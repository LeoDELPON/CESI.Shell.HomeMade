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