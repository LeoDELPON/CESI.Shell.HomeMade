#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <wtypes.h>
#include <direct.h>

HANDLE hStdin;
DWORD fdwSaveOldMode;

typedef  struct {
    long* array;
    size_t used;
    size_t size;
} Array_t;