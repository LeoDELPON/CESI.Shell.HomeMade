#include "fwd.h"
#include "stringManager.h"
#include "processManager.h"
#include "cursorMotion.h"

VOID ErrorExit(LPSTR lpszMessage);
VOID GetCurrentDir(VOID);
VOID InitWelcomeMessage(VOID);

int main(void) {
    DWORD cNumRead, fdwMode, i;
    INPUT_RECORD irInBuf[128];
    int isNewCommand = 0;
    char chBuffer[1];
    int counter = 0;
    Array_t arrayElement;
    size_t indexArrayElement = 0;
    LD_BOOL_T isRunning = TRUE;
    LimitPosBaseInput_t limitStart, limitEnd;


    arrayElement.array = NULL;
    CustomArrayInit(&arrayElement, 5);

    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    if (hStdin == INVALID_HANDLE_VALUE
        || hStdout == INVALID_HANDLE_VALUE)
        ErrorExit("GetStdHandle");

    InitWelcomeMessage();
    GetCurrentDir();
    GetCursorPosition(&limitStart);
    while (isRunning)
    {
        if (!ReadConsoleInputW(
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
                if (irInBuf[i].Event.KeyEvent.wVirtualKeyCode == KEY_ENTER) {
                    EnterWriteToConsole(&arrayElement);
                    GetCursorPosition(&limitStart);
                    isNewCommand = 1;
                    indexArrayElement = 0;
                }
                MoveConsole(&irInBuf, &limitStart, &limitEnd);
                if (irInBuf[i].Event.KeyEvent.wVirtualKeyCode == KEY_DEL) {
                    limitEnd.x--;
                    CustomArrayDeleteElement(&arrayElement, arrayElement.used);
                    indexArrayElement--;
                }
                else {
                    CustomArrayAddElement(&arrayElement, irInBuf[i].Event.KeyEvent.uChar.AsciiChar, 0);
                    if (irInBuf[i].Event.KeyEvent.uChar.AsciiChar) {
                        GetCursorPosition(&limitEnd);
                    }
                    printf("%c", arrayElement.array[indexArrayElement++]);
                }
            }
        }
    }
    SetConsoleMode(hStdin, fdwSaveOldMode);
    return 0;
}