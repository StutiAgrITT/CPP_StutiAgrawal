#include<iostream>
#include<string>

double StringToDouble(std::string number) {
    double result = 0.0;
    double multiplying_factor = 1;
    int index = 0;
    bool is_negative = false;

    while (number[index] == ' ') index++;

    if (number[index] == '-' || number[index] == '+') {
        if (number[index] == '-') {
            is_negative = true;
        }
        index++;
    }

    while (index < number.length() && (number[index] >= '0' && number[index] <= '9')) {
        result = result * 10 + (number[index] - '0');
        index++;
    }

    if (number[index] == '.') {
        index++;
        while (index < number.length() && (number[index] >= '0' && number[index] <= '9')) {
            multiplying_factor *= 0.1;
            result += ((number[index] - '0') * multiplying_factor);
            index++;
        }
    }
    return (is_negative) ? -result : result;
}

int main() {
    std::string number;
    std::cout << "Enter string: ";
    std::cin >> number;
    double number_float = StringToDouble(number);
    std::cout << "After converting to double: " << number_float << std::endl;
    return 0;
}
