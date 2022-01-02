#ifndef CLOX_NATIVES_H
#define CLOX_NATIVES_H

#include "value.h"
#include "object.h"

Value clockNative(int argCount, NativeErrorCode* outStatus, Value* args);
Value numberToStringNative(int argCount, NativeErrorCode* outStatus, Value* args);

#endif
