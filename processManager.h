#pragma once
#include "fwd.h"


char* StrGetter(Array_t* buffer);
DWORD ApplyCommand(Array_t* stringToBeParsed);
VOID InitCommands(CallProcessList_t* procList);
VOID InitCommandList(CallProcessList_t* list, int l);
VOID AddCommandToList(CallProcessList_t* list, CallProcess_t element);
void InitGetCurrentDirectory(CallProcess_t* dict);
void InitChangeDirectory(CallProcess_t* dict);
void InitFindFilesD(CallProcess_t* dict);
void (*p[3]) (CallProcess_t* process);