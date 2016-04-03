//
//  hw5.c
//  
//
//  Created by Benjamin on 4/2/16.
//  Transfer in memory using integer copies when possible, otherwise default
//  to byte copies. Account for when memory alignment is not to size of integers
//
//  Read by address, or by chunk of allocation? If it is a half, don't load int?

int memmov(void* source, void* dest); // Uses integer copy instead of byte

int main(){
    int number = 20;
    int number_dest = 12;
    char t1 = 3;
    
    //test of reading from char with an int pointer
    int* ptr = &t1;
    printf("%d", ptr);
    
    //memmov(&number, &number_dest);
}

int memmov(void* source, void* dest, int length_of_mem){ // void pointer to handle any argument
    printf("Entering memmov\n");  // Implicit declaration
    
    return 1;
}