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
    
    double num_array[9] = {2, 4, 5, 3, 2, 2, 7, 6, 4};
    
    int* num_moved;
    
    memmov(num_array, &num_moved, sizeof(num_array) / sizeof(num_array[0]), sizeof(int));
}

/**
 * Size of operation used to make adaptability based off int in the current system
 */
int memmov(void* source, void* dest, int length, int size){         // void pointer to handle any argument
    printf("Entering memmov\n");  // Implicit declaration
    int total_bytes = length * size;                                // Counts total bytes in array
    int num_char_calls = total_bytes % sizeof(int);                 // Amount of char calls to be needed
    int num_int_calls = (total_bytes - num_char_calls) / sizeof(int);// Amount of int* calls needed to increment
    int* four_ptr = (int*) source;
    char* single_ptr;
    while(num_int_calls > 0){
        ++four_ptr;
        --num_int_calls;
    }
    
    // Character reads
    single_ptr = (char*) four_ptr;
    while(num_char_calls > 0){
        ++single_ptr;
        --num_char_calls;
    }
    printf("\nChar calls: %d, Int Calls: %d\n", num_char_calls, num_int_calls);
    
    return 1;
}