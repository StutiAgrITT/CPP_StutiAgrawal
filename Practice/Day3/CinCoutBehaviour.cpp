#include<iostream>

int main(){
    int x;
    std::cout << "Enter a number: ";
    std::cin >> x;
    std::cout << (std::cin.tie() == &std::cout) << "\n";
    if(std::cin.fail()){
        std::cout << "Input error.\n";
    }
    std::cout << x << "\n";
    std::cout << x << std::endl;
}
