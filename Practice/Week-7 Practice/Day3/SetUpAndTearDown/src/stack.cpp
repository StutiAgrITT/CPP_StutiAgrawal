#include "stack.h"

void Stack::push(int value) {
    data.push_back(value);
}

void Stack::pop() {
    if (data.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    data.pop_back();
}

int Stack::top() const {
    if (data.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data.back();
}

bool Stack::isEmpty() const {
    return data.empty();
}

int Stack::size() const {
    return data.size();
}
