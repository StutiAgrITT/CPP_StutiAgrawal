#include <iostream>

class Date {
    int m_year;
    int m_month;
    int m_day;

    void print() const {
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};

int main() {
    // Date today = {2026, 2, 2}; // aggregate initialization fails
    // today.m_day = 3; // direct data access fails
    // today.print(); // private member function call fails
}