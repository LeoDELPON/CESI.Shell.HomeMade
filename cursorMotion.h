#include "fwd.h"
#include "stringManager.h"
#include "processManager.h"


void SetCursorPosition(int x, int y);
void MoveConsole(INPUT_RECORD* pIrInBuf, LimitPosBaseInput_t* lim, LimitPosBaseInput_t* limEnd);
void EnterWriteToConsole(Array_t* pArray);
void GetCursorPosition(LimitPosBaseInput_t* lim);