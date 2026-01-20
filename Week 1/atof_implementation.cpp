#include<iostream>
#include<string>

double Power(double base, int exponent) {
    double result = 1.0;
    if (exponent < 0) {
        exponent = -exponent;
        base = 1 / base;
    }
    while (exponent > 0) {
        result *= base;
        exponent--;
    }
    return result;
}

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

    if (number[index] == 'e' || number[index] == 'E') {
        index++;
        bool exp_negative = false;
        if (number[index] == '+' || number[index] == '-') {
            if (number[index] == '-')
                exp_negative = true;
            index++;
        }

        int exponent = 0;
        while (index < number.length() && (number[index] >= '0' && number[index] <= '9')) {
            exponent = exponent * 10 + (number[index] - '0');
            index++;
        }

        if (exp_negative)
            exponent = -exponent;
        result *= Power(10, exponent);


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
