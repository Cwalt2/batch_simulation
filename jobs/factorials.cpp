//
// Created by cwalt on 2/21/26.
//

#include "factorials.h"
#include <iostream>
#include <unistd.h>

int main() {
    long long fact = 1;
    for(int i = 1; i <= 10; i++) {
        fact *= i;
        std::cout << "Factorial so far: " << fact << std::endl;
        usleep(100000);
    }
    return 0;
}