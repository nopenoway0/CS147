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
    float a = -5.25;
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
    short count = 0;
    int tmp_bit;
    int whole_number;
    float fraction;
    char bin_fraction[32] = "0";
    // Get sign
    if(a >= 0){
        sign = 0;
    }
    else{
        sign = 1;
        a *= -1;
    }
    // Get Whole number and fraction
    whole_number = (int) a;
    fraction = a - (float) whole_number;
    // Convert Whole Number into Binary, greatest -> least in bin_fraction
    
    //Convert Fraction into binary
    while(fraction != 0 && count < 32){
        fraction *= 2;
        bin_fraction[count] = (char)(int)fraction;
        if(bin_fraction[count] == 1) fraction -= 1;
        count++;
    }
    //Prep for finding exponent
    tmp_bit = a;
    // Find the exponent without bias
    while(tmp_bit > 1){
        tmp_bit = tmp_bit >> 1;
        exponent++;
    }
    printf("\n%d|%d|%d|%.4f\n", sign, exponent + 127, whole_number, fraction);
    count = 0;
    while(count < 32){
        printf("%d",bin_fraction[count]);
        count++;
    }
}
