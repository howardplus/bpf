cmake_minimum_required(VERSION 3.13)

set (CMAKE_C_COMPILER        "/usr/bin/clang")

project (bpf_loader)

add_executable (bpf_loader loader.c $ENV{KERN_SRC}/samples/bpf/bpf_load.c)

target_compile_definitions (bpf_loader PUBLIC
    HAVE_ATTR_TEST=0)

target_include_directories (bpf_loader PUBLIC
    $ENV{KERN_SRC}/tools/lib 
    $ENV{KERN_SRC}/tools/perf 
    $ENV{KERN_SRC}/tools/include 
    $ENV{KERN_SRC}/samples/bpf 
    )

target_link_directories (bpf_loader PUBLIC
    /usr/local/lib64
    )

target_link_libraries (bpf_loader bpf elf)

