#include <iostream>

//non modifiable lvalue reference can take both lvalue (const and non const) and rvalue
//if function with same name but parameters different like below
//for r value T&& will be preferred and for lvalue T& will be preferred
//if not present then const T& will be called
//does not give ambiguious

void print(int& num) {
    std::cout << "lvalue modifiable" << '\n';
}

void print(const int& num) {
    std::cout << "lvalue" << '\n';
}

void print(int&& num) {
    std::cout << &num << '\n';
}

int main() {
    print(10); 
    int num;
    print(num);
    const int num2 = 10;
    print(num2);
    return 0;
}
