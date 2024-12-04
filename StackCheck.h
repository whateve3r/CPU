#include "Consts.h"
#include "StackStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Filesize.h"

#ifndef StackChecking
#define StackChecking
int StackCheck(const Stack* stack);
int StackDump(const Stack* stack);
int Verificator(const Stack* stack);
#endif
