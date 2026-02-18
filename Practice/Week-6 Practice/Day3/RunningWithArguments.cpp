#include <iostream>

int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << '\n';
    }
    return 0;
}

//in gdb, type run hello world bye etc.