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
unsigned int t = 1;
char* pter = (char*) &t;
unsigned char b = pter[0];
while(b != 0){
    char tmp = b * 2;
    b = b << 1;
    if(tmp != b){
       printf("1");
    }
    else printf("0");
}
}
