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

#define SAFE_FREE(x) if(x) {free(x); x=NULL;}

#define SAFE_ERROR_EXIT_STRING_1_ARG(arg) {char buff[256];fprintf(stderr, "[-] ERROR on %s function\n[-] %s=%s \n[-] ErrorNo: %d at line : %d in the file %s\n[-] Message: %s",__func__ , #arg, arg ,errno, __LINE__, __FILE__, strerror_s(buff, 256, errno)); exit(EXIT_FAILURE);}
#define SAFE_ERROR_EXIT_STRING_2_ARGS(arg1, arg2) {char buff[256]; fprintf(stderr, "[-] ERROR on %s function\n[-] %s=%s | %s=%s \n[-] ErrorNo: %d at line : %d in the file %s\n[-] Message: %s",__func__ , #arg1, arg1, #arg2, arg2, errno, __LINE__, __FILE__, strerror_s(buff, 256, errno)); exit(EXIT_FAILURE);}
#define SAFE_ERROR_EXIT_STRING_3_ARGS(arg1, arg2, arg3) {char buff[256]; fprintf(stderr, "[-] ERROR on %s function\n[-] %s=%s | %s=%s | %s=%s \n[-] ErrorNo: %d at line : %d in the file %s\n[-] Message: %s",__func__ , #arg1, arg1, #arg2, arg2, #arg3, arg3 ,errno, __LINE__, __FILE__, strerror(buff, 256, errno)); exit(EXIT_FAILURE);}
#define GET_4TH_ARG(arg1, arg2, arg3, arg4, ...) arg4
#define PRINT_STRING_MACRO_CHOOSER(...) GET_4TH_ARG(__VA_ARGS__, SAFE_ERROR_EXIT_STRING_3_ARGS, SAFE_ERROR_EXIT_STRING_2_ARGS ,SAFE_ERROR_EXIT_STRING_1_ARG)

#define SAFE_ERROR_EXIT(...) PRINT_STRING_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)

#define SAFE_MALLOC(x,y,z) if(!((x)=malloc(y * z))) {SAFE_ERROR_EXIT(x);}

typedef unsigned LD_BOOL_T;

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

typedef struct _List_Parsed_t {
	char* structureElement;
	struct _List_Parsed_t* nextElement;
} LIST_PARSED_T;

typedef struct _LimitPosBaseInput_t {
	long x;
	long y;
	int index;
} LimitPosBaseInput_t;

HANDLE hStdin, hStdout;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
DWORD fdwSaveOldMode;
