#include <stdio.h>
#include <unistd.h>
#include <bpf_load.h>

int main(int argc, char **argv) {

    if (load_bpf_file("../../kern/build/bpf_prog.o") != 0) {
        printf("The kernel didn't load the BPF program\n");
        return -1;
    }

    while (1) {
        int key = 0;
        int value;
        int ret = bpf_map_lookup_elem(map_fd[0], &key, &value);
        if (ret)
            printf("error lookup key %d\n", key);
        else
            printf("current value = %d\n", value);

        sleep(1);
    }

    return 0;
}

