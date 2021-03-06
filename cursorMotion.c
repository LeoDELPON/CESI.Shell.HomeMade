#include "cursorMotion.h"
#include "processManager.h"


void SetCursorPosition(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(hStdout, coord);
}

void MoveConsole(INPUT_RECORD* pIrInBuf, LimitPosBaseInput_t* lim, LimitPosBaseInput_t* limEnd) {
	CONSOLE_SCREEN_BUFFER_INFO psbi;
	GetConsoleScreenBufferInfo(hStdout, &psbi);
	if (pIrInBuf[0].Event.KeyEvent.wVirtualKeyCode == KEY_LEFT_ARROW && (lim->x < psbi.dwCursorPosition.X)) {
		lim->index--;
		SetCursorPosition(psbi.dwCursorPosition.X - 1, psbi.dwCursorPosition.Y);
	}
	if (pIrInBuf[0].Event.KeyEvent.wVirtualKeyCode == KEY_RIGHT_ARROW && (psbi.dwCursorPosition.X < limEnd->x)) {
		lim->index++;
		SetCursorPosition(psbi.dwCursorPosition.X + 1, psbi.dwCursorPosition.Y);
	}
}


void GetCursorPosition(LimitPosBaseInput_t* lim) {
	CONSOLE_SCREEN_BUFFER_INFO psbi;
	GetConsoleScreenBufferInfo(hStdout, &psbi);
	lim->x = psbi.dwCursorPosition.X;
	lim->y = psbi.dwCursorPosition.Y;
}


void GetHistoricCommand(INPUT_RECORD* pIrInBuf) {

}