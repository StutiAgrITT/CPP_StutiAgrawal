#include<iostream>
#include<string>

int StringToInteger(std::string number) {
    if (number[0] == '-') {
        return -1;
    }
    int number_int = 0;
    for (int i = 0; i < number.length(); i++) {
        if(number[i] > '9' || number[i] < '0') return -1;
        number_int = (number_int * 10) + (number[i] - '0');
    }
    return number_int;
}

int GetValidInteger() {
    std::string number_string;
    std::cout << "Enter number of rows: ";
    while (true) {
        std::cin >> number_string;
        int number_int = StringToInteger(number_string);
        if(number_int != -1) return number_int;
        std::cout << "Invalid number. Enter again: ";
    }
    return -1;
}

void ButterflyPattern(int num) {
    for (int i = 1; i < num; i++) {
        for (int j = 1; j <= i; j++) {
            (j % 2) != 0 ? std::cout << "1 " : std::cout << "0 "; 
        }
        for (int space = 1; space <= (2 * num - 1) - (2 * i); space++) {
            std::cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            ((num + j) % 2) == 0 ? std::cout << "1 " : std::cout << "0 "; 
        }
        std::cout << std::endl;
    }

    for (int i = 1; i < 2 * num; i++) {
        (i % 2 == 1) ? std::cout << "1 " : std::cout << "0 ";
    }
    std::cout << std::endl;

    for (int i = num - 1; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            (j % 2) != 0 ? std::cout << "1 " : std::cout << "0 ";
        }
        for (int space = 1; space <= (2 * num - 1) - (2 * i); space++) {
            std::cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            ((num + j) % 2) == 0 ? std::cout << "1 " : std::cout << "0 "; 
        }
        std::cout << std::endl;
    }
}

int main() {
    int number_of_rows = GetValidInteger();
    ButterflyPattern(number_of_rows);
}
