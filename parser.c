#include "fwd.h"
#include "parser.h"
#include "commandShell.h"


typedef struct {
	CallProcess_t* nxtDictElement;
	char* keyDict;
	void* (*func)(void);
	size_t IDAssociated;
	int dictSize;
} CallProcess_t;


DWORD ApplyCommand(Array_t* stringToBeParsed) {
	CallProcess_t listProcess;
	InitCommandArray(&listProcess);
	for (unsigned i = 0; i < listProcess.dictSize ; ++i) {
		if (strcmp(listProcess.keyDict, stringToBeParsed->array))
			listProcess.func;
	}
}


VOID InitCommandArray() {
	
}

VOID InitGetCurrentDirectory(CallProcess_t* dict) {
	dict->keyDict = "pwd";
	dict->func = (void(*)(void))GetCurrentDir;
	dict->IDAssociated = 1;
	dict->dictSize = +1;
}

VOID InitChangeDirectory(CallProcess_t* dict) {
	dict->keyDict = "cd";
	dict->func = (void(*)(void))ChangeDir;
	dict->IDAssociated = 2;
	dict->dictSize = +1;
}

VOID InitFindFilesD(CallProcess_t* dict) {

}

VOID InitExitProgram(CallProcess_t* dict) {

}




