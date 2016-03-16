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
    printf("\nExiting Program\n");
    return 1;
}
/*
When grabbing from addresses, make a pointer then navigate through the address using index blocks
for an unsigned intenger of 256, the first byte[0] will read 128, byte[1] will read 1 and the rest of the bytes will read 0
*/
//Bit shift to right, until number equals 0. If number /= orignal number /2 then that means a 1 dropped off
//Otherwise, 0 dropped off.
int toBinary(float a){
    char* pter = (char*) &a;
    unsigned char b;
    int storage;
    int bin;
    for(int x = 4; x > 0; x--){
    b = pter[x];
    int bin = 0;
    storage = (int) b;
    for(int y = 0; y < 8; y++){
        bin += (storage % 2) * (int)pow(10, y);
        //printf("%d", (int) pow(10, x));
        storage = storage >> 1;
    }
    int zeros = 8 - (int)log((bin / 10));
    if(zeros > 0){
        while(zeros > 1){
        printf("0");
        --zeros;
    }
    }
    /*else for(int y = 0; y < 7; y++){
        printf("0");
    }*/
    printf("%d", bin);
    }
    return 1;
}