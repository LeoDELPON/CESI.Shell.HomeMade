#pragma once
#include "fwd.h"


VOID GetCurrentDir(VOID);
VOID ErrorExit(LPSTR lpszMessage);
VOID ChangeDir(char* path);
int ListDirectoryContent(const char* path);