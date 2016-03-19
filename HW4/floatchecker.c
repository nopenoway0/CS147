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
    printf("\n");
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
        bin_fraction[0] = 0;
    }
    else{
        bin_fraction[0] = 1;
        a *= -1;
    }
    count++;
    //Prep for finding exponent
    tmp_bit = a;
    // Find the exponent without bias
    while(tmp_bit > 1){
        tmp_bit = tmp_bit >> 1;
        exponent++;
    }
    //Add bias
    exponent += 127;
    //Convert exponent to binary
    tmp_bit = exponent;
    count = 8;
    while(tmp_bit != 0 && count > 0){
        bin_fraction[count] = tmp_bit % 2;
        tmp_bit = tmp_bit / 2;
        count--;
    }
    count = 8;
    // TODO: can change to not use tmp_bit
    whole_number = (int) a;
    fraction = a - (float) whole_number;
    tmp_bit = whole_number;
    // Convert Whole Number into Binary, greatest -> least in bin_fraction
    while(tmp_bit != 0 && count < 32){
        bin_fraction[count] = tmp_bit % 2;
        tmp_bit = tmp_bit / 2;
        count++;
    }
    //Convert Fraction into binary
    while(fraction != 0 && count < 32){
        fraction *= 2;
        bin_fraction[count] = (char)(int)fraction;
        if(bin_fraction[count] == 1) fraction -= 1;
        count++;
    }
    // Increment count by 1 to not print the 1's place in IEEE notation
    count = 0;
    while(count < 31){
        printf("%d",bin_fraction[count]);
        count++;
    }
}
