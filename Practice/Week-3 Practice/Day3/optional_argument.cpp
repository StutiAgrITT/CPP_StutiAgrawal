#include <iostream>

void printID(const int* id = nullptr) { //but function overloading is better
    if (id) {
        std::cout << "id: " << *id << '\n';
    }
    else {
        std::cout << "address: " << id << '\n';
        std::cout << "id unknown" << '\n';
    }
}

int main() {
    printID();
    int id = 814;
    printID(&id);
}