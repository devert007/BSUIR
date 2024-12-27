
#include "memory.h"
#include <stdlib.h>
#include <string.h>

void initialize_memory_manager(MemoryManager* mem_manager, size_t total_memory) {
    mem_manager->total_memory = total_memory;
    mem_manager->num_pages = total_memory / PAGE_SIZE;

    mem_manager->pages = (Page*)malloc(mem_manager->num_pages * sizeof(Page));
    if (mem_manager->pages == NULL) {
        printf("Error: Memory allocation for pages failed\n");
        return;
    }

    mem_manager->allocations = (Allocation*)malloc(mem_manager->num_pages * sizeof(Allocation));
    if (mem_manager->allocations == NULL) {
        printf("Error: Memory allocation for allocations failed\n");
        free(mem_manager->pages);
        return;
    }

    // Initialize each page
    for (size_t i = 0; i < mem_manager->num_pages; i++) {
        mem_manager->pages[i].start_address = malloc(PAGE_SIZE);
        mem_manager->pages[i].size = PAGE_SIZE;
        mem_manager->pages[i].allocation = NULL;
    }
}

void* allocate_memory(MemoryManager* mem_manager, size_t size) {
    size_t num_consecutive_pages = size / PAGE_SIZE + (size % PAGE_SIZE != 0);
    size_t consecutive_pages_found = 0;

    for (size_t i = 0; i < mem_manager->num_pages; i++) {
        if (!mem_manager->pages[i].is_allocated) {
            consecutive_pages_found++;
        } else {
            consecutive_pages_found = 0;
        }

        if (consecutive_pages_found == num_consecutive_pages) {
            // Mark consecutive pages as allocated
            for (size_t j = i - num_consecutive_pages + 1; j <= i; j++) {
                mem_manager->pages[j].is_allocated = true;
                mem_manager->pages[j].allocation = &mem_manager->allocations[j];
                mem_manager->allocations[j].size = PAGE_SIZE;
            }
            return mem_manager->pages[i - num_consecutive_pages + 1].start_address;
        }
    }

    return NULL; // No consecutive free pages found
}

void free_memory(MemoryManager* mem_manager, void* address) {
    for (size_t i = 0; i < mem_manager->num_pages; i++) {
        if (address >= mem_manager->pages[i].start_address &&
            (char*)address < (char*)mem_manager->pages[i].start_address + PAGE_SIZE) {
            mem_manager->pages[i].is_allocated = 0;
            mem_manager->pages[i].allocation = NULL;
               // Check if consecutive pages are also free and merge them
            size_t j = i;
            while (j < mem_manager->num_pages && mem_manager->pages[j].is_allocated == 0) {
                mem_manager->pages[j].allocation = NULL;
                j++;
            }
            return;
        }
    }
}

void read_memory(void* address, void* buffer, size_t size) {
    memcpy(buffer, address, size);
}

void write_memory(void* address, void* data, size_t size) {
    memcpy(address, data, size);
}