cmake_minimum_required(VERSION 3.8)
project(clox)

if (CMAKE_BUILD_TYPE MATCHES DEBUG)
  add_compile_definitions(CLOX_DEBUG)
endif (CMAKE_BUILD_TYPE MATCHES DEBUG)

set (CMAKE_C_STANDARD 11)

add_executable(clox src/main.c src/chunk.c src/debug.c src/memory.c src/value.c src/vm.c src/scanner.c src/compiler.c src/object.c src/table.c src/natives.c)
