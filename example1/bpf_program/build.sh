# build the bpf program
KERN_SRC=/usr/src/linux-source-5.4.0/linux-source-5.4.0
clang -O2 -emit-llvm -I${KERN_SRC}/tools/testing/selftests/bpf -c bpf_prog.c -o - | llc -march=bpf -filetype=obj -o bpf_prog.o
