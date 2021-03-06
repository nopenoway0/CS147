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
float stof(const char* s);

int main(int argc, char**argv){
    float  a;
    char tester[] = "test";
    if(argc == 2){
        printf("Entering Program with arguments %s|%f\n", argv[0], stof(argv[1]));
        a = stof(argv[1]);
    }
    else if(argc < 2){
            printf("Enter float to convert: ");
            scanf("%s",tester);
            a = stof(tester);
    }
    else{
        printf("Improper input format\n");
    }
    printf("Printing bits from memory: ");
    PrintToBinary(a);
    printf("\n");
    printf("Printing float to binary:  ");
    ConvertToBinary(a);
    printf("\nExiting Program\n");
    return 1;
}
// Understanding of anding and bit shifting from :
//Bit shift to right, until number equals 0. If number /= orignal number /2 then that means a 1 dropped off
//Otherwise, 0 dropped off.
void PrintToBinary(float a){;
    int num_loops = sizeof(a) * 8 - 1;  // Sets the amount of bit shfts
    int* ptr = (int*)&a;                      // Have int point to the address of the float
    int bit;

    while(num_loops > 0){
        bit = *ptr & 1<<num_loops;              // Shift 1 bit, to the x place. AND it with the current value. If the current value there is also 1, the and stays 1, if it is zero, then bit is set to zero
        if(bit != 0){                   // due to the AND. Check result in the bit field, and if 1 just print it, if 0 just print it.
            printf("1");
        }
        else printf("0");
        num_loops--;
    }
}

void ConvertToBinary(float a){
    unsigned char sign;
    unsigned char exponent = 0;
    unsigned char tmp = 0;
    short count = 0;
    short count_2 = 0;
    int tmp_bit;
    int whole_number;
    float fraction;
    char bin_fraction[32] = "0";
    char temp_array[23] = "0";
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
    //TODO: Complete zeroes
    tmp_bit = exponent;
    count = 8;
    while(count > 0){
        bin_fraction[count] = tmp_bit % 2;
        tmp_bit = tmp_bit / 2;
        count--;
    }
    // TODO: can change to not use tmp_bit
    whole_number = (int) a;
    fraction = a - whole_number;
    tmp_bit = whole_number;
    // Convert Whole Number into Binary, store into temp array
    count = 0;
    while(tmp_bit != 0 && count < 23){
        temp_array[count] = tmp_bit % 2;
        tmp_bit = tmp_bit / 2;
        count++;
    }
    count_2 = 9;
    while(count >= 0){
        bin_fraction[count_2] = temp_array[count];
        count--;
        count_2++;
    }
    //Convert Fraction into binary
    count = 0;
    while(fraction != 0 && count < 23){
        fraction *= 2;
        temp_array[count] = (int)fraction;
        if(temp_array[count] == 1) fraction -= 1;
        count++;
    }
    tmp = count;
    count = 0;
    // Swap to actual fraction array
    while(count < tmp){
        bin_fraction[count_2] = temp_array[count];
        count++;
        count_2++;
    }
    // Increment count by 1 to not print the 1's place in IEEE notation
    count = 0;
    while(count < 9){
        printf("%d",bin_fraction[count]);
        count++;
    }
    count+=2;
    while(count < 31){
    printf("%d",bin_fraction[count]);
    count++;
    }
    printf("00"); // Has 2 less precision than reading from bits
}

float stof(const char* s){  // http://stackoverflow.com/questions/4392665/converting-string-to-float-without-atof-in-c, just converted it for compatibility
    float rez = 0, fact = 1;
    int point_seen = 0;
    if (*s == '-'){
        s++;
        fact = -1;
    };
    while(*s){
        if (*s == '.'){
            point_seen = 1;
            s++;
            continue;
        };
        int d = *s - '0';
        if (d >= 0 && d <= 9){
            if (point_seen) fact /= 10.0f;
            rez = rez * 10.0f + (float)d;
        };
        s++;
    };
    return rez * fact;
};
