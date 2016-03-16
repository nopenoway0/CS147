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
void ConvertToBinary(float a);

int main(){
    printf("Entering Program\n");
    float a = -5;
    PrintToBinary(a);
    ConvertToBinary(a);
    printf("\nExiting Program\n");
    return 1;
}
// Understanding of anding and bit shifting from :
//Bit shift to right, until number equals 0. If number /= orignal number /2 then that means a 1 dropped off
//Otherwise, 0 dropped off.
void PrintToBinary(float a){;
    int num_loops = sizeof(a) * 8 - 1;  // Sets the amount of bit shfts
    int* ptr = &a;                      // Have int point to the address of the float
    int bit;

    for(int x = num_loops; x > 0; x--){
        bit = *ptr & 1<<x;              //
        if(bit != 0){
            printf("1");
        }
        else printf("0");
    }
}

void ConvertToBinary(float a){
    unsigned char sign;
    unsigned char exponent = 0;
    unsigned int fraction;
    int tmp_bit = a;
    float remainder;
    // Set Sign of number
    if(a >= 0){
        sign = 0;
    }
    else{
        sign = 1;
        a *= -1;
    }
    //Change the float to binary
    remainder = a / 1;
    remainder = a - remainder;
    if(remainder > 0){
        a *= 10
    }
    // Convert float to decimal
    while(tmp_bit > 1){
        tmp_bit = tmp_bit >> 1;
        exponent++;
    }
    printf("\n%d|%d|", sign, exponent + 127);
}
