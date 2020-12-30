#include "fwd.h"
#include "processManager.h"
#include "commandShell.h"
#include "stringParser.h"

void ApplyCommand(Array_t* stringToBeParsed) {
	CallProcessList_t listProcess;
	//InitCommands(&listProcess);
	SyntaxTree tree;
	StrParser(stringToBeParsed ,&tree);

	//for (unsigned i = 0; i < listProcess.dictSize ; ++i) {
	//	if (strcmp(listProcess.keyDict, stringToBeParsed->array))
	//		listProcess.func;
	//}
}


VOID InitCommands(CallProcessList_t* procList) {
	InitCommandList(procList, 5);
	CallProcess_t proc;
	p[0] = InitGetCurrentDirectory;
	p[1] = InitChangeDirectory;
	p[2] = InitFindFilesD;
	for (unsigned i = 0; i < 3; ++i) {
		(*p[i])(&proc);
		AddCommandToList(procList, proc);
		FreeCallProcess(&proc);
	}
}

VOID InitCommandList(CallProcessList_t* list, int l) {
	list->process = (CallProcess_t*)malloc(sizeof(CallProcess_t) * l);
	list->used = 0;
	list->size = l;
}

VOID AddCommandToList(CallProcessList_t* list, CallProcess_t element) {
	if (!list)
		ErrorExit("The process couldn't be had to the processList");
	if (list->used == list->size) {
		list->size <<= 1;
		list->process = realloc(list->process, list->size * sizeof(CallProcess_t));
	}
	else {
		list->process[list->used] = element;
		list->used++;
	}
}

void InitGetCurrentDirectory(CallProcess_t* proc) {
	proc->keyDict = "pwd";
	proc->func = (void(*)(void))GetCurrentDir;
	proc->IDAssociated = 1;
	proc->dictSize++;
}

void InitChangeDirectory(CallProcess_t* proc) {
	proc->keyDict = "cd";
	proc->func = (void(*)(void))ChangeDir;
	proc->IDAssociated = 2;
	proc->dictSize++;
}

void InitFindFilesD(CallProcess_t* proc) {
	proc->keyDict = "ls";
	proc->func = (void(*)(void))ListDirectoryContent;
	proc->IDAssociated = 3;
	proc->dictSize++;
}


void FreeCallProcess(CallProcess_t* process) {

}


void InitExitProgram(CallProcess_t* process) {

}


void InitCreateDirectory(CallProcess_t* process) {

}


