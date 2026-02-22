//
// Created by cwalt on 2/21/26.
//

#include "summation.h"
#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "Job: Summation 1 to 10\n";

    int sum = 0;

    for (int i = 1; i <= 10; i++) {
        sum += i;
        std::cout << "Added " << i
                  << " | Current Sum = " << sum << std::endl;

        usleep(100000); // 100ms delay
    }

    std::cout << "Final Sum = " << sum << std::endl;
    std::cout << "Job Complete.\n";

    return 0;
}