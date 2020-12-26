#include "fwd.h"
#include "stringManager.h"

VOID ErrorExit(LPSTR lpszMessage);
VOID GetCurrentDir(VOID);
VOID InitWelcomeMessage(VOID);

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
                    CustomArrayAddEOF(&arrayElement);
                    CustomArrayFreeElement(&arrayElement);
                    CustomArrayInit(&arrayElement, 5);
                    printf("\n");
                    isNewCommand = 1;
                    indexArrayElement = 0;
                }
                if (irInBuf[i].Event.KeyEvent.wVirtualKeyCode == 0x08) {
                    CustomArrayDeleteElement(&arrayElement, arrayElement.used);       
                    indexArrayElement--;
                }
                else {
                    CustomArrayAddElement(&arrayElement, irInBuf[i].Event.KeyEvent.uChar.AsciiChar, 0);
                    printf("%c", arrayElement.array[indexArrayElement++]);
                }
           }
        }
    }
    SetConsoleMode(hStdin, fdwSaveOldMode);
    return 0;
}