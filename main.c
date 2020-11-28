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

VOID ErrorExit(LPSTR lpszMessage);
VOID GetCurrentDir(VOID);
VOID InitWelcomeMessage(VOID);
VOID CustomArrayInit(Array_t* a, size_t sizeInit);
VOID CustomArrayAddElement(Array_t* a, long element);
VOID CustomArrayFreeElement(Array_t* a);
VOID safeFree(char* pointerToFree);
VOID CustomArrayDeleteLastElement(Array_t* a, size_t indexCount);

int main(VOID) {
    DWORD cNumRead, fdwMode, i;
    int isNewCommand = 0;
    INPUT_RECORD irInBuf[128];
    int counter = 0;
    Array_t arrayElement;
    size_t indexArrayElement = 0;

    arrayElement.array = NULL;
    CustomArrayInit(&arrayElement, 5);

    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    if (hStdin == INVALID_HANDLE_VALUE)
        ErrorExit("GetStdHandle");

    if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
        ErrorExit("GetConsoleMode");

    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if (!SetConsoleMode(hStdin, fdwMode))
        ErrorExit("SetConsoleMode");

    InitWelcomeMessage();
    GetCurrentDir();
    while (counter++ <= 100)
    {
        if (!ReadConsoleInput(
            hStdin,      
            irInBuf,     
            128,         
            &cNumRead)) 
            ErrorExit("ReadConsoleInput");

        if (isNewCommand == 1) {
            GetCurrentDir();
            isNewCommand = 0;
        }
        for (i = 0; i < cNumRead; i++)
        {
            if (irInBuf[i].Event.KeyEvent.bKeyDown) {
                if (irInBuf[i].Event.KeyEvent.wVirtualKeyCode == 0x0D) {
                    CustomArrayFreeElement(&arrayElement);
                    CustomArrayInit(&arrayElement, 5);
                    printf("\n");
                    isNewCommand = 1;
                    indexArrayElement = 0;
                }
                // HAS TO BE FIXED, WHEN USER BACKSPACE THE WHOLE LINE IS NOT OVVERIDE WITH THE NEW STRING -1 CHAR
                if (irInBuf[i].Event.KeyEvent.wVirtualKeyCode == 0x08) {
                    CustomArrayDeleteLastElement(&arrayElement, arrayElement.used);
                }
                else {
                    CustomArrayAddElement(&arrayElement, irInBuf[i].Event.KeyEvent.uChar.AsciiChar);
                    printf("%c", arrayElement.array[indexArrayElement++]);
                }
           }
        }
    }
    SetConsoleMode(hStdin, fdwSaveOldMode);

    return 0;
}



VOID ErrorExit(LPSTR lpszMessage)
{
    fprintf(stderr, "ERROR: %s,\n ErrorNo: %d", lpszMessage, errno);
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

VOID InitWelcomeMessage(VOID) {
    printf("Leo DELPON Company [version 0.00]\n(nc) 2020 Personnal Project. Feel Free, It is open-source :)\n\n");
}

VOID CustomArrayInit(Array_t*a, size_t sizeInit) {
    a->array = (long*)malloc(sizeInit * sizeof(long));
    a->used = 0;
    a->size = sizeInit;
}

VOID CustomArrayAddElement(Array_t* a, long element) {
    if (a->used == a->size) {
        a->size <<= 1;
        a->array = realloc(a->array, a->size * sizeof(long));
    }
    a->array[a->used] = element;
    a->used++;
}

VOID CustomArrayDeleteLastElement(Array_t* a, size_t indexActualSize) {

}

VOID CustomArrayFreeElement(Array_t* a) {
    if (!a->array)
        ErrorExit("Array memory not allocated");
    safeFree(a->array);
    a->used = a->size = 0;
}


VOID safeFree(char* pointerToFree) {
    if (!pointerToFree)
        ErrorExit("An error occured");
    free(pointerToFree);
}