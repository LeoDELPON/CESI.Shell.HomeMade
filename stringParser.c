#include "fwd.h"
#include "stringManager.h"
#include "allocatorManager.h"

LIST_PARSED_T* AddToList(LIST_PARSED_T* listString, char* string) {
    unsigned int stringLength = strlen(string);
    if (listString->structureElement == NULL) {
        listString->structureElement = (char*)LdnMalloc(sizeof(char) * stringLength + 1);
        for (unsigned i = 0; i < stringLength; ++i) {
            listString->structureElement[i] = string[i];
        }
        listString->structureElement[stringLength] = '\0';
        printf("%s\n", listString->structureElement);
        listString->nextElement = NULL;
        return listString;
    }
    else {
        LIST_PARSED_T* newParsedList = (LIST_PARSED_T*)LdnMalloc(sizeof(LIST_PARSED_T));
        LIST_PARSED_T* currentList = (LIST_PARSED_T*)LdnMalloc(sizeof(LIST_PARSED_T));

        currentList = listString;

        newParsedList->structureElement = NULL;
        newParsedList->structureElement = (char*)LdnMalloc(sizeof(char) * stringLength + 1);
        newParsedList->nextElement = NULL;

        for (unsigned i = 0; i < stringLength; ++i) {
            newParsedList->structureElement[i] = string[i];
        }
        newParsedList->structureElement[stringLength] = '\0';

        printf("%s\n", newParsedList->structureElement);
        while (currentList->nextElement != NULL) {
            currentList = currentList->nextElement;
        }
        currentList->nextElement = newParsedList;
        return currentList;
    }
}


char* LdnStrTok(char* str, LIST_PARSED_T* list) {
    const char TOKEN_STRING_SEPARATOR = ' ';
    char* chParsed;
    unsigned strLength = strlen(str);
    chParsed = NULL;
    unsigned int start = 0;
    printf("\n");
    if (str[0] == '\0') return NULL;
    for (unsigned i = 1; i < strLength; ++i) {
        if ((TOKEN_STRING_SEPARATOR == str[i-1]) && TOKEN_STRING_SEPARATOR == str[i]) {
            start++;
            continue;
        }
        if (TOKEN_STRING_SEPARATOR != str[i] || (TOKEN_STRING_SEPARATOR != str[i] && !isalpha(str[i-1]))) continue;
        unsigned int sizeMalloc = i - start;
        chParsed = (char*)LdnMalloc(sizeof(char) * sizeMalloc + 1);
        LdnStrncpy_s(chParsed, sizeMalloc, str, start, i);
        AddToList(list, chParsed);
        SafeFree(chParsed);
        start = i;
    }
    unsigned int sizeMalloc = strLength - start;
    chParsed = (char*)LdnMalloc(sizeof(char) * sizeMalloc + 1);
    LdnStrncpy_s(chParsed, sizeMalloc, str, start, (strLength));
    AddToList(list, chParsed);
    SafeFree(chParsed);
    return list;
}