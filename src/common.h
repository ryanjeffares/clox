#ifndef CLOX_COMMON_H
#define CLOX_COMMON_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(_DEBUG) || !defined(NDEBUG) || defined(DEBUG)
    #define CLOX_DEBUG
#endif

#ifdef CLOX_DEBUG
#define DEBUG_PRINT_CODE
#define DEBUG_TRACE_EXECUTION
#endif

#define UINT8_COUNT (UINT8_MAX + 1)

#endif  // CLOX_COMMON_H
