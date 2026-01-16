#include<iostream>
#include<string>

int StringToInteger(std::string number) {
    if (number[0] == '-') {
        return -1;
    }
    int number_int = 0;
    for (int index = 0; index < number.length(); index++) {
        if (number[index] > '9' || number[index] < '0') return -1;
        number_int = (number_int * 10) + (number[index] - '0');
    }
    return number_int;
}

void GetValidInteger(int& number_int) {
    std::string number_string;
    std::cout << "Enter number of rows: ";
    while (true) {
        std::cin >> number_string;
        number_int = StringToInteger(number_string);
        if(number_int != -1) return;
        std::cout << "Invalid number. Enter again: ";
    }
}

void ButterflyPattern(int num) {
    for (int row = 1; row < num; row++) {
        for (int column = 1; column <= row; column++) {
            (column % 2) != 0 ? std::cout << "1 " : std::cout << "0 "; 
        }
        for (int space = 1; space <= (2 * num - 1) - (2 * row); space++) {
            std::cout << "  ";
        }
        for (int column = 1; column <= row; column++) {
            ((num + column) % 2) == 0 ? std::cout << "1 " : std::cout << "0 "; 
        }
        std::cout << std::endl;
    }

    for (int row = 1; row < 2 * num; row++) {
        (row % 2 == 1) ? std::cout << "1 " : std::cout << "0 ";
    }
    std::cout << std::endl;

    for (int row = num - 1; row > 0; row--) {
        for (int column = 1; column <= row; column++) {
            (column % 2) != 0 ? std::cout << "1 " : std::cout << "0 ";
        }
        for (int space = 1; space <= (2 * num - 1) - (2 * row); space++) {
            std::cout << "  ";
        }
        for (int column = 1; column <= row; column++) {
            ((num + column) % 2) == 0 ? std::cout << "1 " : std::cout << "0 "; 
        }
        std::cout << std::endl;
    }
}

int main() {
    int number_of_rows;
    GetValidInteger(number_of_rows);
    ButterflyPattern(number_of_rows);
    return 0;
}
