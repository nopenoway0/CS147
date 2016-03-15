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
float a = -5;
int a_bin = toBinary(a);
return 1;
}
/*
When grabbing from addresses, make a pointer then navigate through the address using index blocks
for an unsigned intenger of 256, the first byte[0] will read 128, byte[1] will read 1 and the rest of the bytes will read 0
*/
int toBinary(float a){
unsigned int t = 256;
char* pter = (char*) &t;
unsigned char b = pter[1];
printf("int a: %.0f | char pointer: %d", a, b);
}
