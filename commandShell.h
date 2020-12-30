#pragma once
#include "fwd.h"


void GetCurrentDir(void);
VOID ErrorExit(LPSTR lpszMessage);
VOID ChangeDir(char* path);
int ListDirectoryContent(const char* path);