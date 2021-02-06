#pragma once
#include "fwd.h"


void GetCurrentDir(void);
VOID ChangeDir(char* path);
void ListDirectoryContent(const char* path);
void ExitShell();
void CreateFolder();
void LdnCreateFile();
void OpenHelpCommand();