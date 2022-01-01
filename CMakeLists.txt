cmake_minimum_required(VERSION 3.8)
project(clox)

add_executable(clox src/main.c src/chunk.c src/debug.c src/memory.c src/value.c src/vm.c src/scanner.c src/compiler.c src/object.c src/table.c)
