#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#ifndef MMEMORY_H
#define MMEMORY_H

#define PAGE_SIZE 4096

typedef struct {
    void* address;
    size_t size;
} Allocation;// это распределить наших ячеек памяти

typedef struct {
    void* start_address;
    size_t size;
    Allocation* allocation;
    bool is_allocated;
} Page;

typedef struct {
    size_t total_memory;
    size_t num_pages;
    Page* pages;
    Allocation* allocations;
} MemoryManager;

void initialize_memory_manager(MemoryManager* mem_manager, size_t total_memory);
void* allocate_memory(MemoryManager* mem_manager, size_t size);
void free_memory(MemoryManager* mem_manager, void* address);
void read_memory(void* address, void* buffer, size_t size);
void write_memory(void* address, void* data, size_t size);

#endif /* MMEMORY_H */