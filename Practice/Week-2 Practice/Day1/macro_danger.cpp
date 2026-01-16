#include <iostream>

#define SQR(x) x * x
#define INC(x) ++x
#define ADD 5 + 6


int main()
{
    int square = SQR(3 + 2); //should be 25, but will be 11
                             //due to pure text replacement
    std::cout << square << '\n';

    int number = 5;
    int product = INC(number) * INC(number); //should be 36
                                             //but will give undefined behaviour
    std::cout << product << '\n';

    int sum = ADD * 5;
    std::cout << sum << '\n';
}