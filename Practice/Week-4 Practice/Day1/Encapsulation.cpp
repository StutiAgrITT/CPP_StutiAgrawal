#include <iostream>
#include <string>

class BankAccount {
public:
    void deposit(int amount) {
        if (amount > 0)
            m_balance += amount;
    }

    void withdraw(int amount) {
        if (amount <= m_balance)
            m_balance -= amount;
    }

    void print() const {
        std::cout << "Balance: " << m_balance << '\n';
    }

private:
    int m_balance = 0;
};

int main()
{
    BankAccount account;

    account.deposit(1000);
    account.withdraw(300);
    account.print();

    // acc.m_balance = 100000; // not allowed
    //encapsulation: binding data and methods that operate on it together, while restricting direct access to data

    return 0;
}
