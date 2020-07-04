# build the bpf program
clang -O2 -emit-llvm -c bpf_prog.c -o - | llc -march=bpf -filetype=obj -o bpf_prog.o
