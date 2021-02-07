#include "fwd.h"
#include "processManager.h"
#include "commandShell.h"
#include "stringParser.h"
#include "allocatorManager.h"

void ExecuteCommand(LIST_PARSED_T* listOfParsedWords) {
	CustomCommandLinkedList_t*  currentList = (CustomCommandLinkedList_t*)LdnMalloc(sizeof(CustomCommandLinkedList_t));
	CustomCommandLinkedList_t* listProcess = (CustomCommandLinkedList_t*)LdnMalloc(sizeof(CustomCommandLinkedList_t));
	listProcess->nextElement = NULL;
	InitializeProcessList(&listProcess);
	currentList = listProcess;
	while (currentList->nextElement != NULL && strcmp(listOfParsedWords->structureElement, listProcess->function->commandMatch)) {
		currentList = currentList->nextElement;
	}
	currentList->function->opt;
}

CustomCommandLinkedList_t* InitializeProcessList(CustomCommandLinkedList_t* list) {
	CustomFunctionPtr functionTab[CUSTOM_CALL_NUMBER] = { 
		&GetCurrentDir, 
		&ChangeDir, 
		&ListDirectoryContent 
	};
}

CustomCommand_t* InitializeCustomCommand(CustomCommand_t* custCommand) {

}