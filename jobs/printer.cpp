//
// Created by cwalt on 2/21/26.
//

#include "printer.h"
#include <iostream>
#include <unistd.h>

int main() {
    for(int i = 0; i < 100; i++) {
        std::cout << "#" << std::flush;
        usleep(30000);
    }
    std::cout << std::endl;
    return 0;
}