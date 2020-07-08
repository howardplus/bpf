cmake_minimum_required (VERSION 3.13)

set (CMAKE_C_COMPILER "/usr/bin/clang")

project (bpf_prog)

add_custom_target ( bpf_prog ALL
    COMMAND /usr/bin/clang -O2 -emit-llvm
        -I$ENV{KERN_SRC}/tools/testing/selftests/bpf
        -c ${CMAKE_CURRENT_SOURCE_DIR}/bpf_prog.c
        -o ${CMAKE_CURRENT_BINARY_DIR}/bpf_prog.o
    )

add_custom_command ( TARGET bpf_prog
    COMMAND /usr/bin/llc -march=bpf -filetype=obj 
        -o ${CMAKE_CURRENT_BINARY_DIR}/bpf_prog.o < ${CMAKE_CURRENT_BINARY_DIR}/bpf_prog.o
    )
