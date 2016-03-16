//
//  floatchecker.c
//
//
//  Created by Benjamin on 3/14/16.
//
//

#include <stdio.h>
#include <math.h>

void PrintToBinary(float a);

int main(){
    printf("Entering Program\n");
    float a = -5;
    PrintToBinary(a);
    printf("\nExiting Program\n");
    return 1;
}
// Understanding of anding and bit shifting from :
//Bit shift to right, until number equals 0. If number /= orignal number /2 then that means a 1 dropped off
//Otherwise, 0 dropped off.
void PrintToBinary(float a){;
    int num_loops = sizeof(a) * 8 - 1;
    int* ptr = &a;
    int bit;

    for(int x = num_loops; x > 0; x--){
        bit = *ptr & 1<<x;
        if(bit != 0){
            printf("1");
        }
        else printf("0");
    }
}
