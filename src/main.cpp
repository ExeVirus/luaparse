#include <iostream>

extern "C" {
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}

int main() {
    std::cout << "Hello World!";
    return 0;
}