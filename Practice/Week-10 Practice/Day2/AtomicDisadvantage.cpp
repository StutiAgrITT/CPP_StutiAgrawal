#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> balance(100);
std::atomic<int> items(0);

void buy_item() {
    if (balance >= 100) {  //atomic load
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        balance -= 100; //atomic write
        items++; 
    }
}

int main() {
    std::thread t1(buy_item);
    std::thread t2(buy_item);

    t1.join();
    t2.join();

    std::cout << "Balance: " << balance << std::endl;
    std::cout << "Items: " << items << std::endl;
}

// Balance: -100
// Items: 2