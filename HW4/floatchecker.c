//
//  floatchecker.c
//
//
//  Created by Benjamin on 3/14/16.
//
//

#include <stdio.h>
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
int toBinary(float a){
unsigned int t = 2;
char* pter = (char*) &t;
unsigned char b = pter[0];
int tmp1;
int tmp2;
for(int i = 0; i < 8; i++){
    tmp1 = b / 2;
    b = b >> 1;
    tmp2 = (int)b;
    printf("tmp1 = %d | tmp2 = %d\n", tmp1, tmp2);
    if(tmp1 != tmp2){
        printf("1");
    }
    else if(b == 0) printf("0");
    else printf("0");
}
    printf("\nExiting Program\n");
}
