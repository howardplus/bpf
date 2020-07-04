KERN_SRC=/home/howard/Projects/linux-source-5.4.0
clang -O2 -DHAVE_ATTR_TEST=0 -Wall -Wno-unused-variable -o bpf_loader \
    -I${KERN_SRC}/tools/lib \
    -I${KERN_SRC}/tools/perf \
    -I${KERN_SRC}/tools/include \
    -I${KERN_SRC}/samples/bpf \
    -Wl,--library-path=${KERN_SRC}/tools/lib/bpf/,-rpath=${KERN_SRC}/tools/lib/bpf/,--library=bpf,--library=elf \
    loader.c ${KERN_SRC}/samples/bpf/bpf_load.c
