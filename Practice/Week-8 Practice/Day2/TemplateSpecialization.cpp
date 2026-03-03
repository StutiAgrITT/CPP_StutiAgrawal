#include <iostream>
#include <cstring>

template<typename T>
class Printer
{
public:
    void print(T value) const
    {
        std::cout << "Generic type: " << value << '\n';
    }
    void display() {
        std::cout << "hi\n"; // could only be called by p1
    }
};

template<>
class Printer<int>
{
public:
    void print(int value) const
    {
        std::cout << "Specialized for int: " << value << '\n';
    }
};

template<typename T>
class Printer<T*>
{
public:
    void print(T* value) const
    {
        std::cout << "Pointer type: " << *value << '\n';
    }
};

template<>
class Printer<const char*>
{
public:
    void print(const char* value) const
    {
        std::cout << "C-String specialization: " << value << '\n';
    }
};

int main()
{
    Printer<double> p1;
    p1.print(3.14);           // Uses Primary Template

    Printer<int> p2;
    p2.print(42);             // Uses Full Specialization (int)

    int x = 100;
    Printer<int*> p3;
    p3.print(&x);             // Uses Partial Specialization (T*)

    Printer<const char*> p4;
    p4.print("Hello World");  // Uses Full Specialization (const char*)
    return 0;
}