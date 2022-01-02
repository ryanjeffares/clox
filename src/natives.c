#include <time.h>
#include <stdio.h>
#include <math.h>

#include "natives.h"

Value clockNative(int argCount, NativeErrorCode* outStatus, Value* args) {
    if (argCount != 0) {
        *outStatus = ERR_INCORRECT_ARG_COUNT;
        return NUMBER_VAL(0.0);
    }
    *outStatus = ERR_NONE;
    return NUMBER_VAL((double)clock() / CLOCKS_PER_SEC);
}

Value numberToStringNative(int argCount, NativeErrorCode* outStatus, Value* args) {
    if (!IS_NUMBER(args[0])) {
        *outStatus = ERR_INCORRECT_TYPE;
        return OBJ_VAL("");
    }

    if (argCount != 1) {
        *outStatus = ERR_INCORRECT_ARG_COUNT;
        return OBJ_VAL("");
    }

    char s[50];
    double n = args[0].as.number;
    if (trunc(n) == n) {
        sprintf_s(s, 50, "%i", (int)n);
    } else {
        sprintf_s(s, 50, "%f", n);
    }
    ObjString* string = copyString(s, 10);
    *outStatus = ERR_NONE;
    return OBJ_VAL(string);
}

