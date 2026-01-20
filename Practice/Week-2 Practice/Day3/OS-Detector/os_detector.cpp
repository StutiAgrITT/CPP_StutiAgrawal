#include "os_defined.h"
#include<iostream>

int getOSCode() {
    #ifdef WINDOWS_OS
        return 1;
    #elif defined(LINUX_OS)
        return 2;
    #elif defined(MAC_OS)
        return 3;
    #endif
}

int main() {
    switch (getOSCode()) {
    case 1:
        std::cout << "Windows \n";
        break;
    case 2:
        std::cout << "Linux \n";
        break;
    case 3:
        std::cout << "MacOS \n";
        break;
    default:
        std::cout << "Unknown \n";
        break;
    }
}