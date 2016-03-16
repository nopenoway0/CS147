//
//  floatchecker.c
//
//
//  Created by Benjamin on 3/14/16.
//
//

#include <stdio.h>
#include <math.h>

int toBinary(float a);

int main(){
    printf("Entering Program\n");
    float a = -5;
    int a_bin = toBinary(a);
    return 1;
}
/*
When grabbing from addresses, make a pointer then navigate through the address using index blocks
for an unsigned intenger of 256, the first byte[0] will read 128, byte[1] will read 1 and the rest of the bytes will read 0
*/
//Bit shift to right, until number equals 0. If number /= orignal number /2 then that means a 1 dropped off
//Otherwise, 0 dropped off.
/*
 Produces string of the proper binary, but does it backwards
*/
int toBinary(float a){
    unsigned int t = 128;
    char* pter = (char*) &t;
    unsigned char b = pter[0];
    int storage;
    int bin = 0;
    storage = (int) b;
    for(int x = 0; x < 8; x++){
        bin += (storage % 2) * (int)pow(10, x);
        //printf("%d", (int) pow(10, x));
        storage = storage >> 1;
    }
//Add proper zeros before the print
    int zeros = 8 - (int)log((bin / 10));
    while(zeros > 1){
        printf("0");
        --zeros;
    }
    printf("%d", bin);
    printf("\nExiting Program\n");
}