#include <linux/bpf.h>
#include <bpf_helpers.h>

struct bpf_map_def SEC("maps") my_map = {
    .type           = BPF_MAP_TYPE_HASH,
    .key_size       = sizeof(int),
    .value_size     = sizeof(int),
    .max_entries    = 100,
};

SEC("tracepoint/syscalls/sys_enter_execve")
int bpf_prog(void *ctx) {
    int init_value = 1;
    int key = 0;
    int *value;
    
    char msg[] = "Eneter execve";
    bpf_trace_printk(msg, sizeof(msg));

    value = bpf_map_lookup_elem(&my_map, &key);
    if (value)
        *value += 1;
    else
        bpf_map_update_elem(&my_map, &key, &init_value, BPF_ANY);
	return 0;
}

char _license[] SEC("license") = "GPL";
