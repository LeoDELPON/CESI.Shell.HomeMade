#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <wtypes.h>
#include <direct.h>

#define TRUE 1
#define FALSE 0
#define KEY_ENTER 0x0D
#define KEY_DEL 0x08
#define KEY_TAB 0x09
#define KEY_LEFT_ARROW 0x25
#define KEY_RIGHT_ARROW 0x27

typedef unsigned LD_BOOL_T;
typedef struct SyntaxTree SyntaxTree;

typedef  struct _Array_t {
    char* array;
    size_t used;
    size_t size;
} Array_t;

typedef struct _CallProcess_t {
	char* keyDict;
	void* (*func)(void);
	size_t IDAssociated;
	int dictSize;
} CallProcess_t;

typedef struct _CallProcessList_t {
	CallProcess_t* process;
	size_t used;
	size_t size;
} CallProcessList_t;

struct SyntaxTree {
	char* structureElement;
	SyntaxTree* nextElement;
};

typedef struct _LimitPosBaseInput_t {
	long x;
	long y;
	int index;
} LimitPosBaseInput_t;

HANDLE hStdin, hStdout;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
DWORD fdwSaveOldMode;
