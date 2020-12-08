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
        ErrorExit("[-] _getcwd");
    else {
        printf("%s ", currentDir);
        free(currentDir);
    }
}

VOID ChangeDir(const char* path) {
     if (!path)
         ErrorExit("[-] ChangeDir \n");
     if (_chdir(path)) {
         switch (errno) {
         case ENOENT:
             ErrorExit("[-] Unable to locate the directory : %s\n", path);
             break;
         case EINVAL:
             printf("[-] Invalid buffer.\n");
             break;
         default:
             printf("[-] Error unkown. \n");
         }
     }
     else {
         GetCurrentDir();
     }
}

//Not finished bc it does not find dir
int ListDirectoryContent(const char* sDir) {
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;

    char sPath[2048];

    sprintf_s(sPath, 2048, "%s\\*.*", sDir);

    if ((hFind = FindFirstFile((LPCWSTR)sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        printf("Path not found: [%s]\n", sDir);
        return 0;
    }

    do
    {
        if (strcmp((char*)fdFile.cFileName, ".") != 0
            && strcmp((char*)fdFile.cFileName, "..") != 0)
        {

            sprintf_s(sPath, 2048, "%s\\%s", sDir, (char*)fdFile.cFileName);
            if (fdFile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                printf_s("Directory: %s\n", sPath);
            }
            else {
                printf_s("File: %s\n", sPath);
            }
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    return 1;
}

VOID ExitProgramm() {

}


VOID CreateDir() {

}

VOID CreateF() {

}