#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

static void repl() {
    char line[1024];
    for (;;) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }

        interpret(line, true, false);
    }
}

static char* readFile(const char* path) {    
    FILE* file = fopen(path, "rb");
    if (file == NULL) {
        fprintf(stderr, "Could not open file '%s'\n", path);
        exit(74);
    }
    fseek(file, 0L, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(fileSize + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Not enough memory to read '%s'\n", path);
        exit(74);
    }

    size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
    if (bytesRead < fileSize) {
        fprintf(stderr, "Could not read file '%s'\n", path);
        exit(74);
    }
    buffer[bytesRead] = '\0';

    fclose(file);
    return buffer;
}

static void runFile(const char* path, bool verbose) {
    char* source = readFile(path);
    InterpretResult result = interpret(source, false, verbose);
    free(source);

    switch (result) {
        case INTERPRET_COMPILE_ERROR:
            fprintf(stderr, "Interpreter Compiler Error.\n");
            exit(65);
        case INTERPRET_RUNTIME_ERROR: 
            fprintf(stderr, "Interpreter Runtime Error.\n");
            exit(70);
        default:
            break;  // Ok
    }
}

int main(int argc, const char* argv[])
{
    initVM();

    switch (argc) {
        case 1:
            repl();
            break;
        case 2:
            runFile(argv[1], false);
            break;
        case 3:
            if (strcmp(argv[2], "--verbose") == 0 || strcmp(argv[2], "-v") == 0) {
                runFile(argv[1], true);
                break;
            }
        default:
            fprintf(stderr, "Usage: clox [path [--verbose]]\n");
            exit(64);
    }

    freeVM();
    return 0;
}
