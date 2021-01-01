#include "fwd.h"
#include "stringManager.h"

LIST_PARSED_T* AddToList(LIST_PARSED_T* list, char* e) {
    int length = strlen(e);
    int newL = length + 1;
    if (!list) {
        list = malloc(sizeof(LIST_PARSED_T));
        if (list) {
            list->structureElement = NULL;
            list->structureElement = malloc(sizeof(char) * newL);
            strncpy_s(list->structureElement, newL, e, length);
            list->nextElement = NULL;
            return list;
        }
    }
    else {
        LIST_PARSED_T* current = list;
        LIST_PARSED_T* newNode = malloc(sizeof(LIST_PARSED_T));
        if (newNode) {
            newNode->structureElement = NULL;
            newNode->structureElement = malloc(sizeof(char) * newL);
            strncpy_s(newNode->structureElement, newL, e, length);
            newNode->nextElement = NULL;
        }

        while (current->nextElement != NULL) {
            current = current->nextElement;
        }
        current->nextElement = newNode;
        return 1;
    }

}


char* OperatorParser(char* str, LIST_PARSED_T* list) {
    const char TOKEN_STRING_SEPARATOR = ' ';
    char* chParsed;
    unsigned strLength = strlen(str);
    chParsed = NULL;
    char* ret;
    for (unsigned i = 0; i < strLength; ++i) {
        if ((TOKEN_STRING_SEPARATOR != str[i] && (str[0] != ' ')) || (str[i] == '\0')) continue;

        chParsed = malloc(sizeof(char) * i + 1);
        LdnStrncpy_s(chParsed, i + 1, str, 0);
        printf("%s\n", chParsed);
        AddToList(list, chParsed);
        free(chParsed);
        chParsed = NULL;

        ret = malloc(sizeof(char) * (strLength - i));
        LdnStrncpy_s(ret, (strLength - i), str, i + 1);
        return ret;
    }
    return "l";
}