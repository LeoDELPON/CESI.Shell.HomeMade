#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <wtypes.h>
#include <direct.h>

HANDLE hStdin;
DWORD fdwSaveOldMode;

typedef  struct {
    long* array;
    size_t used;
    size_t size;
} Array_t;

typedef struct {
	char* keyDict;
	void* (*func)(void);
	size_t IDAssociated;
	int dictSize;
} CallProcess_t;

typedef struct {
	CallProcess_t* process;
	size_t used;
	size_t size;
} CallProcessList_t;

typedef struct {
	char* structureElement;
	SyntaxTree* nextElement;
} SyntaxTree;