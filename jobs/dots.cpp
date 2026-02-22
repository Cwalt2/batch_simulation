//
// Created by Christopher Walters on 2/20/26.
//

#include "dots.h"
#include "iostream"

#include <iostream>
#include <unistd.h>   // usleep()

int main() {
    std::cout << "Job: Print 50 dots\n";

    for (int i = 0; i < 50; i++) {
        std::cout << "." << std::flush;
        usleep(50000);
    }

    std::cout << "\nJob Complete.\n";
    return 0;
}