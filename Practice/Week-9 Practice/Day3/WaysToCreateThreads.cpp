#include <iostream>
#include <thread>

void func1(int x) {
    while (x-- > 0) {
        std::cout << x << '\n';
    }
}

class Base1 {
public:
    void operator()(int x) {
        while(x-- > 0) {
            std::cout << x << '\n';
        }
    }
};

class Base2 {
public:
    void run(int x) {
        while (x-- > 0) {
            std::cout << x << '\n';
        }
    }
};

class Base3 {
public:
    static void run(int x) {
        while (x-- > 0) {
            std::cout << x << '\n';
        }
    }
};

int main() {
    //1. function pointer
    std::thread t1(func1, 5);
    t1.join();

    //2. lambda
    auto func2 = [](int x) {
        while (x-- > 0) {
            std::cout << x << '\n';
        }
    };

    std::thread t2(func2, 5);
    t2.join();
    //OR
    std::thread t3([](int x) {
        while (x-- > 0) {
            std::cout << x << '\n';
        }
    }, 5);
    t3.join();

    //3. functor
    std::thread t4(Base1(), 5);
    t4.join();

    //4. non static member function
    Base2 b;
    std::thread t5(&Base2::run, &b, 5);
    t5.join();

    //5. static member function
    std::thread t6(&Base3::run, 5);
    t6.join();
    return 0;
}
 