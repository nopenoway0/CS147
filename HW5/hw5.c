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

int memmov(void* source, void* dest, int length, int size); // Uses integer copy instead of byte

int main(){

    int num_array[9] = {2, 4, 5, 3, 2, 2, 7, 6, 4};

    int* num_moved;

    memmov(num_array, num_moved, sizeof(num_array) / sizeof(num_array[0]), sizeof(int));

    int size_num_array = sizeof(num_array) / sizeof(num_array[0]);
    while(size_num_array > 0){
        printf("%d", 5);
        ++num_moved;
        --size_num_array;
    }
    free(num_moved);
}

/**
 * Size of operation used to make adaptability based off int in the current system
 * Assumes memory must be allocated at destination
 */
int memmov(void* source, void* dest, int length, int size){         // void pointer to handle any argument
    printf("Entering memmov\n");  // Implicit declaration

    int* four_ptr_src = (int*) source;
    int* four_ptr_dst = (int*) dest;
    if(four_ptr_dst == four_ptr_src) return 0;                      // Base conditions if memory completely overlaps

    int total_bytes = length * size;                                // Counts total bytes in array
    dest = malloc(total_bytes);
    int num_char_calls = total_bytes % sizeof(int);                 // Amount of char calls to be needed
    int num_int_calls = (total_bytes - num_char_calls) / sizeof(int);// Amount of int* calls needed to increment
    char* single_ptr_src;
    char* single_ptr_dest;
    while(num_int_calls > 0){
        *four_ptr_dst = (unsigned)*four_ptr_src;
        ++four_ptr_src;
        ++four_ptr_dst;
        --num_int_calls;
    }

    // Character reads
    single_ptr_src = (char*) four_ptr_src;
    single_ptr_dest = (char*) four_ptr_dst;
    while(num_char_calls > 0){
        ++single_ptr_src;
        --num_char_calls;
    }
    //printf("\nChar calls: %d, Int Calls: %d\n", num_char_calls, num_int_calls);

    return 1;
}
