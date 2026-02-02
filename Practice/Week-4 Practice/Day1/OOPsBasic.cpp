#include <iostream>

struct Date {
    int year;
    int month;
    int day;

    void print() {
        std::cout << year << "/" << month << "/" << day << '\n';
    }
};

void print(Date& date) {
    std::cout << date.year << '\n';
}

int main() {
    Date today = {2026, 2, 2};
    today.print();
    return 0;
}
