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
    
    memmov(num_array, &num_moved, sizeof(num_array), sizeof(int));
}

int memmov(void* source, void* dest, int length, int size){ // void pointer to handle any argument
    printf("Entering memmov\n");  // Implicit declaration
    
    return 1;
}