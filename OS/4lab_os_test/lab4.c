
#include <stdio.h>
#include "memory.h"
#include "memory.c"

int main() {
    MemoryManager mem_manager;
    size_t total_memory = 4096 * 10; // Total memory of 10 pages

    initialize_memory_manager(&mem_manager, total_memory);

    // Test memory allocation larger than one page
    void* allocated_mem = allocate_memory(&mem_manager, 9000); // Allocate 9000 bytes
    if (allocated_mem != NULL) {
        printf("Memory allocated successfully\n");

        // Test memory write
        char data[] = "Hello, Memory Manager!";
        write_memory(allocated_mem, data, sizeof(data));

        // Test memory read
        char read_data[sizeof(data)];
        read_memory(allocated_mem, read_data, sizeof(data));
        printf("Read data: %s\n", read_data);

        // Test memory deallocation
        free_memory(&mem_manager, allocated_mem);
        printf("Memory freed\n");
    } else {
        printf("Failed to allocate memory\n");
    }

    return 0;
}