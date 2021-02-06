#include "fwd.h"
#include "processManager.h"
#include "commandShell.h"
#include "stringParser.h"

void ExecuteCommand(LIST_PARSED_T* listOfParsedWords) {
	CustomCommandLinkedList_t* listProcess;
	CustomCommandLinkedList_t* currentList;
	listProcess = NULL;
	currentList = NULL;
	currentList = (CustomCommandLinkedList_t*)malloc(sizeof(CustomCommandLinkedList_t));
	listProcess = (CustomCommandLinkedList_t*)malloc(sizeof(CustomCommandLinkedList_t));
	if (!currentList) SAFE_ERROR_EXIT(currentList);
	if (!listProcess) SAFE_ERROR_EXIT(listProcess);
	listProcess->nextElement = NULL;
	InitializeProcessList(&listProcess);
	currentList = listProcess;
	while (currentList->nextElement != NULL && strcmp(listOfParsedWords->structureElement, listProcess->function->commandMatch)) {
		currentList = currentList->nextElement;
	}
	currentList->function->opt;
}

CustomCommandLinkedList_t InitializeProcessList(CustomCommandLinkedList_t* list) {
	CustomFunctionPtr functionTab[CUSTOM_CALL_NUMBER] = { &GetCurrentDir, &ChangeDir, &ListDirectoryContent };

}