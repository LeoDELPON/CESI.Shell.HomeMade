#include "fwd.h"
#include "stringManager.h"



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
        ErrorExit("CustomArrayAddEelement, the Array_t does not exist");
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
        ErrorExit("CustomArrayAddEelement, the Array_t does not exist");
    if (a->used == a->size) {
        a->size <<= 1;
        a->array = realloc(a->array, a->size * sizeof(long));
    }
    a->array[a->used] = "\0";
    a->used++;
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

    for (unsigned k = 0; k < a->used - 1; ++k) {
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
    if (!a->array)
        ErrorExit("Array memory not allocated");
    safeFree(a->array);
    a->used = a->size = 0;
}


VOID safeFree(char* pointerToFree) {
    if (!pointerToFree)
        ErrorExit("An error occured");
    free(pointerToFree);
}