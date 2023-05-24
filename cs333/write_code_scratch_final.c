#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>


void *vikalloc(size_t size)
{
    size_t correct_size = 0;
    mem_block_t *curr = NULL;

    if (size == 0)
        return NULL;

    correct_size = new_block(size);

    if (!mem_block_first) {
        curr = sbrk(correct_size);
        curr->size = size;
        curr->capacity = correct_size - sizeof(mem_block_t);
        curr->next = NULL;
        curr->prev = NULL;
        return (((void *) mem_block_first) + sizeof(mem_block_t));
    }

    curr = mem_block_first;


    do
    {
        if (curr->size == 0) {
            curr->size = size;
            return (((void *) curr) + sizeof(mem_block_t));
        }

        //Don't worry about split section

        curr = curr->next;
    } while (curr->next);

    curr->next = sbrk(correct_size);
    curr->next->size = size;
    curr->next->capacity = correct_size - sizeof(mem_block_t);
    curr->next->prev = curr;
    curr = curr->next;
    curr->next = NULL;
    return (((void *) curr) + sizeof(mem_block_t));
}
