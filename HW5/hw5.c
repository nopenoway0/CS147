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

    int* num_moved = 5;

    return memmov(num_array, num_moved, sizeof(num_array) / sizeof(num_array[0]), sizeof(int));

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
int memmov(void* source, void* dest, int source_size, int dest_size){         // void pointer to handle any argument, size in bytes
    printf("Entering memmov\n");  // Implicit declaration
    if(source == dest) return 0;

    int* four_ptr_src = (int*) source;
    int* four_ptr_dst = (int*) dest;                  // Base conditions if memory completely overlaps
    unsigned int a1 = source;
    unsigned int a2 = dest;

    printf("a1: %d, a2: %d\n", a1, a2);

    return 1;
}
