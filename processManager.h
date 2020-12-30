#pragma once
#include "fwd.h"

void ApplyCommand(Array_t* stringToBeParsed);
void InitCommands(CallProcessList_t* procList);
void InitCommandList(CallProcessList_t* list, int l);
void AddCommandToList(CallProcessList_t* list, CallProcess_t element);
void InitGetCurrentDirectory(CallProcess_t* process);
void InitChangeDirectory(CallProcess_t* process);
void InitFindFilesD(CallProcess_t* process);
void (*p[3]) (CallProcess_t* process);
void InitExitProgram(CallProcess_t* process);
void InitCreateDirectory(CallProcess_t* process);
void FreeCallProcess(CallProcess_t* process);