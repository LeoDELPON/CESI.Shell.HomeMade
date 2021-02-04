#include "fwd.h"
#include "stringManager.h"
#include "commandShell.h"
#include "stringParser.h"


VOID InitWelcomeMessage(VOID) {
    printf("Leo DELPON Company [version 0.00]\n(nc) 2020 Personnal Project. Feel Free, It is open-source :)\n\n");
}

VOID CustomArrayInit(Array_t* a, size_t sizeInit) {
    a->array = (long*)malloc(sizeInit * sizeof(long));
    a->used = 0;
    a->size = sizeInit;
}

VOID CustomArrayAddElement(Array_t* a, long element, int isSpecifiedIndex) {
    if (!a)
        SAFE_ERROR_EXIT(a);
    if (a->used == a->size) {
        a->size <<= 1;
        a->array = realloc(a->array, a->size * sizeof(long));
    }
    if (isSpecifiedIndex == 1) {
        a->array[a->used] = a->array[a->used + 1];
    }
    else {
        a->array[a->used] = element;
        a->used++;
    }
}

VOID CustomArrayAddEOF(Array_t* a) {
    if (!a)
        SAFE_ERROR_EXIT(a);
    if (a->used == a->size) {
        a->size <<= 1;
        a->array = realloc(a->array, a->size * sizeof(long));
    }
    a->array[a->used] = '\0';
}
VOID CustomArrayDeleteElement(Array_t* a, size_t elementToDel) {
    Array_t newArray;
    newArray.array = NULL;
    int index = elementToDel - 1;
    int lastIndex = (a->used - 1);
    CustomArrayInit(&newArray, 5);
    if (index != lastIndex) {
        for (unsigned i = index; i < lastIndex; ++i) {
            a->array[i] = a->array[i + 1];
            printf("%c\n", a->array[i]);
        }
    }

    for (unsigned k = 0; k < lastIndex; ++k) {
        if (elementToDel == 0) {
            CustomArrayFreeElement(&newArray);
            CustomArrayInit(&newArray, 5);
            break;
        }
        CustomArrayAddElement(&newArray, a->array[k], 0);
    }

    CustomArrayFreeElement(a);
    CustomArrayInit(a, 5);
    printf("\33[2K\r");
    GetCurrentDir();
    for (unsigned j = 0; j < newArray.used; ++j) {
        CustomArrayAddElement(a, newArray.array[j], 0);
        printf("%c", a->array[j]);
    }
}

VOID CustomArrayFreeElement(Array_t* a) {
    a->used = a->size = 0;
    SafeFree(a->array);
}


VOID SafeFree(char* pointerToFree) {
    if (pointerToFree == NULL)
        SAFE_ERROR_EXIT(pointerToFree);
    SAFE_FREE(pointerToFree);
}

char* LdnStrncpy_s(char* dest, unsigned int destLength, char* source, int sourceStart, int wordIndex) {
    int indexIndicatorAbortStrncpy = wordIndex - sourceStart;
    size_t indexArrayStartDest = 0;
    size_t indexArrayStartSrc = 0;
    if (sourceStart != 0) {
        indexArrayStartSrc = sourceStart + 1;
    } else {
        indexArrayStartSrc = sourceStart;
    }
    while (indexIndicatorAbortStrncpy != 0) {
        dest[indexArrayStartDest] = source[indexArrayStartSrc]; 
        indexIndicatorAbortStrncpy--;
        indexArrayStartDest++;
        indexArrayStartSrc++;
    }               
    if (sourceStart != 0) {
        dest[destLength - 1] = '\0';
    }
    else {
        dest[destLength] = '\0';
    }
    return dest;
}


void EnterWriteToConsole(Array_t* pArray) {                
    LIST_PARSED_T* parsedList = NULL;
    parsedList = (LIST_PARSED_T*)malloc(sizeof(LIST_PARSED_T));
    if (parsedList == NULL) SAFE_ERROR_EXIT(parsedList);
    parsedList->structureElement = NULL;
    CustomArrayAddEOF(pArray);
    LdnStrTok(pArray->array, parsedList);
    //ApplyCommand(pArray);
    CustomArrayFreeElement(pArray);
    CustomArrayInit(pArray, 5);
    printf("\n");
}