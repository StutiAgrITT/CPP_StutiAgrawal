#include <iostream>

class Date {
private:
    int m_date = 02;
    int m_month = 02;
    int m_year = 2025;

public: 
    int getDate() const {
        return m_date;
    }
    void setDate(int date) {
        m_date = date;
    }
    int getMonth() const {
        return m_month;
    }
    void setMonth(int month) {
        m_month = month;
    }
    int getYear() const {
        return m_year;
    }
    void setYear(int year) {
        m_year = year;
    }
};

int main() {
    Date today;
    today.setYear(2026);
    std::cout << "Year is : " << today.getYear() << '\n';
    return 0;
}
