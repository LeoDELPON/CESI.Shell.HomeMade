#include "fwd.h"
#include "parser.h"
#include "commandShell.h"


typedef struct {
	callProcess_t* nxtDictElement;
	char* keyDict;
	void* (*func)(void);
	size_t PIDAssociated;
} callProcess_t;


VOID GettingStringParser(Array_t* stringToBeParsed) {

}


VOID InitCommandArray() {
	
}

VOID InitGetCurrentDirectory(callProcess_t* dict) {
	dict->keyDict = "pwd";
	dict->func = (void(*)(void))GetCurrentDir;
	dict->PIDAssociated = 1;
}

VOID InitChangeDirectory(callProcess_t* dict) {

}

VOID InitSeeDirectory(callProcess_t* dict) {

}

VOID InitExitProgram(callProcess_t* dict) {

}




