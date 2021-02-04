#include "fwd.h"
#include "stringManager.h"

//LIST_PARSED_T* AddToList(LIST_PARSED_T* list, char* e) {
//    int length = strlen(e);
//    int newL = length + 1;
//    if (!list) {
//        list = malloc(sizeof(LIST_PARSED_T));
//        if (list) {
//            list->structureElement = NULL;
//            list->structureElement = malloc(sizeof(char) * newL);
//            strncpy_s(list->structureElement, newL, e, length);
//            list->nextElement = NULL;
//            printf("%s\n", list->structureElement);
//            return list;
//        }
//    }
//    else {
//        LIST_PARSED_T* current = list;
//        LIST_PARSED_T* newNode = malloc(sizeof(LIST_PARSED_T));
//        if (newNode) {
//            newNode->structureElement = NULL;
//            newNode->structureElement = malloc(sizeof(char) * newL);
//            strncpy_s(newNode->structureElement, newL, e, length);
//            newNode->nextElement = NULL;
//        }
//
//        while (current->nextElement != NULL) {
//            current = current->nextElement;
//        }
//        current->nextElement = newNode;
//        return 1;
//    }
//
//}


LIST_PARSED_T* AddToList(LIST_PARSED_T* listString, char* string) {
    unsigned int stringLength = strlen(string);
    if (listString == NULL) {
        listString = (LIST_PARSED_T*)malloc(sizeof(LIST_PARSED_T));
        listString->structureElement = NULL;
        listString->structureElement = (char*)malloc(sizeof(char) * stringLength + 1);
        for (unsigned i = 0; i < stringLength; ++i) {
            listString->structureElement[i] = string[i];
        }
        listString->structureElement[stringLength] = '\0';
        printf("%s\n", listString->structureElement);
        listString->nextElement = NULL;
    }
    else {
        printf("List not empty");
    }
}


char* OperatorParser(char* str, LIST_PARSED_T* list) {
    const char TOKEN_STRING_SEPARATOR = ' ';
    char* chParsed;
    unsigned strLength = strlen(str);
    chParsed = NULL;
    char* ret;
    unsigned int start = 0;
    printf("\n");
    for (unsigned i = 1; i < strLength; ++i) {
        if ((TOKEN_STRING_SEPARATOR == str[i-1]) && TOKEN_STRING_SEPARATOR == str[i]) {
            start++;
            continue;
        }
        if (TOKEN_STRING_SEPARATOR != str[i] || (TOKEN_STRING_SEPARATOR != str[i] && !isalpha(str[i-1]))) continue;
        unsigned int sizeMalloc = i - start;
        chParsed = (char*)malloc(sizeof(char) * sizeMalloc + 1);
        LdnStrncpy_s(chParsed, sizeMalloc, str, start, i);
        AddToList(list, chParsed);
        SafeFree(chParsed);
        start = i;
    }
    unsigned int sizeMalloc = strLength - start;
    chParsed = (char*)malloc(sizeof(char) * sizeMalloc + 1);
    LdnStrncpy_s(chParsed, sizeMalloc, str, start, (strLength));
    AddToList(list, chParsed);
    SafeFree(chParsed);
    return str;
}