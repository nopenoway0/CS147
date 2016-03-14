//
//  main.cpp
//  hw3
//
//  Created by Benjamin on 3/7/16.
//  Copyright © 2016 Benjamin. All rights reserved.
//

#include <iostream>
int power(int x, unsigned y);

int main(int argc, const char * argv[]) {
    std::cout << power(2, 3);
}

/* Function to calculate x raised to the power y */

int power(int x, unsigned int y) {
    if( y == 0) return 1;
    else if (y%2 == 0) return power(x, y/2) * power(x, y/2);
    else return x * power(x, y/2) * power(x, y/2);
}