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
    LD_BOOL_T isRunning = TRUE, isLeftArrow;
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
    limitStart.index = 0;
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
            GetCursorPosition(&limitStart);
            isNewCommand = 0;
        }
        for (i = 0; i < cNumRead; i++)
        {
            if (irInBuf[i].Event.KeyEvent.bKeyDown) {
                if (irInBuf[i].Event.KeyEvent.wVirtualKeyCode == KEY_ENTER) {
                    EnterWriteToConsole(&arrayElement, &limitStart);
                    isNewCommand = 1;
                    limitStart.index = 0;
                }
                MoveConsole(&irInBuf, &limitStart, &limitEnd);
                if (irInBuf[i].Event.KeyEvent.wVirtualKeyCode == KEY_DEL) {
                    limitEnd.x--;
                    CustomArrayDeleteElement(&arrayElement, arrayElement.used);
                    limitStart.index--;
                }
                if (irInBuf[i].Event.KeyEvent.uChar.AsciiChar) {
                    GetCursorPosition(&limitEnd);
                    CustomArrayAddElement(&arrayElement, irInBuf[i].Event.KeyEvent.uChar.AsciiChar, 0);
                    printf("%c", arrayElement.array[limitStart.index++]);
                }
            }
        }
    }
    SetConsoleMode(hStdin, fdwSaveOldMode);
    return 0;
}