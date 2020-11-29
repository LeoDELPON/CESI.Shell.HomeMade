#pragma once
#include "fwd.h"
#include "commandShell.h"


VOID ErrorExit(LPSTR lpszMessage)
{
    fprintf(stderr, "ERROR: %s,\n ErrorNo: %d at line : %d  in the file %s", lpszMessage, errno, __LINE__, __FILE__);
    SetConsoleMode(hStdin, fdwSaveOldMode);
    ExitProcess(0);
}

VOID GetCurrentDir(VOID) {
    char* currentDir;
    if ((currentDir = _getcwd(NULL, 0)) == NULL)
        ErrorExit("_getcwd");
    else {
        printf("%s ", currentDir);
        free(currentDir);
    }
}