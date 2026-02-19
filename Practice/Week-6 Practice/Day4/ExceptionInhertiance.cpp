#include <iostream>
#include <string>
#include <exception>

class ArrayException : public std::exception{
private:
    std::string _message;

public:
    ArrayException(std::string message) : _message(message) {}
    // std::string getError() const {
    //     return _message;
    // }
    const char* what() const noexcept override {
        return _message.c_str();
    }
};

void valueAtIndex(int arr[], int size, int index) {
    try {
        if (index < 0 || index >= size) throw ArrayException("Invalid index\n");
        std::cout << arr[index] << '\n';
    }
    catch (const std::exception& e) { //now only one function for multiple classes of exception
        std::cout << e.what();
    }
}

int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(int);

    valueAtIndex(arr, size, 2);
    valueAtIndex(arr, size, 4);
    valueAtIndex(arr, size, -1);
    valueAtIndex(arr, size, 5);
    return 0;
}