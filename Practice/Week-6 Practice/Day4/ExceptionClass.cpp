#include <iostream>
#include <string>

class ArrayException {
private:
    std::string _message;

public:
    ArrayException(std::string message) : _message(message) {}
    std::string getError() const {
        return _message;
    }
};

void valueAtIndex(int arr[], int size, int index) {
    try {
        if (index < 0 || index >= size) throw ArrayException("Invalid index\n");
        std::cout << arr[index] << '\n';
    }
    catch (const ArrayException& e) {
        std::cout << e.getError();
    }
}

int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(int);

    valueAtIndex(arr, size, 2);
    valueAtIndex(arr, size, -1);
    valueAtIndex(arr, size, 5);
    return 0;
}