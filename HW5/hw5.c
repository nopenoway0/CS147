//
//  hw5.c
//  Assumes that the system is 32-bit because mips is 32-bit
//
//  Created by Benjamin on 4/2/16.
//  Transfer in memory using integer copies when possible, otherwise default
//  to byte copies. Account for when memory alignment is not to size of integers
//
//  Read by address, or by chunk of allocation? If it is a half, don't load int
//  Determine by the size when to read a byte. If the it ends on an address not divisible by 4 then it can be used
//  or read by a byte

#include <stdio.h>
#include <stdlib.h>

int memmov(void* source, void* dest, int dest_size, int size_var); // Uses integer copy instead of byte

int main(){

    int num_array[10] = {2, 4, 5, 3, 2, 2, 7, 6, 4, 12};

    int* num_moved = (int*) malloc(sizeof(int) * 10);

    memmov(num_array, num_moved, 10, 4);

    int size_num_array = sizeof(num_array) / sizeof(num_array[0]);
    while(size_num_array > 0){
        printf("%d\n", *num_moved);
        ++num_moved;
        --size_num_array;
    }
    return 1;
}

/**
 * Size of operation used to make adaptability based off int in the current system
 * Assumes memory must be allocated at destination
 */
int memmov(void* source, void* dest, int dest_size, int size_var){         // void pointer to handle any argument, size in bytes
    printf("Entering memmov\n");  // Implicit declaration
    if(source == dest) return 0;

    unsigned int* four_ptr_src = (unsigned int*) source;
    unsigned int* four_ptr_dst = (unsigned int*) dest;                  // Base conditions if memory completely overlaps
    
    unsigned long a1 = (long) &source;
    unsigned long a2 = (long) &dest;
    
    unsigned char* one_ptr_src;
    unsigned char* one_ptr_dst;
    
    int total_bytes = dest_size * size_var;
    int amt_int_load = total_bytes / 4;
    int amt_char_load = total_bytes - amt_int_load;

    if(source < dest){                                // If the source is located earlier in memory
        while((long)source < a2 && amt_int_load > 0){
            *four_ptr_dst = *four_ptr_src;
            ++four_ptr_dst;
            ++four_ptr_src;
            --amt_int_load;
        }
    }
    else{                                             // If the source is located later in memory
        while((long)dest < a1 && amt_int_load > 0){
            *four_ptr_dst = *four_ptr_src;
            ++four_ptr_dst;
            ++four_ptr_src;
            --amt_int_load;
        }
    }
    
//  Char loading
    one_ptr_dst = (unsigned char*) four_ptr_dst;
    one_ptr_src = (unsigned char*) four_ptr_src;
    
    if(source < dest){                                // If the source is located earlier in memory
        while((long)source < a2 && amt_char_load > 0){
            *one_ptr_dst = *one_ptr_src;
            ++one_ptr_src;
            ++one_ptr_dst;
            --amt_char_load;
        }
    }
    else{                                             // If the source is located later in memory
        while((long)dest < a1 && amt_char_load > 0){
            *one_ptr_dst = *one_ptr_src;
            ++one_ptr_src;
            ++one_ptr_dst;
            --amt_char_load;
        }
    }
    
    return 1;
}
