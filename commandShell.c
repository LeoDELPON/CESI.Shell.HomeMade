#pragma once
#include "fwd.h"
#include "commandShell.h"

void GetCurrentDir(void) {
    char* currentDir;
    if ((currentDir = _getcwd(NULL, 0)) == NULL) {
        SAFE_ERROR_EXIT(currentDir);
    }
    else {
        printf("%s", currentDir);
        free(currentDir);
    }
}

VOID ChangeDir(const char* path) {
    if (!path)
        SAFE_ERROR_EXIT(path);
     if (_chdir(path)) {
         SAFE_ERROR_EXIT(path);
     }
     else {
         GetCurrentDir();
     }
}

//Not finished bc it does not find dir
void ListDirectoryContent(const char* sDir) {
    WIN32_FIND_DATAA fdFile;
    HANDLE hFind = NULL;
    wchar_t sPath[2048];
    sprintf_s(sPath, 2048, "%s\\*.*", sDir);

    if ((hFind = FindFirstFileA(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        SAFE_ERROR_EXIT(hFind);
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
    } while (FindNextFileA(hFind, &fdFile));
    FindClose(hFind);
}

VOID ExitProgramm() {

}


VOID CreateDir() {

}

VOID CreateF() {

}

VOID OpenHelpCommand() {
    puts("\n**********************************************************"
        "\n            Copyright Leo .D @ Skyso"
        "\nUse this for fun and feel free to let a star on github :)"
        "\n            List commands supported:"
        "\n            - cd"
        "\n            - ls"
        "\n            - pwd"
        "\n            - mkdir"
        "\n            - exit"
        "\n            - touch"
        "\n            - cp"
        "\n            - mv"
        "\n            - rm"
        "\n            - sudo"
        "\n            - cat"
        "\n            - ping"
        "\n            - head"
        "\n            - tail"
        "\n"
        "\nAgain, thank you to KJ for having helped me doing this shell"
        "\n************************************************************"
    );
}