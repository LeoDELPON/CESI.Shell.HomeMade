#pragma once
#include "fwd.h"


void GetCurrentDir(void);
VOID ChangeDir(char* path);
int ListDirectoryContent(const char* path);